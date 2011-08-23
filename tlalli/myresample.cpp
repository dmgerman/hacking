#include <stdio.h>
#include <assert.h>
#include <math.h>

#include <iostream>
#include "vigra/stdimage.hxx"
#include "vigra/stdimagefunctions.hxx"
#include "vigra/impex.hxx"
#include "vigra/resizeimage.hxx"
#include "boost/program_options.hpp"

#include "Interpolators.h"


/* What do I need?

 * A stack where the evaluation stack will be stored
 * it will contain

 ** each of the functions to be evaluated. Each function will be a geometric one:
 **  <x,y> -> <x',y'>
 ** will it be useful to  keep track of the valid values of each function?
 ** it should be fast
 ** should it do sampling itself? if so it will need to know about the actual pixel values
 ** caching should be an option
 ** From the point of view of the caller it does not matter what it is
 ** Should it be double of float or double double? Ideally a template...
 */


class transform_func {
public:
    virtual bool func(double &xOut, double &yOut, double x, double y)
    {
	return true; //virtual function that will implement the transform
    };
};


// Scale pixels by a given scale
class scale_transform_func: public transform_func {
    double xScale;
    double yScale;
public:
    scale_transform_func(double pScale) { xScale = yScale = pScale; };
    scale_transform_func(double pXScale, double pYScale) { xScale = pXScale; yScale = pYScale;};
    virtual bool func(double &xOut, double &yOut, double x, double y)
    { 
	// Simply scale
	xOut = x * xScale; yOut = y * yScale;
	// XXX We need to make sure that these values are valid
	return true;
    }
};

/*

class correct_lens_func: public transform_func {
    double a,b,c,e,f;
public:
    correct_lens_func(double pA, double pB, double pC, double pD=0, double pE=0);
    virtual bool func(double &xOut, double &yOut, double x, double y)
    { 
	// Simply scale
	xOut = x * xScale; yOut = y * yScale;
	// XXX We need to make sure that these values are valid
	return true;
    }
}
*/
class evaluation_chain {
    int last ;
    transform_func transforms[15];
public:
    evaluation_chain() { last = 0; };

    void Add_Head(transform_func func)
    {
	int i;
	for (i=last;i> 0;i--) {
	    transforms[i] = transforms[i-1];
	}
	last++;
	assert(last < 15);
	transforms[0] = func;
    }

    void Add_Tail(transform_func func)
    {
	last++;
	transforms[last] = func;
	assert(last < 15);
    }

    bool eval(double &xOut, double &yOut, double x, double y)
    {
	if (last == 0) return false;
	int i;
	int ret;
	
	for (i = 0;i<last;i++) {
	    ret = transforms[i].func(x, y, x, y);
	    // We need to handle the NANs and the return value of each function
	    printf("Doing iter %d of %d ret %d x,y %f,%f\n", i, last, ret, x, y);
	    if (!ret) return false;
	    printf("Doing iter %d of %d\n", i, last);
	}
	xOut = x;
	yOut = y;
	return true;
    }
};


using namespace vigra; 
namespace po = boost::program_options;

std::string version = "Tessel Version 0.1 Copyright 2007 Daniel M German\n\n";

static int processParameters(int argc, char **argv, int rotate, std::string &input, std::string &output) 
{
    try {
	
	po::options_description desc("Allowed options");
	desc.add_options()
	    ("help", "produce help message")
	    ("rotate", "rotate source image at locations <0,1> and <1,0> by 180 degres ")
	    ;
	
	// Hidden options, will be allowed both on command line and
	// in config file, but will not be shown to the user.
	po::options_description hidden("Hidden options");
	hidden.add_options()
	    ("input-file", po::value< std::string >(), "input file")
	    ("output-file", po::value< std::string >(), "output file")
	    ;     

	desc.add(hidden);
	po::positional_options_description p;
	p.add("input-file", 1); 
	p.add("output-file", -1);

	po::variables_map vm;
	po::store(po::command_line_parser(argc, argv).
		  options(desc).positional(p).run(), vm);
	po::notify(vm);
    
	if (vm.count("help") ) {
	    std::cerr << argv[0] <<  " [options] <input image> <output image>\n\n"
		"This program tessellates an image into a 2x2 grid. \n";
	    std::cerr << "(supported formats: " << vigra::impexListFormats() << ")" << std::endl << std::endl;
	    std::cerr << desc << "\n";
	    exit(1);
	}

	if (vm.count("rotate")) {
	    rotate = 1;
	}
	if (vm.count("input-file")) {
	    input = vm["input-file"].as< std::string >();
	} else {
	    std::cerr << "No input file specified. Use --help\n";
	    exit(1);
	}

	if (vm.count("output-file")) {
	    output = vm["output-file"].as< std::string >();
	} else {
	    std::cerr << "No output file specified. Use --help\n";
	    exit(1);
	}


    }
    catch (vigra::StdException & e) {
	std::cout << "Illegal option. Try --help\n";
	exit(1);
    }
    return(rotate);
}


