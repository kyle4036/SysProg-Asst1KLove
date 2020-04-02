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
int branch(char* flag, char* fileName, char* codeBook);

int improperUsage();
int improperName();

int main(int argc,char* argv[]){

  char* lastArg = argv[argc-1];

  //check if the command line flags are valid
  if(argc < 3 || argc > 5){
    improperUsage();
  }

  //*****NOTE:: the final argument in recursive
  //            may be a codeBook or a PathName,
  //  need to add a check somewhere here
  switch(validFlag(argv[1])){
    case NOTGOOD:
      improperUsage();
      break;
    case GOOD:
      if(validFlag(argv[2])==GOOD){
        improperUsage();
      }
      if(validFlag(argv[2])==FLAGR){
        recursive(argv[3], argv[1], lastArg);
      }
      branch(argv[1],argv[2], lastArg);
      break;
    case FLAGR:
      if(validFlag(argv[2])!=GOOD){
        improperUsage();
      }
      recursive(argv[3],argv[2],lastArg);
      break;
  }

  return 0;
}

int validFlag(char* input){
  if(!strncmp(input, "-b",3)){
    return GOOD;
  }
  else if(!strncmp(input, "-c",3)){
    return GOOD;
  }
  else if(!strncmp(input, "-d",3)){
    return GOOD;
  }
  else if(!strncmp(input, "-R",3)){
    return FLAGR;
  }
  else{
    return 0;
  }
}

//split off into the different functions based on the input
int branch(char* flag, char* fileName, char* codeBook){

  //*****NOTE:: need to add checks for fileName and codeBook in compress and decompress

  if(!strncmp(flag, "-b",3)){
    int fd = open(fileName, O_RDONLY);
    if(fd == -1){
      improperName();
    }
    close(fd);
    buildCodeBook(fileName);
  }
  else if(!strncmp(flag, "-c",3)){
    compress(fileName, codeBook);
  }
  else if(!strncmp(flag, "-d",3)){
    decompress(fileName, codeBook);
  }
  return 0;
}

int improperUsage(){
  printf("Bad command line input:\n\t./fileCompressor [-R] [-b or -c or -d] <path or file> |codebook|\n");
  exit(EXIT_FAILURE);
  return 1;
}
int improperName(char* name){
  printf("Bad command line input:\n\t%s not a proper file or directory\n",name);
  exit(EXIT_FAILURE);
  return 1;
}
