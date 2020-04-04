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

    printlList(maxHeap);

    l_node* ltemp = popTail(maxHeap);

    printlList(maxHeap);

    printl_node(ltemp);
    return 0;
}
