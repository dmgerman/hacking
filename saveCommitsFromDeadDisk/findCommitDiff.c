#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>


#define GIG (1024L*1024*1024)
#define BLOCK 512
#define BLOCKS_PER_GIG (GIG/512)

int contains(char block[], int size) 
{
  int i;
  if (strncmp(block, "commit ", strlen("commit ")) !=0) {
    return 0;
  }
  block+=strlen("commit ") + 40;
  size -=strlen("commit ") + 40;
  if (*block != ' ')  {
    return 0;
  }

  i = 0;
  while (*block != '\n') {
    if (!(isxdigit(*block) || *block == ' ')) {
      return 0;
    }
    block++;
    i++;
    if (i >= size) {
      return 0;
    }
  }
  block++;
  if (strncmp(block, "Author:", strlen("Author:")) !=0 &&
      strncmp(block, "Merge:", strlen("Merge:")) !=0) {
    return 0;
  }
  return 1;

  // skip until next end of line
  while (i < size) {
    if (*block = '\n') {
      block++;
      break ;
    }
    *block++;
    i++;
  }
  if (strncmp(block, "AuthorDate:", strlen("AuthorDate:")) !=0) {
    return 0;
  }

  return 1;
}

void printBlock(unsigned long int location, char block[], int size)
{
  char cid[41];
  strncpy(cid, block+strlen("commit "), 40);
  cid[40] = 0;

  printf("\n++++++++++++++++++++++++++++++++++++++++\n");
  printf("Location;%s;%ld\n", cid, location);
  int nl = 0;
  while (size-- > 1) {
    putchar(*block);
    if (*block == '\n' && *(block+1) == '\n' ) {
      break;
    }
    block++;
  }
  //  printf("%s", block);
  printf("\n----------------------------------------\n");
}


void main(int argsc, char *args[]) {
  int disk;
  int readC;
  char block[512];
  unsigned long count =0;
  unsigned long readBlocks =0;


  if (argsc != 2) {
    fprintf(stderr, "usage find <filename>\n");
    exit(1);
  }
  printf("Args [%s][%s] sizeof long [%lu]\n", args[0],args[1], sizeof(unsigned long int));


  if ((disk = open(args[1],  O_RDONLY)) == 0) {
    fprintf(stderr, "unable to open %s\n", args[0]);
    exit(1);
  }
    
  count = 0;

  while ((readC = read(disk, block, 512)) > 0) {
    if (contains(block, readC) ) {
      printBlock(readBlocks, block, readC);
      count++;
    }
    readBlocks++;
    if (readBlocks % BLOCKS_PER_GIG == 0) {
      fprintf(stderr, "read %10ld gigs found [%10ld] blocks (each block [%6d] bytes) [%12ld] blocks\n", readBlocks/BLOCKS_PER_GIG, count, BLOCK, readBlocks);
    }
  }
  fprintf(stderr, "Found [%ld] matches in [%ld]\n", count, readBlocks);
  close(disk);
}
