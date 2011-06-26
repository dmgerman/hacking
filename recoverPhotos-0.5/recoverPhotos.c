/*
   $Id$

   Recovers photos from camera media. See README for details.


 * Copyright (C) 2004 Daniel M. German
 *
 * Author: Daniel M. German dmg _at_ turingmachine _dot_ org
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

//#define _LARGEFILE64_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include <getopt.h>

#define FALSE 0
#define TRUE  1


#define USAGE "recoverPhotos Version " VERSION "\n\
\
Recovers photos from damaged media. \
\
Author: Daniel M. German dmgerman at uvic dot ca\n\
\n\
Usage: %s [OPTION] filename ...\n\
\n\
 Options\n\
  -v --verbose           increase verbosity\n\
  -o --overwrite         overwrite output file\n\
  -n --dryrun            do not actually create the files\n\
  -d --outputDir <dir>   directory where output files should\n\
                         be placed\n\
  -p --prefix <string>   Use <string> as the prefix for recovered images\n\
     --canonADD          Canon \"Add Decision Data\" (use with care)\n\
\n\
         \n\
By default the output files are created in the current directory. \n\
\n\
"


#define DEBUG

#include <unistd.h>

#ifdef DEBUG
#define DEBUG_ENTRY(a) (!debug || fprintf(stderr, "Entering function: %s [%s:%d]\n", a, __FILE__, __LINE__))
#define DEBUG_EXIT(a) (!debug || fprintf(stderr, "Exiting function: %s [%s:%d]\n", a, __FILE__, __LINE__))
#define DEBUG_1(a) (debug?fprintf(stderr, a):0)
#define DEBUG_2(a,b) (debug? fprintf(stderr, a,b):0)
#define DEBUG_3(a,b,c) (debug? fprintf(stderr, a,b,c):0)
#define DEBUG_4(a,b,c,d) (debug? fprintf(stderr, a,b,c,d):0)
#define DEBUG_5(a,b,c,d,e) (debug? fprintf(stderr, a,b,c,d,e):0)
#define DEBUG_6(a,b,c,d,e,f) (debug? fprintf(stderr, a,b,c,d,e,f):0)
#define DEBUG_7(a,b,c,d,e,f,g) (debug? fprintf(stderr, a,b,c,d,e,f,g):0)
#define DEBUG_8(a,b,c,d,e,f,g,h) (debug? fprintf(stderr, a,b,c,d,e,f,g,h):0)
#define DEBUG_9(a,b,c,d,e,f,g,h,i) (debug? fprintf(stderr, a,b,c,d,e,f,g,h,i):0)
#define DEBUG_10(a,b,c,d,e,f,g,h,i,j) (debug? fprintf(stderr, a,b,c,d,e,f,g,h,i,j):0)
#else
#define DEBUG_1(a) 			
#define DEBUG_2(a,b) 			
#define DEBUG_3(a,b,c) 			
#define DEBUG_4(a,b,c,d) 		
#define DEBUG_5(a,b,c,d,e) 		
#define DEBUG_6(a,b,c,d,e,f) 		
#define DEBUG_7(a,b,c,d,e,f,g) 		
#define DEBUG_8(a,b,c,d,e,f,g,h) 	
#define DEBUG_9(a,b,c,d,e,f,g,h,i) 	
#define DEBUG_10(a,b,c,d,e,f,g,h,i,j) 	
#endif


/* GLobal variables */

int totalImages = 0;
int totalWrittenImages = 0;

int debug=0;
int dryRun = 0;
int verbose = 0;
int overWrite = 0;
int createDir = 0;
char *dirName = NULL;
char *prefix = "recovered_";
int canonADD = 0;

#define BUFFER_SIZE (50*1024*1024)
unsigned char buffer[BUFFER_SIZE];

/* The Canon Add Decision Data Custom Function appends 160 bytes at the end of the file */
#define CANON_ADD_BYTES 160


enum byte_order_enum { big_endian, little_endian, unchanged};
typedef enum byte_order_enum byte_order;


