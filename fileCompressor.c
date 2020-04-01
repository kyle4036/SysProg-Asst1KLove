#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>

#include "Huffman.h"

#define NOTGOOD 0
#define GOOD 1
#define FLAGR 2

int validFlag(char* input);
int improperUsage();

int main(int argc,char* argv[]){

  //check if the command line flags are valid
  if(argc < 3){
    improperUsage();
  }
  switch(validFlag(argv[1])){
    case NOTGOOD:
      improperUsage();
      break;
    case GOOD:
      if(validFlag(argv[2])==GOOD){
        improperUsage();
      }
      break;
    case FLAGR:
      if(validFlag(argv[2])!=GOOD){
        imrpoperUsage();
      }
      break;
  }

  return 0;
}

int validFlag(char* input){
  if(strncmp(input, "-b",3)){
    return GOOD;
  }
  else if(strncmp(input, "-c",3)){
    return GOOD;
  }
  else if(strncmp(input, "-d",3)){
    return GOOD;
  }
  else if(strncmp(input, "-R",3)){
    return FLAGR;
  }
  else{
    return 0;
  }
}

int improperUsage(){
  printf("Bad command line input:\n\t./fileCompressor [-R] [-b or -c or -d] <path or file> |codebook|\n");
  exit(EXIT_FAILURE);
  return 1;
}
