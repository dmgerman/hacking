#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>


#define GIG (1024L*1024*1024)
#define BLOCK 512
#define BLOCKS_PER_GIG (GIG/512)

#define MAX_LINE 1024
#define MAX_FILE_SIZE (1024*1024*10)

#define BUFFER_SIZE (BLOCK * 10)

int read_chunck(int file, char *buffer)
{
  int t;
  int i = 0;
  t  = read(file, buffer, BUFFER_SIZE);

  while (i < t) {
    if (buffer[i] == 0) 
      return i;
    i++;
  }
  return t;
}

int copy_data(int out, int input) 
{
  char c[BUFFER_SIZE];
  int limit = 0;
  int size;

  while ((size = read_chunck(input, c)) != 0) {

    write(out, c, size);

    limit += size;
    if (size != BUFFER_SIZE) {
      return 1;
    }
    if (limit > MAX_FILE_SIZE) {
      return 0;
    }
  }
  return 1;
}


void create_file(int file, unsigned long location, char *filename)
{
  off_t offset = location * BLOCK;
  int out;
  if (lseek(file, offset, SEEK_SET)!=offset) {
    fprintf(stderr, "We could not seek block [%lud][%ld]\n", location, offset);
    assert(0);
  }
  assert(strlen(filename) > 40);

  //  assert(filename[0] != '/');
  assert(filename[strlen(filename)-1] == 'f');

  if (file_exists(filename)) {
    fprintf(stderr, "file exists [%s] we don't overwrite\n", filename);    
    return;
  }

  out = open(filename, O_WRONLY|O_CREAT,0644);
  if (out == 0) {
    fprintf(stderr, "Could not create output file [%s]\n", filename);
    exit(1);
  }


  if (copy_data(out, file) == 0) {
    close(out);
    unlink(filename);
  } else {
    close(out);
  }
}




int read_char(int file)
{
  char c;
  if (read(file,&c,1) == 1) {
    return c;
  } else {
    return 0;
  }
}

      
int file_exists(char *filename) 
{
  int t;
  if( access( filename, R_OK ) != -1 ) {
    return 1;
  } else {
    return 0;
  }

}



void main(int argsc, char *args[]) {

  char line[MAX_LINE];
  char cid[100];
  char filename[1024];
  unsigned long location = 0;
  char sep1;
  char sep2;
  char deviceName[100];
  int disk;
  int count = 0;

  if (argsc != 2) {
    fprintf(stderr, "usage find <filename>\n");
    exit(1);
  }
  printf("Args for [%s [%s] sizeof long [%lu]\n", args[0],args[1], sizeof(unsigned long int));


  sprintf(deviceName, "/dev/%s", args[1]);


  if (!file_exists(deviceName)) {
    fprintf(stderr,"Device file does not exxist [%s]\n", deviceName);
    exit(1);
  }



  if ((disk = open(deviceName,  O_RDONLY)) == 0) {
    fprintf(stderr, "unable to open %s\n", args[0]);
    exit(1);
  }

  printf("Device name %s\n", deviceName);
  
  while (fgets(line, MAX_LINE, stdin)!= NULL) {
    if (count % 10000 == 0) {
      fprintf(stderr, "%d...\n", count/10000);
    }
    count++;


    
    bzero(filename, 1024);
    bzero(cid, 100);
    
    if (parse_line(line, cid, &location, filename) == 0) {
      assert(0);
    }
    printf("%s;%ld;%s\n", cid, location, filename);
    create_file(disk, location, filename);
    
  }
  
  
}



int parse_line(char *line, char *cid, unsigned long int *location, char *filename)
{
  if (strlen(line) == 0) 
    return 0;

  assert(strlen(line) > 50);

  memcpy(cid, line, 40);

  line +=41;

  *location = atol(line);
  
  while(*line != 0 && *line != ';') {
    line++;
  }
  assert(*line  == ';');
  line++;
  
  strcpy(filename, line);
  filename[strlen(filename) - 1] =0;
	 
}
