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
#include "checkMacros.h"

//self organising linked list

lList* createList(char* token){
    lList* list = malloc(sizeof(lList));
    CHECKMALLOC(list);
    l_node* head = malloc(sizeof(l_node));
    CHECKMALLOC(head);

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
    l_node* temp = data->tail;
    while(!isempty(data) && temp->next != NULL){
        removeTail(data);
        temp = data->tail;
    }
    free(data);
}

//Note:does not currently adjust the new tail previous l_node
void removeTail(lList* data){
    l_node* temp = data->tail;
    data->tail = temp->next;
    free(temp->token);
    free(temp);
}

/*
void sortList(lList data){
  //defunct
}
*/

void addToken(lList* data,char* token){
    l_node* temp = data->head;

    int test1 = strncmp(token, temp->token, 50);
    while(strncmp(token, temp->token, 50) && temp->prev != NULL)
        temp = temp->prev;

    if(!strncmp(token, temp->token, 50)){
        if(data->head != data->tail){
            l_node* next = temp->next;

            temp->freq++;

            if(next != NULL && temp->freq > next->freq)
                swapAdj(temp,next,data);
        }
        else if(data->head == data->tail)
            temp->freq++;
    }
    else{
        addNode(data,token);
    }

}

void swapAdj(l_node* a,l_node* b,lList* data){
    l_node* tempNext;
    l_node* tempPrev;

    tempNext = a->next;
    tempPrev = a->prev;

    a->next = tempPrev;
    a->prev = tempNext;

    tempNext = b->next;
    tempPrev = b->prev;
    b->next = tempPrev;
    b->prev = tempNext;

    if(a->next == NULL)
        data->head = a;
    else if(b->next == NULL)
        data->head = b;

    if(a->prev == NULL)
        data->tail = a;
    else if(b->prev == NULL)
        data->tail = b;
}

void addNode(lList* data,char* token){
    l_node* temp = createl_node(token);
    l_node* tail = data->tail;
    temp->next = tail;
    tail->prev = temp;
    data->tail = temp;
}

int isempty(lList* data){
    if(data->head == NULL)
        return 1;
    else
        return 0;
}

//debugging

l_node* createl_node(char* token){
    l_node* node = malloc(sizeof(l_node));
    CHECKMALLOC(node);
    node->token = token;
    node->freq = 1;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
l_node* next(l_node* node){
    CHECKNEXT(node);
    printl_node(node->next);
    return node->next;
}
l_node* prev(l_node* node){
    CHECKPREV(node);
    printl_node(node->prev);
    return node->prev;
}
l_node* head(lList* list){
    printl_node(list->head);
    return list->head;
}
l_node* tail(lList* list){
    printl_node(list->tail);
    return list->tail;
}
void printl_node(l_node* node){
    printf("token - '%s'\nfreq - %d\nnext - %x\nprev - %x\n",
            node->token, node->freq, node->next, node->prev);
}
void printlList(lList* list){
    printf("head - %x\ntail - %x\n",list->head,list->tail);
}
