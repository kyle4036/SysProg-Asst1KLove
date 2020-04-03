#ifndef HUFFMAN_H
#define HUFFMAN_H

  int buildCodeBook(char* fileName, int fd);
  int compress(char* fileName,char* codeBook);
  int decompress(char* fileName,char* codeBook);
  int recursive(char* pathName, char* flag,char* codeBook);

  lList* readInData(int fd);

  char* flagToString(char* flag);

  #define CHECKREAD(x) do{\
    if((x) == -1){\
      printf("Cannot Read File: ");\
      switch(errno){\
        case EINVAL: printf("File unsuitable for reading.\n"); exit(1);\
        default : printf("Kernel or program error.\n"); exit(1);\
      }\
    }
  }while(0)

#endif
