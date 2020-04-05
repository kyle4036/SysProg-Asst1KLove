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

h_node* createh_node(int leaf, int freq, char* token){
    h_node* temp = malloc(sizeof(h_node));
    CHECKMALLOC(temp);

    temp->leaf = leaf;
    temp->freq = freq;
    temp->token = token;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
hTree* createTree(h_node* node){
    hTree* tempTree = malloc(sizeof(hTree));
    CHECKMALLOC(tempTree);

    tempTree->root = node;
    tempTree->freq = node->freq;

    return tempTree;
}

h_node* lNode_hNode(l_node* node){
    h_node* temp = malloc(sizeof(h_node));
    CHECKMALLOC(temp);

    temp->leaf = LEAF;
    temp->freq = node->freq;
    temp->token = node->token;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

//::NOTE: previously createTree()
hTree* combineTrees(hTree* left, hTree* right){

    int totalFreq = left->freq + right->freq;

    hTree* tempTree = malloc(sizeof(hTree));
    CHECKMALLOC(tempTree);

    h_node* root = createh_node(BRANCH, totalFreq, "BRANCH_ENTITY");
    root->left = left->root;
    root->right = right->root;

    tempTree->root = root;
    tempTree->freq = totalFreq;

    return tempTree;
}

void addTokenT(hList* data, hTree* tree){

}

void freeTree(hTree* tree){

}

hList* convertlList(lList* list){
    l_node* temp = list->head;
    hTree** dpHTree;
    while(temp->prev != NULL){
        dpHTree = convertl_node(temp);
        temp->token = dpHTree;
        CHECKPREV(temp);//damn something broke
        temp = temp->prev;
    }
    dpHTree = convertl_node(temp);
    temp->token = dpHTree;

    hList* newlist = malloc(sizeof(hList));
    newlist->head = list->head;
    newlist->tail = list->tail;

    return newlist;
}
hTree** convertl_node(l_node* node){
    h_node* htemp = lNode_hNode(node);
    hTree* ttemp = createTree(htemp);

    hTree** temp = malloc(sizeof(hTree**));
    CHECKMALLOC(temp);
    *temp = ttemp;

    return temp;
}
l_node* popTail(hList* data){
    l_node* temp = data->tail;
    data->tail = temp->next;
    l_node* tail = data->tail;
    tail->prev = NULL;
    return temp;
}

//debugging

h_node* left(h_node* node){
    CHECKLEFT(node->left);
    printh_node(node->left);
    return node->left;
}
h_node* right(h_node* node){
    CHECKRIGHT(node->right);
    printh_node(node->right);
    return node->right;
}

h_node* hroot(hTree* tree){
    printh_node(tree->root);
    return tree->root;
}

void printh_node(h_node* node){
    printf("address - %x\nleaf - %d\ntoken - '%s'\nfreq - %d\nleft - %x\nright - %x\n\n",
            node,node->leaf, node->token, node->freq, node->left, node->right);
}
void printhTree(hTree* tree){
    printf("root - %x\nfreq - %d\n\n",tree->root,tree->freq);
    h_node* root = hroot(tree);
    descendTree(root);
}
void printhList(hList* list){
    printf("head - %x\ntail - %x\n\n",list->head,list->tail);
    int i = 0;
    printf("#%d:",i++);
    l_node* temp = list->head;
    hTree** dpHTree = temp->token;
    printhTree(*dpHTree);

    while(temp->prev != NULL){
        CHECKPREV(temp);//damn something broke
        temp = temp->prev;
        dpHTree = temp->token;
        printf("#%d:",i++);
        printhTree(*dpHTree);
    }
}

h_node* descendTree(h_node* node){//recursively goes to the bottom of the tree
    if(node->leaf == BRANCH){
        if(node->left != NULL){
            printf("Left node of %x\n",node);
            descendTree(left(node));
        }
        if(node->right != NULL){
            printf("Right node of %x\n",node);
            descendTree(right(node));
        }
    }
    return node;
}
