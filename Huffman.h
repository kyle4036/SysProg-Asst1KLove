#include "lList.h"

#ifndef HUFFMAN_H
#define HUFFMAN_H

  int buildCodeBook(char* fileName, int fd);
  int compress(char* fileName,char* codeBook);
  int decompress(char* fileName,char* codeBook);
  int recursive(char* pathName, char* flag,char* codeBook);

  lList* readInData(int fd);

  char* flagToString(char* flag);

#endif
