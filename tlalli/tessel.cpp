/*
 *  tessel.cpp
 *
 *  A program to tessellate image. 
 * 
 *  It cuatruplicates an image, and optionally rotates two of the
 *  copies 180 degrees.
 * 
 *  Copyright Daniel M. German
 *  
 *  Feb 2007
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This software is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public
 *  License along with this software; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *
 *  Author: Daniel M German dmg at uvic doooot ca
 * 
 */


#include <iostream>

#include "vigra/stdimage.hxx"
#include "vigra/stdimagefunctions.hxx"
#include "vigra/impex.hxx"
#include "boost/program_options.hpp"

/*
#include "boost/program_options/cmdline.hpp"
#include "boost/program_options/options_description.hpp"
#include "boost/program_options/variables_map.hpp"
#include "boost/program_options/parsers.hpp"
*/
using namespace vigra; 
namespace po = boost::program_options;

std::string version = "Tessel Version 0.1 Copyright 2007 Daniel M German\n\n";

static int processParameters(int argc, char **argv, int rotate, string &input, string &output) 
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
            
	    
	    // Create the two regions that are copies of the original image
	    for (int i=0;i<2;i++) {
		//	      for (int j=0;j<2;j++) {
		copyImage(srcIterRange(in.upperLeft(),
				       in.lowerRight()),
			  destIter(out.upperLeft() + vigra::Diff2D(x*i,y*i))
			  );
	    }

	    if (rotate) {
		
		// Create the other two regions, rotated  180 degrees
		// create image iterator that points to upper left corner 
		// of source image
		vigra::BRGBImage::Iterator sy = in.upperLeft();
		
		// create image iterator that points past the lower right corner of
		// source image (similarly to the past-the-end iterator in the STL)
		vigra::BRGBImage::Iterator send = in.lowerRight();
		
		// create image iterator that points to bottom left corner of resulting 
		// region. dy and dy2 will move up
		vigra::BRGBImage::Iterator dy = out.upperLeft() + vigra::Diff2D(0,2*y);
		vigra::BRGBImage::Iterator dy2 = out.upperLeft() + vigra::Diff2D(x,y);
		
		dy.y --;
		dy2.y --;
		// iterate down the first column of source image
		for(; sy.y != send.y; ++sy.y, --dy.y, --dy2.y) {
		    // create image iterator that points to the first 
		    // pixel of the current row of the source image
		    vigra::BRGBImage::Iterator sx = sy;
		    
		    // create image iterator that points to the last
		    // pixel of the current row of the destination image
		    vigra::BRGBImage::Iterator dx = dy + vigra::Diff2D(x-1,0);
		    vigra::BRGBImage::Iterator dx2 = dy2 + vigra::Diff2D(x-1,0);
		    
		    // Copy the row to the rows of the two areas 
		    for(; sx.x != send.x; ++sx.x, --dx.x, --dx2.x) {
			*dx = *sx;
			*dx2 = *sx;
		    }
		}
	    } else {
		// don't rotate, just place the images as in the original

		copyImage(srcIterRange(in.upperLeft(),
				       in.lowerRight()),
			  destIter(out.upperLeft() + vigra::Diff2D(x,0))
			  );

		copyImage(srcIterRange(in.upperLeft(),
				       in.lowerRight()),
			  destIter(out.upperLeft() + vigra::Diff2D(0,y))
			  );

	    }
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


