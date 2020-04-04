#include "lList.h"

#ifndef HTREE_H
#define HTREE_H

    #define LEAF 1
    #define BRANCH 0

    typedef struct h_node_{
        int leaf;
        int freq;
        char* token;
        struct h_node_* left;
        struct h_node_* right;
    } h_node;

    typedef struct hTree_{
        h_node* root;
        int freq;
    }hTree;

    h_node* createh_node(int leaf, int freq, char* token);
    h_node* lNode_hNode(l_node* node);
    hTree* createTree(h_node* node);
    void addTokenT(lList* data, hTree* tree);
    hTree* combineTrees(hTree* left, hTree* right);

    void freeTree(hTree* tree);

//debugging tools

    void printh_node(h_node* node);
    void printhTree(hTree* tree);
    h_node* hroot(hTree* tree);
    h_node* left(h_node* node);
    h_node* right(h_node* node);
    h_node* descendTree(h_node* node);

    #define CHECKLEFT(x) do{\
        if((x) == NULL){\
            printf("Couldn't left() on line %d! value null...",(__LINE__)-1);\
            return NULL;\
        }\
    }while(0)\

    #define CHECKRIGHT(x) do{\
        if((x) == NULL){\
            printf("Couldn't right() on line %d! value null...",(__LINE__)-1);\
            return NULL;\
        }\
    }while(0)\

#endif
