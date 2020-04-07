#include "lList.h"
#include "hTree.h"

#ifndef HUFFMAN_H
#define HUFFMAN_H

    int buildCodeBook(char* fileName, int fd);
    int compress(char* fileName,char* codeBook);
    int decompress(char* fileName,char* codeBook);
    int recursive(char* pathName, char* flag,char* codeBook);

    lList* readInData(int fd);
    void catString(char** stringO,int stringLen,char charTemp);
    hTree* buildTree(lList* minHeap);
    void writeData(hTree* tree);
    void writeTree(h_node* currentNode,int fd,char** stringO,int sLen);

    char* flagToString(char* flag);

#endif