template <class SrcImageIterator, class SrcAccessor,
          class DestImageIterator, class DestAccessor,
          class TRANSFORM,
          class DistImageIterator, class DistAccessor,
          class Interpolator>
void transformImageDist(vigra::triple<SrcImageIterator, SrcImageIterator, SrcAccessor> src,
                        vigra::triple<DestImageIterator, DestImageIterator, DestAccessor> dest,
                        vigra::Diff2D destUL,
                        TRANSFORM & transform,
                        vigra::triple<DistImageIterator, DistImageIterator, DistAccessor> centerDist,
                        Interpolator & interp)
//                        utils::MultiProgressDisplay & prog)
{
    vigra::Diff2D destSize = dest.second - dest.first;
    vigra::Diff2D distSize = centerDist.second - centerDist.first;

    bool calcDist=true;
    if (distSize.x == 0 && distSize.y == 0) {
        calcDist=false;
    }

    //    if (calcDist) {
    //        DEBUG_ASSERT(distSize == destSize);
    //    }
    int xstart = destUL.x;
    int xend   = destUL.x + destSize.x;
    int ystart = destUL.y;
    int yend   = destUL.y + destSize.y;

    //    prog.pushTask(utils::ProgressTask("Remapping", "", 1.0/(yend-ystart)));

    vigra::Diff2D srcSize = src.second - src.first;
    // FIXME: use d & e here.
    vigra::Diff2D srcMiddle = srcSize / 2;

//    vigra::BilinearInterpolatingAccessor<SrcAccessor, typename SrcAccessor::value_type> interpol(src.third);

    //InterpolatingAccessor(src.third, interp);
    vigra_ext::InterpolatingAccessor<SrcAccessor,
                          typename SrcAccessor::value_type,
                          Interpolator> interpol(src.third, interp);


//    vigra::BilinearInterpolatingAccessor<SrcAccessor, typename SrcAccessor::value_type> interpol(src.third);

//    vigra::BilinearInterpolatingAccessor interpol(src.third);

    // create dest y iterator
    DestImageIterator yd(dest.first);
    // create dist y iterator
    DistImageIterator ydist(centerDist.first);
    // loop over the image and transform
    for(int y=ystart; y < yend; ++y, ++yd.y, ++ydist.y)
    {
        // create x iterators
        DestImageIterator xd(yd);
        DistImageIterator xdist(ydist);
        for(int x=xstart; x < xend; ++x, ++xd.x, ++xdist.x)
        {
            double sx,sy;
            if (transform.eval(sx,sy,x,y)) {
                // make sure that the interpolator doesn't
                // access pixels outside.. Should we introduce
                // some sort of border treatment?
                if (sx < interp.size/2 -1
                    || sx > srcSize.x-interp.size/2 - 1
                    || sy < interp.size/2 - 1
                    || sy > srcSize.y-interp.size/2 - 1)
                {
                    if (calcDist) {
                        // save an invalid distance
                        *xdist = FLT_MAX;
                    }
                    // nothing..
                } else {
    //                cout << x << "," << y << " -> " << sx << "," << sy << " " << std::endl;
    
    //                nearest neighbour
    //                *xd = src.third(src.first, vigra::Diff2D((int)round(sx), (int)round(sy)));
                    // use given interpolator function.
                    *xd = interpol(src.first, sx, sy);
                    if (calcDist) {
                        double mx = sx - srcMiddle.x;
                        double my = sy - srcMiddle.y;
                        *xdist = sqrt(mx*mx + my*my);
                    }
                }
            } else {
                *xdist = FLT_MAX;
            }
        }
        if ((y-ystart)%100 == 0) {
	  //            prog.setProgress(((double)y-ystart)/(yend-ystart));
        }
    }
    //    prog.popTask();
}




