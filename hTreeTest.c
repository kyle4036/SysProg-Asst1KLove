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

    l_node* ltemp1 = popTail(maxHeap);
    l_node* ltemp2 = popTail(maxHeap);

    printf("\nheap minus bottom 2 elements\n");
    printlList(maxHeap);

    printf("\nbottom 2 elements\n");
    printl_node(ltemp1);
    printl_node(ltemp2);

    printf("\nmaking h_nodes\n");

    h_node* htemp1 = lNode_hNode(ltemp1);
    h_node* htemp2 = lNode_hNode(ltemp2);

    printh_node(htemp1);
    printh_node(htemp2);

    printf("\nmaking 1st tree\n");

    hTree* tree = createTree(htemp1, htemp2);

    printhTree(tree);

    return 0;
}
