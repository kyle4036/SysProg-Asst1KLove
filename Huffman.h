#ifndef HUFFMAN_H
#define HUFFMAN_H

  char* flagToString(char* flag);

  int buildCodeBook(char* fileName);
  int compress(char* fileName,char* codeBook);
  int decompress(char* fileName,char* codeBook);
  int recursive(char* pathName, char flag);

#endif