int main(int argc, char ** argv)
{

    // Declare the supported options.

    int rotate = 0;

    std::string input;
    std::string output;

    std::cout << version;

    rotate = processParameters(argc, argv, rotate, input, output);

    try {
        vigra::ImageImportInfo info(input.c_str());
        vigra::ImageImportInfo infoMask("/tmp/mask.jpg");
        
	int x = info.width();
        int y = info.height();
	
        if(info.isGrayscale()) {
	    std::cout << "Grayscale images not supported\n";
        }
        else {
	    vigra::BRGBImage in(info.width(), info.height());
	    
            importImage(info, destImage(in));
            
            // create output image of appropriate size
            vigra::BRGBImage out(info.width()*2, info.height()*2);
            vigra::BRGBImage outDist(info.width()*2, info.height()*2);
            
	    evaluation_chain eval;

	    transformImageDist<BImage,BImage,evaluation_chain,ImageInterpolator>
	      (vigra::srcImageRange(in),
			       vigra::srcImageRange(out),
			       in.size(),
			       eval,
			       vigra::srcImageRange(outDist),
                               vigra_ext::interp_bilin()
			       //                               utils::MultiProgressDisplay & prog
			       );


	    /*
	    vigra::resizeImageLinearInterpolation(
						  in.upperLeft(), in.lowerRight(), in.accessor(),
						  out.upperLeft(), out.lowerRight(), out.accessor()
						  );
	    */
	    
	    vigra::ImageExportInfo outputInfo(output.c_str());
	    //  Only supported in latest vigra
	    //	    outputInfo.setICCProfile(info.getICCProfile());
	    exportImage(srcImageRange(out), outputInfo);
	    
        }

	std::cout << "Created " << output << "\n";

    }
    catch (vigra::StdException & e) {
	std::cout << e.what() << std::endl;
	return 1;
    }
    
    return 0;
}


#ifdef adfdsfendif

int main(void)
{
    double x = 1;
    double y = 1;
    scale_transform_func scaleTransform(0.5, 2);
    scale_transform_func scaleTransformRev(2, 0.5);

    evaluation_chain chain;

    printf("Begin\n");
    if (scaleTransform.func(x, y, 1.0, 1.0)) {
	printf("Good %f:%f\n", x, y);
    }

    printf("Middle\n");

    chain.Add_Tail(scaleTransform);
    chain.Add_Tail(scaleTransformRev);

    if (chain.eval(x, y, 1.0, 1.0)) {
	printf("Chain %f:%f\n", x, y);
    } else {
	printf("Error in return value\n");
    }
    


    return 0;
}


class Image {
private:
    int sizeX;
    int sizeY;
    int numberOfSamples;
    int bytesPerSample;
    int bytesPerPixel;

    boolean isCropped;
    

    ICC_Profile iccProfile;

public:
    Image(int pSizeX, int pSizeY, int pSamples, int bytesPerSample) 
    int getPixelSample(int x, int y, int sample, uint8 &pixel);
    int setPixelSample(int x, int y, int sample, unit8 &pixel);
    int getPixelSample(int x, int y, int sample, uint16 &pixel);
    int setPixelSample(int x, int y, int sample, unit16 &pixel);
};

class ImageInMemory:Image {
private:
    char *buffer;
public:
    int getPixelSample(int x, int y, int sample, int &pixel);
    int setPixelSample(int x, int y, int sample, int &pixel);
};

class ImageInMemoryTiff:ImageInMemory {
private:
    char *buffer;
    string fileName;
    boolean  isCropped;

    //tiff metadata

    float    xPixelsPerResolution;
    float    yPixelsPerResolution;
    uint16_t resolutionUnits;

    uint16_t samplesPerPixel;
    uint16_t bitsPerSample;
    int      bytesPerLine;           // Equal to the scanlinesize

    uint32_t rowsPerStrip;

    pano_TiffCompression compression;

    pano_CropInfo cropInfo;

    // other metadata
    char *copyright;
    char *datetime;
    char *imageDescription;
    char *artist;
    uint16_t imageNumber;        // saved in the page number TIFF field
    uint16_t imageTotalNumber;   // total number of images

    // These fields are computed
    int bytesPerPixel;          // This is a common value to use
    int bitsPerPixel;           // This is a common value to use



public:
    ImageInMemoryTiff(int pSizeX, int pSizeY, int pSamples, int bytesPerSample);
    ImageInMemoryTiff(char *fileName);
    Read(char *fileName);
    Save();
    SaveAs(char *fileName);
};


ImageInMemoryTiff::Read(char *fileName)
{
    //    SetImageDefaults(im);
}





Image::Image(int pSizeX, int pSizeY, int pSamples, int bytesPerSample) 
{
    sizeX = pSizeX;
    sizeY =  pSizeY;
    numberOfSamples = pSamples;
    bytesPerSample = bytesPerSample;
};


void main(void)
{
    ImageInMemoryTiff input("rip.tif");
    
    input.SaveAs("rip2.tif");


    
}