void Write_File(char *buffer, size_t size, char *extension) 
{
  static int fileCount = 0;
  char fileName[256];
  char temp[256];
  FILE *file;
  int len;

  assert(extension != NULL);
  assert(buffer != NULL);
  assert(size > 100);
  
  len = strlen(extension);

  /* Create the file name */

  if (prefix != NULL) {
    len += strlen(prefix);
  }
  if (dirName != NULL) {
    len += strlen(dirName);
  }
  if (len  > 250) {
    fprintf(stderr, "Overflow\n");
    exit(1);
  }

  sprintf(temp, "%s%04d.%s", prefix, fileCount++, extension);
  
  if (dirName != NULL && strlen(dirName) > 0) {
    strcpy(fileName, dirName);
    if (dirName[strlen(dirName)-1] != '/') {
      strcat(fileName, "/");
    }
    strcat(fileName, temp);
  } else {
    strcpy(fileName, temp);
  }
  
  
  if (dryRun) 
    return;

  if (!overWrite &&
      (file = fopen(fileName, "r")) != NULL) {
    fprintf(stderr, "     output file %s exists, I do not overwrite\n", fileName);
    fclose(file);
   return;
  }

  printf("    writing file %s \n", fileName);
  
  if ((file = fopen(fileName, "w+")) == NULL) {
    fprintf(stderr, "Unable to create file %s\n", fileName);
    perror("");
    exit(1);
  }
  
  fprintf(stderr, "to write %d\n", size);
  if (fwrite(buffer, 1, size, file) != size) {
    fprintf(stderr, "Unable to write to file %s\n", fileName);
    perror("");
    exit(1);
  }
  fclose(file);
  totalWrittenImages++;
}



byte_order Host_Endianism(void)
{
   int i = 1;
   char *p = (char*)&i;
   if (*p == 1) 
      return little_endian;
   else
      return big_endian;

}

typedef union {
   unsigned char  bytes[2];
   u_int16_t value;
} int2;

typedef union {
   unsigned char  bytes[4];
   u_int32_t       value;
} int4;


int Convert_Number_4_bytes(void* value, byte_order endianism)
{
  int4 *temp;
  temp = (int4*)value;

  if (endianism == little_endian || endianism == unchanged) {
    return temp->bytes[0] + (temp->bytes[1] << 8) + (temp->bytes[2] << 16) + (temp->bytes[3] << 24);
  } else {
    return (temp->bytes[0] << 24) + (temp->bytes[1] << 16) + (temp->bytes[2] << 8) + temp->bytes[0];
  }
}


int Convert_Number_2_bytes(void *value, byte_order endianism)
{
  int2 *temp;
  temp = (int2*)value;

   if (endianism == little_endian || endianism == unchanged) {
      return temp->bytes[0] + (temp->bytes[1] << 8);
   } else {
      return (temp->bytes[0] << 8) + temp->bytes[1];
   }
}

/* We'll check if the first FD stack looks good, that will be good enough */
int Canon_CR2_Process_Directory(char *data, int offsetIFD)
{
  unsigned int offset;
  int lastOffset = -1;

  DEBUG_ENTRY("canon_cr2_process_directory");

  if (offsetIFD < 0 || 
      offsetIFD > 10*1024*1024) {
    return -1;
  }
  /* The directory is a link list, after an array of records, the next 4 byptes point to the offset of the next directory.

  All offsets are absolution within the file (in CRWs the offsets are relative ).

  */

  while (offsetIFD != 0 && offsetIFD != 0xFFFF) {
    int countEntries=0;
    int i;
    /* Read directory, we start by reading number of entries in the directory */

    offset = offsetIFD;

    if (offset >= BUFFER_SIZE)  return -1;
    countEntries = Convert_Number_2_bytes(&data[offset], little_endian);

    offset +=2;

    DEBUG_2("Number of entries: %d\n", countEntries);


    for (i=0;i<countEntries;i++) {
      /* read each entry */

      int recordId;
      int format;
      int count;
      int offsetData;

      /* read record type */
      if (offset >= BUFFER_SIZE)  return -1;
      recordId = Convert_Number_2_bytes(&data[offset], little_endian);
      offset +=2;

      if (offset >= BUFFER_SIZE)  return -1;
      format = Convert_Number_2_bytes(&data[offset], little_endian);
      offset +=2;

      if (offset >= BUFFER_SIZE)  return -1;
      count = Convert_Number_4_bytes(&data[offset], little_endian);
      offset +=4;

      if (offset >= BUFFER_SIZE)  return -1;
      offsetData = Convert_Number_4_bytes(&data[offset], little_endian);
      offset +=4;
      //      offset +=10;


      DEBUG_5("Record ID 0x%0x %d %d %d\n", recordId, format, count, offsetData);

      switch (recordId) {
      case 0x111:
	/* we will make some assumptions. 
	   THe last Strip is the good one */
	lastOffset = offsetData;
	break;
      case 0x117:
	lastOffset += offsetData;
	break;
      }

    }
    /* The next 4 bytes are the offset of next directory, if zero we are done
       
     */
    if (offset >= BUFFER_SIZE)  return -1;
    offsetIFD = Convert_Number_4_bytes(&data[offset], little_endian);
    offset +=4;


    DEBUG_3("Value of NEXT offsetIFD: %d 0x%x\n", offsetIFD, offsetIFD);

  }

  if (canonADD) {
    lastOffset += CANON_ADD_BYTES;
  }

  DEBUG_2("Going to return %d\n", lastOffset);

  DEBUG_EXIT("canon_cr2_process_directory");


  return lastOffset;


}



