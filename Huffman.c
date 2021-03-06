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
#include "hTree.h"
#include "lList.h"
#include "checkMacros.h"

//char* flagToString(char* flag);

int buildCodeBook(char* fileName, int fd){
    printf("\nBuilding codebook for %s!\n", fileName);

    lList* maxHeap = readInData(fd);
    close(fd);

    printf("\nAll Data from File organized\n");
    printlList(maxHeap);

    printf("\nTree of Data\n");
    hTree* tree = buildTree(maxHeap);
    printhTree(tree);

    printf("\nWriting data to HuffmanCodebook\n");
    writeData(tree);


    return 0;
}

lList* readInData(int fd){
    int count;
    char charTemp;

    char* spacePntr = malloc(sizeof(char)*5);
    CHECKMALLOC(spacePntr);
    *spacePntr = "_";

    char** stringTemp;
    int stringLen = 2;
    stringTemp = malloc(sizeof(char*));
    CHECKMALLOC(stringTemp);

    lList* maxHeap;

    count = read(fd,&charTemp,sizeof(char));
    CHECKREAD(count);

    maxHeap = createList(spacePntr);

    *stringTemp = malloc(sizeof(char*) * stringLen);
    CHECKMALLOC(*stringTemp);
    strncat(*stringTemp,&charTemp,1);

    while(count != 0){
        count = read(fd,&charTemp,sizeof(char));
        CHECKREAD(count);

        if(charTemp == ' '){
            addToken(maxHeap, spacePntr);
            addToken(maxHeap,*stringTemp);

            //free(*stringTemp);
            stringTemp = malloc(sizeof(char*));
            CHECKMALLOC(stringTemp);

            stringLen = 2;

            *stringTemp = malloc(sizeof(char*) * stringLen);
            CHECKMALLOC(*stringTemp);

            count = read(fd,&charTemp,sizeof(char));
            CHECKREAD(count);
            strncat(*stringTemp,&charTemp,1);
        }
        else{
            stringLen++;
            catString(stringTemp,stringLen,charTemp);
        }
    }
    return maxHeap;
}

void catString(char** stringO,int stringLen,char charTemp){
    char* stringTemp = malloc(sizeof(char)* stringLen);
    CHECKMALLOC(stringTemp);
    strncpy(stringTemp, *stringO,stringLen);
    strncat(stringTemp, &charTemp,1);
    free(*stringO);
    *stringO = stringTemp;
}

hTree* buildTree(lList* maxHeap){
    hList* hHeap = convertlList(maxHeap);
    hTree* temptree;

    l_node* node1;
    l_node* node2;

    while(!ishTreeComplete(hHeap)){
        node1 = popTail(hHeap);
        node2 = popTail(hHeap);

        if(node1->freq < node2->freq)
            temptree = combineTrees(node1->token, node2->token);
        else
            temptree = combineTrees(node2->token, node1->token);

        free(node1);
        free(node2);

        if(hListIsEmpty(hHeap))
            return temptree;
        else
            addTreeToken(hHeap,temptree);
    }


    return temptree;
}

void writeData(hTree* tree){
    int fd = open("HuffmanCodebook",O_WRONLY | O_CREAT,S_IRWXU|S_IRWXG);

    if(fd == -1){
        if(errno == EEXIST){
            printf("\nCodebook already exists\n");
            exit(1);
        }
        printf("\ncouldn't create HuffmanCodebook: sorry\n");
        exit(1);
    }

    //int count;
    int sLen = 3;
    char* tempString = malloc(sizeof(char*) * sLen);
    *tempString = "\0";
    CHECKMALLOC(tempString);

    h_node* tempNode = tree->root;

    writeTree(tempNode, fd,tempString, sLen);

}
void writeTree(h_node* currentNode,int fd,char* stringO,int sLen){
    sLen++;
    char* newString = malloc(sizeof(char*)*sLen);
    strcpy(newString,stringO);

    if(currentNode->leaf != LEAF){
        if(currentNode->right != NULL){
            strncat(newString,"0",1);
            writeTree(currentNode->right, fd,newString,sLen);
        }
        if(currentNode->left != NULL){
            strncat(newString,"1",1);
            writeTree(currentNode->left, fd,newString,sLen);
        }
    }
    else{
        int lineLength = strnlen(currentNode->token,50) + strnlen(stringO,50) + 5;
        char* line = malloc(sizeof(char*) * lineLength);
        CHECKMALLOC(line);

        strcpy(line,stringO);
        strcat(line,"\t");
        strcat(line,currentNode->token);
        strcat(line,"\n");

        int count = write(fd,line,lineLength);
        while(count < lineLength){
            count += write(fd,line+count,lineLength);
        }
    }
    free(newString);
}



int compress(char* fileName,char* codeBook,int fn,int cb){
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