static double setAntiasing(double aaSupport) {
	 switch( TrPtr->interpolator ){
	 case _aabox:
		  aaSupport = 0.5;
		  aafilter=Box;
		  break;
	 case _aatriangle:
		  aaSupport = 1;
		  aafilter=Triangle;
		  break;
	 case _aahermite:
		  aaSupport = 1;
		  aafilter=Hermite;
		  break;
	 case _aahanning:
		  aaSupport = 1;
		  aafilter=Hanning;
		  break;
	 case _aahamming:
		  aaSupport = 1;
		  aafilter=Hamming;
		  break;
	 case _aablackman:
		  aaSupport = 1;
		  aafilter=Blackman;
		  break;
	 case _aagaussian:
		  aaSupport = 1.25;
		  aafilter=Gaussian;
		  break;
	 case _aagaussian2:
		  aaSupport = 1.0;
		  aafilter=Gaussian_2;
		  break;
	 case _aaquadratic:
		  aaSupport = 1.5;
		  aafilter=Quadratic;
		  break;
	 case _aacubic:
		  aaSupport = 2;
		  aafilter=Cubic;
		  break;
	 case _aacatrom:
		  aaSupport = 2;
		  aafilter=Catrom;
		  break;
	 case _aamitchell:
		  aaSupport = 2;
		  aafilter=Mitchell;
		  break;
	 case _aalanczos2: // antialias lanczos2
		  aaSupport = 2;
		  aafilter=Lanczos2;
		  break;
	 case _aalanczos3: // antialias lanczos3
		  aaSupport = 3;
		  aafilter=Lanczos3;
		  break;
	 case _aablackmanbessel:
		  aaSupport = 3.2383;
		  aafilter=BlackmanBessel;
		  break;
	 case _aablackmansinc:
		  aaSupport = 4;
		  aafilter=BlackmanSinc;
		  break;
	 default: 
		  PrintError( "Invalid Antialiased Interpolator selected" );
		  TrPtr->success = 0;
		  exit(1);
	 }
	 return(aaSupport);
}



