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

lList* createList(char* token){
  lList* list = malloc(sizeof(lList));
  l_node* head = malloc(sizeof(l_node));

  head->token = token;
  head->freq = 1;
  head->next = NULL;
  head->prev = NULL;

  list->head = head;
  list->tail = head;

  return list;
}

void sortList(lList data){
  //defunct
}


void addToken(lList data,char* token){

}
