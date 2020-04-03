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
  
  //printf("echo");
  return 0;
}
