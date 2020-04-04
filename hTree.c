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
hTree* createTree(hTree* left, hTree* right){
    int totalFreq = left->freq + right->freq;

    hTree* tempTree = malloc(sizeof(hTree));
    CHECKMALLOC(tempTree);

    h_node* root = createh_node(BRANCH, totalFreq, "BRANCH_ENTITY");
    root->left = left;
    root->right = right;

    tempTree->root = root;
    tempTree->freq = totalFreq;
}