int Recover_CR2(int file)
{
  int readBytes = 0;
  int offsetIFD = 0;
  int end = -1;

  /* Let us make it easy, let us try to read 10 Megs */
  int fileOffset = lseek(file, 0, SEEK_CUR);

  readBytes = read(file, buffer, BUFFER_SIZE);
  
  if (readBytes < 5 * 1024 * 1024) {
    DEBUG_2("It just looks too small %d\n", readBytes);
  }

  /* Now we have a buffer with enough data to see if it a CR2, so let us try to check if it is indeed a photo */
  
  /* THe offset of the first IFD is the next 4 bytes */

  offsetIFD = Convert_Number_4_bytes(&buffer[4], little_endian);

  DEBUG_2("OffsetIFD %d \n", offsetIFD);

  end = Canon_CR2_Process_Directory(buffer,  offsetIFD);

  DEBUG_2("Found something that looks like a CR2 of length %d\n", end);
  
  if (end > 0) {
    assert(end > 3 * 1024 * 1024);

    printf("Found CR2 image of size %d at offset %d\n", end, fileOffset);
    totalImages++;

    Write_File(buffer, end, "CR2");
  
    if (end % 512 != 0) {
      /* sector boundary, we have to jump to the eat the rest of the sector */
      end += 512 - end % 512;
    }
  }
  
  return end;

}


int JPEG_Process(unsigned char buffer[], int offsetIFD, int imageLen) 
{
  /* A JPEG is composed of records of the following format:
     
  0xFF+Marker Number(1 byte)+Data size(2 bytes)+Data(n bytes)

  and the last marker is  0xFFD9 (end of image)

  */
  int length = -1; /* THe real length of the JPEG found */

  unsigned char recordId = buffer[offsetIFD+1];

  DEBUG_3("JEPG entry '[%x][%x]\n", buffer[offsetIFD], buffer[offsetIFD+1]);

  
  while (buffer[offsetIFD] == 0xFF) {
    int size;

    /* It looks like a record */

    recordId = buffer[offsetIFD+1];
    DEBUG_2("JPEG entry '[%x]\n", recordId);

    /* Now find the length of this record, it is the next 2 bytes */
    
    if (recordId == 0xd8) {
      /* This record has no data */
      size = 0;
    } else {
      size = Convert_Number_2_bytes(&buffer[offsetIFD + 2], big_endian);
    }
    
    DEBUG_5("JPEG  entry size '[%d][%x] Offset %d %x\n", size, size, offsetIFD, offsetIFD);


    /* Nexf offset: */
    offsetIFD += size + 2;
    
    if (recordId == 0xda) {
      /* This is the SOS record, data follows, so far so good */
      break;
    } 

  }
  if (recordId != 0xda) {
    DEBUG_1("No SOS found\n");
    return -1;
  }

  /* Now search for EOI */
  
  int i =offsetIFD; 
  while (i+1 < imageLen) {
    if (buffer[i] == 0xFF &&
	buffer[i+1] == 0xD9) {
      break;
    }
    i++;
  }

  if (buffer[i+1] != 0xD9) {
    DEBUG_1("False alarm\n");
    return -1;
  } else {

    length = i + 2;

    if (canonADD) {
      length += CANON_ADD_BYTES;
    }

    DEBUG_1("Good\n");
    return length;
  }


}


