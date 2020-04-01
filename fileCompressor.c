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

int validFlag(char* input);

int main(int argc,char* argv[]){
  if(argv[1] == "")
  return 0;
}

int validFlag(char* input){
  if(strncmp(input, "-b")){
    return 1;
  }
  else if(strncmp(input, "-c")){
    return 1;
  }
  else if(strncmp(input, "-d")){
    return 1;
  }
  else if(strncmp(input, "-R")){
    return 2;
  }
  else{
    return 0;
  }
}
