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

int buildCodeBook(char* fileName){
  printf("Building codebook for %s!\n", fileName);
  return 0;
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
  return 0;
}

char* flagToString(char* flag){
  int length;

  char[] bString = "building codebook for";
  char[] cString = "compressing";
  char[] dString = "decompressing";

  if(strncmp(input, "-b",3)){
    length = strnlen(bString,30);
    char* action = malloc(sizeof(char) * length);
    strncpy(action,bString,length);
    return action;
  }
  else if(strncmp(input, "-c",3)){
    length = strnlen(cString,30);
    char* action = malloc(sizeof(char) * length);
    strncpy(action,cString,length);
    return action;
  }
  else if(strncmp(input, "-d",3)){
    length = strnlen(dString,30);
    char* action = malloc(sizeof(char) * length);
    strncpy(action,dString,length);
    return action;
  }
  else{
    printf("Error In flagToString():\n\t Bad flag input.\n");
    exit(EXIT_FAILURE);
    return 0;
  }
}
