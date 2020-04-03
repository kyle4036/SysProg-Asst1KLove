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
#include "lList.h"

//char* flagToString(char* flag);

int buildCodeBook(char* fileName, int fd){
  printf("Building codebook for %s!\n", fileName);
  lList* data = createList("a");
  return 0;
}

lList* readInData(int fd){
  int count = 1;
  char charTemp;
  while(count != 1){
    count = read(fd,&charTemp,sizeof(char));

    if(count == -1){
      printf("Cannot Read File: ");
      switch(errno){
        case EINVAL: printf("File unsuitable for reading.\n"); exit(1);
        default : printf("Kernel or program error.\n"); exit(1);
      }
    }


  }
}

int compress(char* fileName,char* codeBook){
  printf("Compressing %s using %s codebook!\n",fileName, codeBook);
  return 0;
}

int decompress(char* fileName,char* codeBook){
  printf("Decompressing %s using %s codebook!\n",fileName, codeBook);
  return 0;
}

int recursive(char* pathName, char* flag, char* codeBook){
  char* action = flagToString(flag);
  printf("Recursively %s directory %s!\n",action,pathName);
  free(action);
  return 0;
}

char* flagToString(char* flag){
  int length;

  char bString[] = "building codebook for";
  char cString[] = "compressing";
  char dString[] = "decompressing";

  if(strncmp(flag, "-b",3)){
    length = strnlen(bString,30);
    char* action = malloc(sizeof(char) * length);
    strncpy(action,bString,length);
    return action;
  }
  else if(strncmp(flag, "-c",3)){
    length = strnlen(cString,30);
    char* action = malloc(sizeof(char) * length);
    strncpy(action,cString,length);
    return action;
  }
  else if(strncmp(flag, "-d",3)){
    length = strnlen(dString,30);
    char* action = malloc(sizeof(char) * length);
    strncpy(action,dString,length);
    return action;
  }
  else{
    printf("Error In flagToString():\n\t Bad flag.\n");
    exit(EXIT_FAILURE);
    //return (char*)"a";
  }
}