int Recover_JPEG(int file)
{
  int readBytes = 0;
  int end = -1;

  /* Let us make it easy, let us try to read 10 Megs, or whatever is left */
  int fileOffset = lseek(file, 0, SEEK_CUR);
  readBytes = read(file, buffer, BUFFER_SIZE);
    
  /* Now we have a buffer with enough data to see if it a JPEG, so let us try to check if it is indeed a photo */
  
  /* The third byte should be a  0xFF */
  
  if (buffer[2] != 0xFF) {
    DEBUG_2("THis does not look like a JPEG [%x]\n", buffer[2]);
    return -1;
  }

  end = JPEG_Process(buffer,  2, readBytes);
  
  if (end > 0) {
    printf("Found JPEG image of size %d at offset %d\n", end, fileOffset);
    totalImages++;

    if (verbose) {

    }
    assert(end < 5 * 1024 * 1024);
    Write_File(buffer, end, "JPG");

    if (end % 512 != 0) {
      /* sector boundary, we have to jump to the eat the rest of the sector */
      end += 512 - end % 512;
    }
  } else {
    DEBUG_2("False alarm. It is not a JPEG %d\n", end);
  }
  
  return end;

}


int Scan_For_Headers(int file)
{
  
  /* how about start scanning the beginning of each sector to see what we find */
  char sector[512];
  int i;
  int count =0;
  off_t offset=0;
  off_t newOffset =0;
  
  while (read(file, sector, 512) == 512) {
    int j;
    if (memcmp(sector, "\x49\x49\x2a\x00", 4) == 0) {
	count++;
	DEBUG_4("This is looks like a CR2 %d:%d Count %d\n", i, j,count);
	/* This looks like a CR2 */

	/* Go back to the beginning of the sector */
	
	offset = lseek(file, -512, SEEK_CUR);
	
	if ((newOffset = Recover_CR2(file)) > 0) {
	  assert(newOffset % 512 == 0);
	  lseek(file, offset + newOffset, SEEK_SET);
	} else {
	  /* Not found, reset pointer */
	  lseek(file, offset+512, SEEK_SET);
	}
    } else if (memcmp(sector, "\xff\xd8\xff\xe1", 4) == 0) {

      /* This looks like a JPEG */
      /*( first byte is 0xff and second 0xd8 */
      DEBUG_1("This might look like a JPEG\n");

      offset = lseek(file, -512, SEEK_CUR);
      
      if ((newOffset = Recover_JPEG(file)) > 0) {
	  assert(newOffset % 512 == 0);

	  lseek(file, offset + newOffset, SEEK_SET);
	
      } else {
	  lseek(file, offset+512, SEEK_SET);
      }
    }
    i++;
  }
  return i;
}


int main (int argc, char *argv[])
{
  int file;


  int keepParsingOptions = 1;
  int c;

  while (keepParsingOptions) {
    static struct option longOptions[] = {
      /* These options set a flag. */
      {"verbose",    no_argument,    &verbose,   1},
      {"overwrite",  no_argument,    &overWrite, 1},
      {"dryrun",     no_argument,    &dryRun,    1},
      {"canonADD",   no_argument,    &canonADD,  1},
      /* These options don't set a flag.
	 We distinguish them by their indices. */
      {"outputDir",  required_argument, 0, 'd'},
      {"prefix", required_argument, 0, 'p'},
      
      {0, 0, 0, 0}
    };
    /* getopt_long stores the option index here. */
    int optionIndex = 0;
    
    c = getopt_long (argc, argv, "novpd",
		     longOptions, &optionIndex);
    
    
    if (c == -1) {
      /* Detect the end of the options. */
      keepParsingOptions = 0;
    } else {
      switch (c) {
      case 'n':
	dryRun = 1;
	break;
      case 'o':
	overWrite = 1;
	break;
      case 'v':
	verbose = 1;
	break;
      case 'd':
	dirName = optarg;
	break;
      case 'p':
	prefix = optarg;
	break;
      case '?':
	fprintf(stderr,  USAGE, argv[0]);
	exit(1);
      }
    }
  }

  printf("OPtions: dryRun %d overwrite %d verbose %d \n",
	 dryRun, overWrite, verbose);

  if (optind != argc - 1) {
    fprintf(stderr,  USAGE, argv[0]);
  } 


  //  file = open(argv[optind],  O_RDONLY | O_LARGEFILE);
  file = open(argv[optind],  O_RDONLY );
  if (file == -1) {
    fprintf(stderr, "Unable to open input file ");
    perror(argv[optind]);
    exit(1);
  }

assert(file != 0);
  
  Scan_For_Headers(file);
    
  close(file);
    
  printf("Total number of images found: %d\n", totalImages);

  printf("Total number of images written: %d\n", totalWrittenImages);
  return 0;
}


