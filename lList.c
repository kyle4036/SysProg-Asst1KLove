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

  if(list == NULL || head == NULL){
    printf("Error generating space in createList()\n");
    exit(EXIT_FAILURE);
  }

  head->token = token;
  head->freq = 1;
  head->next = NULL;
  head->prev = NULL;

  list->head = head;
  list->tail = head;

  return list;
}

void freeList(lList* data){

}

void removeTail(lList* data){

}

/*
void sortList(lList data){
  //defunct
}
*/

void addToken(lList data,char* token){

}

//debugging

l_node* createl_node(char* token){
  l_node* node = malloc(sizeof(l_node));
  node->token = token;
  node->freq = 1;
  node->next = NULL;
  node->prev = NULL;
  return node;
}
