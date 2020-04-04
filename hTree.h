#include "lList.h"

#ifndef HTREE_H
#define HTREE_H

    typedef struct h_node_{
        int leaf;
        int freq;
        char* token;
        struct h_node_* left;
        struct h_node_* right;
    } h_node;

    typdef struct hTree_{
        h_node* root;
        int freq;
    }hTree;

    h_node* createh_node(int leaf, int freq, char* token);
    hTree* createTree(h_node* left, h_node* right);
    void addToken(lList* data, hTree* tree);
    hTree* combineTrees(hTree* left, hTree* right);

    void freeTree(hTree* tree);

#endif
