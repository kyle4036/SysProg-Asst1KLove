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

#include "hTree.h"
#include "lList.h"
#include "checkMacros.h"


int main(int argc, char* argv){
    lList* maxHeap = createList("a");
    addToken(maxHeap,"b");
    addToken(maxHeap,"c");
    addToken(maxHeap,"c");
    addToken(maxHeap,"d");
    addToken(maxHeap,"d");
    addToken(maxHeap,"d");

    printf("\noriginal heap\n");
    printlList(maxHeap);

    printf("\nconverted heap\n");
    hList* hHeap = convertlList(maxHeap);
    printhList(hHeap);

    l_node* ltemp1 = popTail(hHeap);
    l_node* ltemp2 = popTail(hHeap);

    hTree** tree1 = ltemp1->token;
    hTree** tree2 = ltemp2->token;

    //free(ltemp1);
    //free(ltemp2);

    hTree* tree3 = combineTrees(*tree1, *tree2);

    free(tree1);
    free(tree2);
    free(ltemp1);
    free(ltemp2);

    printf("\nnew tree from bottom 2 trees\n");
    printhTree(tree3);

    return 0;
}
