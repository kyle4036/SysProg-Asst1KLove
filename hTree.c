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

int ishTreeComplete(hList* data){
    l_node* temp = data->head;
    return temp->prev == NULL;
}
int hListIsEmpty(hList* data){
    return data->head == NULL;
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

l_node* hTree_lNode(hTree* tree){
    l_node* temp = createl_node(tree);
    temp->freq = tree->freq;

    return temp;
}

//::NOTE: previously createTree()
//After combining trees the previous trees are freed
hTree* combineTrees(hTree* left, hTree* right){

    int totalFreq = left->freq + right->freq;

    hTree* tempTree = malloc(sizeof(hTree));
    CHECKMALLOC(tempTree);

    h_node* root = createh_node(BRANCH, totalFreq, "BRANCH_ENTITY");
    root->left = left->root;
    root->right = right->root;

    tempTree->root = root;
    tempTree->freq = totalFreq;

    free(left);
    free(right);
    //*left = NULL;
    //*right = NULL;

    return tempTree;
}

void addTreeToken(hList* data, hTree* tree){
    int freq = tree->freq;

    l_node* newNode = hTree_lNode(tree);
    l_node* prev = data->head;
    l_node* next;

    //incase there is only 1 element in the hList
    if(data->head == data->tail){
        if(prev->freq > freq){
            newNode->next = prev;
            prev->prev = newNode;
            data->tail = newNode;
        }
        else{
            newNode->prev = prev;
            prev->next = newNode;
            data->head = newNode;
        }
        return;
    }

    while(prev->freq > freq && prev->prev != NULL){
        prev = prev->prev;
    }
    next = prev->next;

    if(next == NULL){
        newNode->prev = prev;
        prev->next = newNode;
        data->head = newNode;
    }
    else if(prev->prev == NULL && prev->freq > freq){
        newNode->next = prev;
        prev->prev = newNode;
        data->tail = newNode;
    }
    else{
        newNode->next = next;
        newNode->prev = prev;
        next->prev = newNode;
        prev->next = newNode;
    }
}

//Don't know if I need to free the tokens yet
void freeTree(hTree* tree){
    destroyh_nodes(tree->root);
    free(tree);
}
void destroyh_nodes(h_node* current){
    if(current->left != NULL)
        destroyh_nodes(current->left);
    if(current->right != NULL)
        destroyh_nodes(current->right);

    free(current);
}

hList* convertlList(lList* list){
    l_node* temp = list->head;
    hTree* tree;
    while(temp->prev != NULL){
        tree = convertl_node(temp);
        temp->token = tree;
        CHECKPREV(temp);//damn something broke
        temp = temp->prev;
    }
    tree = convertl_node(temp);
    temp->token = tree;

    hList* newlist = malloc(sizeof(hList));
    newlist->head = list->head;
    newlist->tail = list->tail;

    return newlist;
}
hTree* convertl_node(l_node* node){
    h_node* htemp = lNode_hNode(node);
    hTree* temp = createTree(htemp);

    //hTree** temp = malloc(sizeof(hTree**));
    //CHECKMALLOC(temp);
    //*temp = ttemp;

    return temp;
}
l_node* popTail(hList* data){
    l_node* temp = data->tail;
    data->tail = temp->next;

    if(data->tail == NULL){
        data->head = NULL;
        return temp;
    }


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
    hTree* tree = temp->token;
    printhTree(tree);

    while(temp->prev != NULL){
        CHECKPREV(temp);//damn something broke
        temp = temp->prev;
        tree = temp->token;
        printf("#%d:",i++);
        printhTree(tree);
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