void transForm( TrformStr *TrPtr, fDesc *fD,fDesc *finvD, int color, int imageNum)
{
	 register pt_int32       x, y;    // Loop through destination image
	 int         skip = 0;   // Update progress counter
	 unsigned char     *dest,*src;// Source and destination image data
	 // Message to be displayed by progress reporter
	 char*       progressMessage = "Something is wrong here";
	 char                 percent[8]; // Number displayed by Progress reporter
	 int         valid;      // Is this pixel valid? (i.e. inside source image)
	 long        coeff;      // pixel coefficient in destination image
	 long        cy;      // rownum in destimage
	 int         xc,yc;

	 double         x_d, y_d;   // Cartesian Coordinates of point ("target") in Destination image
	 double         Dx, Dy;     // Coordinates of target in Source image
	 double         orgDx, orgDy;     // Coordinates of target in Source image

	 double         max_x = (double) TrPtr->src->width; // Maximum x values in source image
	 double         max_y = (double) TrPtr->src->height; // Maximum y values in source image
	 double         min_x =  -1.0;//0.0; // Minimum x values in source image
	 double         min_y =  -1.0;//0.0; // Minimum y values in source image

	 int         mix     = TrPtr->src->width - 1; // maximum x-index src
   
	 int         mix2;
	 int         miy     = TrPtr->src->height - 1;// maximum y-index src
	 int         miy2;

	 // Variables used to convert screen coordinates to cartesian coordinates

	 double         w2    = (double) TrPtr->dest->width  / 2.0 - 0.5;  // Steve's L
	 double         h2    = (double) TrPtr->dest->height / 2.0 - 0.5;
	 double         sw2 = (double) TrPtr->src->width   / 2.0 - 0.5;
	 double         sh2 = (double) TrPtr->src->height  / 2.0 - 0.5;
   
	 int         BytesPerLine   = TrPtr->src->bytesPerLine;
	 int         FirstColorByte, SamplesPerPixel;
	 unsigned int   BytesPerPixel, BytesPerSample;

	 int         n, n2;      // How many pixels should be used for interpolation   
	 // int         lu = 0;     // Use lookup table?
	 int         wrap_x = FALSE;
	 double         theGamma;   // gamma handed to SetUpGamma()
   
	 // Some things for the floodfill algorithm
   
	 invCacheItem *invCache;

	 ffQueueItem ffItem;

	 int ptmod_last=0,ptmod_first=0;
	 int ffStackTop=0,ffIsInQueueSize;
	 ffQueueItem *ffStack;
	 int         srcWidth; 
	 int         srcHeight; 
	 unsigned int *ffIsInQueue;

	 int ccx,ccy;
	 double d,sd,ox,oy;
	 long cp;

	 // Variables for antialiasing filter
	 aaFilter aafilter;
	 double aaSupport=0;

	 //////////////////////////////////////////////////////////////////////////

	 // Selection rectangle
	 PTRect         destRect;
	 if( TrPtr->dest->selection.bottom == 0 && TrPtr->dest->selection.right == 0 ){
		  destRect.left  = 0;
		  destRect.right = TrPtr->dest->width;
		  destRect.top   = 0;
		  destRect.bottom = TrPtr->dest->height;
	 }else{
		  memcpy( &destRect, &TrPtr->dest->selection, sizeof(PTRect) );
	 }

	 srcWidth  = TrPtr->src->width; 
	 srcHeight  = TrPtr->src->height; 

	 switch( TrPtr->src->bitsPerPixel ){
	 case 128:   FirstColorByte = 4; BytesPerPixel = 16; SamplesPerPixel = 4; BytesPerSample = 4; break;
	 case  96:   FirstColorByte = 0; BytesPerPixel = 12; SamplesPerPixel = 3; BytesPerSample = 4; break;
	 case  64:   FirstColorByte = 2; BytesPerPixel = 8; SamplesPerPixel = 4; BytesPerSample = 2; break;
	 case  48:   FirstColorByte = 0; BytesPerPixel = 6; SamplesPerPixel = 3; BytesPerSample = 2; break;
	 case  32:   FirstColorByte = 1; BytesPerPixel = 4; SamplesPerPixel = 4; BytesPerSample = 1; break;
	 case  24:   FirstColorByte = 0; BytesPerPixel = 3; SamplesPerPixel = 3; BytesPerSample = 1; break;
	 case   8:   FirstColorByte = 0; BytesPerPixel = 1; SamplesPerPixel = 1; BytesPerSample = 1; break;
	 default :   PrintError("Unsupported Pixel Size: %d", TrPtr->src->bitsPerPixel);
		  TrPtr->success = 0;
		  return;
	 }
	 /* Patch for PTStitcher to support 32 bit
		 if ((TrPtr->dest->dataSize==0) && (TrPtr->dest->bitsPerPixel==128)) {
		 TrPtr->dest->bitsPerPixel=TrPtr->src->bitsPerPixel;
		 TrPtr->dest->bytesPerLine =TrPtr->dest->width * (TrPtr->dest->bitsPerPixel / 8) ; 
		 TrPtr->dest->dataSize=TrPtr->dest->height * TrPtr->dest->bytesPerLine;
		 myfree ((unsigned char**)TrPtr->dest->data);
		 TrPtr->dest->data=(unsigned char**) mymalloc ((size_t)TrPtr->dest->dataSize);
		 }
	 */
	 // Set interpolator etc:
	 n=1;
	 aaSupport = setAntiasing(aaSupport);

	 n2 = n/2 ;
	 mix2 = mix +1 - n;
	 miy2 = miy +1 - n;

	 dest = *TrPtr->dest->data;
	 src  = *TrPtr->src->data; // is locked

	 if(TrPtr->mode & _show_progress){
		  switch(color){
		  case 0:  { 
				char title[30];
#if BROKEN
				int the_Num;
				NumToString(imageNum, the_Num);
				p2cstr(the_Num);
				strcpy(title, "Converting Image #");
				strcat(title, (char *)the_Num);
#else
				sprintf(title, "Converting Image #%d", imageNum);
#endif
				strcpy(progressMessage, title); 
				//progressMessage = "Image Conversion";  
		  }
				break;
		  case 1:  switch( TrPtr->src->dataformat){
				case _RGB:  progressMessage = "Red Channel"  ; break;
				case _Lab:  progressMessage = "Lightness"     ; break;
				} break;
		  case 2:  switch( TrPtr->src->dataformat){
				case _RGB:  progressMessage = "Green Channel"; break;
				case _Lab:  progressMessage = "Color A"    ; break;
				} break; 
		  case 3:  switch( TrPtr->src->dataformat){
				case _RGB:  progressMessage = "Blue Channel"; break;
				case _Lab:  progressMessage = "Color B"   ; break;
				} break; 
               
		  case 4:  switch( TrPtr->src->dataformat)
					 {
                case _RGB:    progressMessage = "Red/Grn Channels " ; break;
                case _Lab: progressMessage = "Unsupported!!"; break;
					 } break;
                
		  case 5:  switch( TrPtr->src->dataformat)
					 {
                case _RGB:    progressMessage = "Red/Blue Channels " ; break;
                case _Lab: progressMessage = "Unsupported!!"; break;
					 } break; 
                
		  case 6:  switch( TrPtr->src->dataformat)
					 {
                case _RGB:    progressMessage = "Grn/Blue Channels " ; break;
                case _Lab: progressMessage = "Unsupported!!"; break;
					 } break; 
               
               
				//       default: progressMessage = "Something is wrong here";
		  }
		  Progress( _initProgress, progressMessage );
	 }

	 if(TrPtr->mode & _wrapX)
		  wrap_x = TRUE;

	 if( TrPtr->src->dataformat == _RGB )   // Gamma correct only RGB-images
		  theGamma = TrPtr->gamma;
	 else
		  theGamma = 1.0;
   
	 if (BytesPerSample<=2) {
		  if( SetUpGamma( theGamma, BytesPerSample) != 0 ){
				PrintError( "Could not set up lookup table for Gamma Correction" );
				TrPtr->success = 0;
				goto Trform_exit;
		  }
	 }

	 // Allocate the memory for the Stack, Floodfill markers and Cache
	 invCache=(invCacheItem *) calloc(INV_CACHE_SIZE * sizeof(invCacheItem),1);
	 ffStack=(ffQueueItem *) calloc(FF_STACK_SIZE * sizeof(ffQueueItem),1);
	 ffIsInQueueSize=(((srcWidth*srcHeight) / 32) + 1);
	 ffIsInQueue=(pt_uint32 *)  calloc(ffIsInQueueSize * sizeof(pt_uint32),1);

	 for(y=destRect.top; y<destRect.bottom; y++){
		  // Update Progress report and check for cancel every 2%.
		  skip++;
		  if( skip == (int)ceil(TrPtr->dest->height/50.0) ){
				if(TrPtr->mode & _show_progress){   
					 sprintf( percent, "%d", (int) ((y * 100)/ TrPtr->dest->height));
					 if( ! Progress( _setProgress, percent ) ){
						  TrPtr->success = 0;
						  goto Trform_exit;
					 }
				}else{
					 if( ! Progress( _idleProgress, 0) ){
						  TrPtr->success = 0;
						  goto Trform_exit;
					 }
				}
				skip = 0;
		  }
      
		  // y-coordinate in dest image relative to center      
		  y_d = (double) y - h2 ;
		  cy  = (y-destRect.top) * TrPtr->dest->bytesPerLine;   
      
		  for(x=destRect.left; x<destRect.right; x++){
				// Calculate pixel coefficient in dest image just once

				coeff = cy  + BytesPerPixel * (x-destRect.left);      

				// FS+
				{
					 // Convert destination screen coordinates to cartesian coordinates.        
					 x_d = (double) x - w2 ;
            
					 // Get source cartesian coordinates 
					 fD->func( x_d, y_d , &Dx, &Dy, fD->param);

					 orgDx=Dx;
					 orgDy=Dy;

					 Dx += sw2;
					 Dy += sh2;
            
					 // Is the pixel valid, i.e. from within source image?
					 if( (Dx >= max_x)   || (Dy >= max_y) || (Dx < min_x) || (Dy < min_y)  )
						  valid = FALSE;
					 else
						  valid = TRUE;
				}

				// Convert only valid pixels
				if( valid ){


					 // Extract integer and fractions of source screen coordinates
					 xc      =  (int)floor( Dx ) ; Dx -= (double)xc;
					 yc      =  (int)floor( Dy ) ; Dy -= (double)yc;
            
					 // if alpha channel marks valid portions, set valid 
					 if(TrPtr->mode & _honor_valid)
						  switch( FirstColorByte ){
						  case 1:{
								int xn = xc, yn = yc;
								if( xn < 0 ) xn = 0; //  -1  crashes Windows
								if( yn < 0 ) yn = 0; //  -1  crashes Windows
								if( src[ yn * BytesPerLine + BytesPerPixel * xn] == 0 )
									 valid = FALSE;
						  }
								break;
						  case 2:{
								int xn = xc, yn = yc;
								if( xn < 0 ) xn = 0; //  -1  crashes Windows
								if( yn < 0 ) yn = 0; //  -1  crashes Windows
								if( *((USHORT*)(src + yn * BytesPerLine + BytesPerPixel * xn)) == 0 )
									 valid = FALSE;
						  }
								break;
						  case 4:{
								int xn = xc, yn = yc;
								if( xn < 0 ) xn = 0; //  -1  crashes Windows
								if( yn < 0 ) yn = 0; //  -1  crashes Windows
								if( *((float*)(src + yn * BytesPerLine + BytesPerPixel * xn)) == 0 )
									 valid = FALSE;
						  }
								break;
						  default: break;
						  }
				}
         
				if( valid ){   

					 int warpover=(TrPtr->src->format==_equirectangular);

					 int bx,by,ex,ey;                                
					 double DstX,DstY,rDstX,rDstY;
					 double weight,w,rd,gd,bd;
					 pt_uint32 *ptui;

					 bx=floor(orgDx + sw2);
					 ex=ceil(orgDx + sw2);
					 by=floor(orgDy + sh2);  
					 ey=ceil(orgDy + sh2);
            
					 // Clear only the modified floodfill markers
					 ptui=&ffIsInQueue[ptmod_first];
					 if (ptmod_last>=ptmod_first) memset(ptui,0,(ptmod_last-ptmod_first+1)*sizeof(ptui[0]));
					 ptmod_first=ffIsInQueueSize;
					 ptmod_last=0;

					 // Add the 4 surrounding pixels as seeds for the floodfile algorithm
					 ffStackAdd(bx,by);
					 ffStackAdd(ex,by);
					 ffStackAdd(bx,ey);
					 ffStackAdd(ex,ey);

					 weight=0;
					 rd=0;
					 gd=0;
					 bd=0;
					 while (ffStackTop) {
						  // Get the next position from the Stack
						  ffItem=ffStack[--ffStackTop];
						  ccx=ffItem.x;
						  ccy=ffItem.y;
               
						  // Calculate the hash, +1 to avoid the 0,0 problem
						  cp=(1 + ccx + ccy*INV_CACHE_FY) % INV_CACHE_SIZE; 
						  if ((invCache[cp].dstX==ccx) && (invCache[cp].dstY==ccy)) { 
								// Cachehit
								DstX=invCache[cp].srcX;
								DstY=invCache[cp].srcY;
						  } else {
								// Calculate the invers function to get the exact position in the source image
								finvD->func((ccx-sw2), (ccy-sh2) , &DstX, &DstY, finvD->param);
								invCache[cp].dstX=ccx;
								invCache[cp].dstY=ccy;
								invCache[cp].srcX=DstX;
								invCache[cp].srcY=DstY;
						  }
               
						  // distance from the exact of the source pixel to the 
						  // position in the destination image
						  rDstX=x_d-DstX;
						  rDstY=y_d-DstY;

						  // distance from the exact position in the source image
						  ox=(ccx-sw2) - orgDx;
						  oy=(ccy-sh2) - orgDy;
               
						  if (warpover) {
								if (ox > max_x/2.0) ox-=max_x;
								if (ox < -max_x/2.0) ox+=max_x;
								if (rDstX > max_x/2.0) rDstX-=max_x;
								if (rDstX < -max_x/2.0) rDstX+=max_x;
						  }

						  sd=sqrt(rDstX*rDstX + rDstY*rDstY);
						  d=sqrt(ox*ox + oy*oy);

						  if (sd>d) { // we are upscaling!
								rDstX*=d/sd;
								rDstY*=d/sd;
						  }

						  // Calculate the weight for the current pixel of the source image
						  if ((fabs(rDstX)<aaSupport) && (fabs(rDstY)<aaSupport)) {
								w=aafilter(rDstX,aaSupport) * aafilter(rDstY,aaSupport);
						  } else {
								w=0;
						  }
						  if (w!=0) {
								// Sum the total weight
								weight +=w;       
								// Add the weighted color values
								switch(BytesPerSample) {
								case 1:  {  
									 register unsigned char *ric=src + FirstColorByte + ccx*BytesPerPixel + ccy*BytesPerLine; // Pointer for 1 byte per pixel
									 rd += glu.DeGamma[(int)*ric] * w;
									 ric++;
									 gd += glu.DeGamma[(int)*ric] * w;               
									 ric++;
									 bd += glu.DeGamma[(int)*ric] * w;   
								}
									 break;
								case 2:  {
									 register unsigned short *ris=(unsigned short *)((char *)src + FirstColorByte + ccx*BytesPerPixel + ccy*BytesPerLine); 
									 rd += glu.DeGamma[(int)*ris] * w;
									 ris++;
									 gd += glu.DeGamma[(int)*ris] * w;               
									 ris++; 
									 bd += glu.DeGamma[(int)*ris] * w;   
								}
									 break;
								case 4:{
									 register float *rif=(float *)((char *)src + FirstColorByte + ccx*BytesPerPixel + ccy*BytesPerLine); 
									 rd += *rif * w;
									 rif++;
									 gd += *rif * w;               
									 rif++;
									 bd += *rif * w;   
								}
									 break;
								}
								// Add the surround pixels as seeds to the stack
								ffStackAdd(ccx-1,ccy-1);
								ffStackAdd(ccx-1,ccy  );
								ffStackAdd(ccx-1,ccy+1);

								ffStackAdd(ccx+1,ccy-1);
								ffStackAdd(ccx+1,ccy  );
								ffStackAdd(ccx+1,ccy+1);
                  
								ffStackAdd(ccx,ccy-1);
								ffStackAdd(ccx,ccy+1);
						  }
					 }

					 if (weight==0) weight=1; // Just in case....
					 switch(BytesPerSample) {
					 case 1:  {
						  register unsigned char *aadst=&(dest[ coeff ]);
						  if (FirstColorByte) {
								*aadst++=UCHAR_MAX;      // Set alpha channel
						  }
						  if ((color==0) || (color==1) || (color==4) || (color==5)) {
								*aadst  =   gamma_char( rd/weight );
						  }
						  aadst++;
						  if ((color==0) || (color==2) || (color==4) || (color==6)) {
								*aadst  =   gamma_char( gd/weight );
						  }
						  aadst++;
						  if ((color==0) || (color==3) || (color==5) || (color==6)) {
								*aadst  =   gamma_char( bd/weight );
						  }
					 }
						  break;
					 case 2:  {
						  register unsigned short *aadst=(void *)&(dest[ coeff ]);
						  if (FirstColorByte) {
								*aadst++=USHRT_MAX;      // Set alpha channel
						  }
						  if ((color==0) || (color==1) || (color==4) || (color==5)) {
								*aadst  =   gamma_short( rd/weight );
						  }
						  aadst++;
						  if ((color==0) || (color==2) || (color==4) || (color==6)) {
								*aadst  =   gamma_short( gd/weight );
						  }
						  aadst++;
						  if ((color==0) || (color==3) || (color==5) || (color==6)) {
								*aadst  =   gamma_short( bd/weight );
						  }
					 }
						  break;
					 case 4:  {
						  float *aadst=((float*)(dest + coeff));
						  if (FirstColorByte) {
								*aadst++=1.0; // Set alpha channel
						  }
						  if ((color==0) || (color==1) || (color==4) || (color==5)) {
								*aadst  = gamma_float(rd/weight);
						  }
						  aadst++;
						  if ((color==0) || (color==2) || (color==4) || (color==6)) {
								*aadst  = gamma_float(gd/weight);
						  }
						  aadst++;
						  if ((color==0) || (color==3) || (color==5) || (color==6)) {
								*aadst  = gamma_float(bd/weight);
						  }
					 }
						  break;
					 }
				}// END: if is a valid pixel
				else
                {  
                    // not valid (source pixel x,y not inside source image, etc.)
                    
                    //Fix: Correct would use incorrect correction values if different factors were set for each color channel
                    //PT.Fix.mt.Begin: March.2004
                    //was:
                    //memset( &(dest[ coeff ]), 0 ,BytesPerPixel );
                    //now:
                    if(color==0) // RGB same time
								{
									 memset( &(dest[ coeff ]), 0 ,BytesPerPixel ); //mt_test
									 //PT.Dev.mt.End: March.2004( &(dest[ coeff ]), 0 ,BytesPerPixel ); 
								}
                    else
								{
									 char*   ptr = &(dest[ coeff ]);
                    
									 if(color < 4) // R or G or B
										  {
												ptr += FirstColorByte + (color - 1)*BytesPerSample;
												memset( ptr, 0 , BytesPerSample ); //mt_test
										  }   
									 else
										  if(color==4) // R+G
												{
													 ptr += FirstColorByte;
													 memset( ptr, 0 , 2*BytesPerSample ); //rjp
												}
										  else
												if(color==5) // R+B
													 {
														  ptr += FirstColorByte;
														  memset( ptr, 0 , BytesPerSample ); 
														  ptr += 2*BytesPerSample;
														  memset( ptr, 0 , BytesPerSample ); //rjp
													 }
												else // (color==6) G+B
													 {
														  ptr += FirstColorByte + BytesPerSample;
														  memset( ptr, 0 , 2*BytesPerSample ); //rjp
													 }
								}
                    
                }// END: else Not a valid pixel
		  }
	 }
	 TrPtr->success = 1;


 Trform_exit:
	 if( glu.DeGamma ) free( glu.DeGamma );    glu.DeGamma    = NULL;
	 if( glu.Gamma )      free( glu.Gamma );   glu.Gamma   = NULL;

	 if(invCache != NULL) free(invCache);
	 if(ffStack != NULL) free(ffStack);
	 if(ffIsInQueue != NULL) free(ffIsInQueue);

	 return;
}

#endif
