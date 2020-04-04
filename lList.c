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
    //free(temp->token);    //might need for next datatype
    free(temp);
}

l_node* popTail(lList* data){
    l_node* temp = data->tail;
    data->tail = temp->next;
    l_node* tail = data->tail;
    tail->prev = NULL;
    return temp;
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
        temp->freq++;
        l_node* next = temp->next;

        //figure out if the data should be swapped
        if(data->head != data->tail && next != NULL && temp->freq > next->freq){

            while(next->next != NULL && temp->freq > next->freq)
                next = next->next;//to bubble up to the correct freq val

            l_node* htemp = data->head;
            if(temp->freq > htemp->freq)//if next is at the head value
                swap(temp,next,data);
            else
                swap(temp,next->prev,data);
        }
        /*
        if(temp == data->head || data->head == data->tail){
            temp->freq++;
        }
        else if(data->head != data->tail){
            l_node* next = temp->next;

            temp->freq++;

            if(next != NULL && temp->freq > next->freq)
                swap(temp,next,data);
        }
        */
    }
    else{
        addNode(data,token);
    }

}

void swap(l_node* a,l_node* b,lList* data){
    char* tempToken;
    int tempFreq;

    tempToken = a->token;
    tempFreq = a->freq;

    a->token = b->token;
    a->freq = b->freq;

    b->token = tempToken;
    b->freq = tempFreq;
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
    CHECKNEXT(node->next);
    printl_node(node->next);
    return node->next;
}
l_node* prev(l_node* node){
    CHECKPREV(node->prev);
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
    printf("address - %x\ntoken - '%s'\nfreq - %d\nnext - %x\nprev - %x\n\n",
            node, node->token, node->freq, node->next, node->prev);
}
void printlList(lList* list){
    printf("head - %x\ntail - %x\n\n",list->head,list->tail);
    int i = 0;
    printf("#%d:",i++);
    l_node* temp = head(list);
    while(temp->prev != NULL){
        CHECKPREV(temp);//damn something broke
        printf("#%d:",i++);
        temp = prev(temp);
    }
}
