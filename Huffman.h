#ifndef HUFFMAN_H
#define HUFFMAN_H

  int buildCodeBook(int fileBase);
  int compress(int fileBase,int codeBook);
  int decompress(int fileBase,int codeBook);
  int recursive(char* pathName, char* flag,char* codeBook);

  char* flagToString(char* flag);

#endif
