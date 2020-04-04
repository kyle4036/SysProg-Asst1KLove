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
hTree* createTree(h_node* left, h_node* right){
    int totalFreq = left->freq + right->freq;

    hTree* tempTree = malloc(sizeof(hTree));
    CHECKMALLOC(tempTree);

    h_node* root = createh_node(BRANCH, totalFreq, "BRANCH_ENTITY");
    root->left = left;
    root->right = right;

    tempTree->root = root;
    tempTree->freq = totalFreq;

    return tempTree;
}

void addTokenT(lList* data, hTree* tree){

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

h_node* descendTree(h_node* node){//recursively goes to the bottom of the tree
    if(node->left != NULL){
        printf("Left node of %x\n",node);
        descend(left(node));
    }
    if(node->right != NULL)
        printf("Right node of %x\n",node);
        descend(right(node));
    return node;
}
