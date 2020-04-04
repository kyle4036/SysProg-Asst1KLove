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
    addToken(maxHeap,"d");
    addToken(maxHeap,"d");
    addToken(maxHeap,"d");

    printf("original heap\n");
    printlList(maxHeap);

    l_node* ltemp1 = popTail(maxHeap);
    l_node* ltemp2 = popTail(maxHeap);

    printf("heap minus bottom 2 elements\n");
    printlList(maxHeap);

    printf("bottome 2 elements\n");
    printl_node(ltemp1);
    printl_node(ltemp2);

    printf("making tree\n");
    

    return 0;
}
