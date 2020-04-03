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

#include "lList.h"

int main(int argc, char* argv){
  lList* list = createList("a");
  addToken(list,"b");
  addToken(list,"b");

  printlList(list);
  printl_node(list->tail);

  //printf("echo");
  return 0;
}
