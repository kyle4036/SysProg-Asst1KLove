#ifndef LLIST_H
#define LLIST_H

    typedef struct l_node_{
        char* token;
        int freq;
        struct l_node_* next;
        struct l_node_* prev;
    } l_node;

    typedef struct lList_{struct l_node* head;struct l_node* tail;} lList;

    lList* createList(char* token);
    void freeList(lList* data);
    void removeTail(lList* data);

    //void sortList(lList data);
    void addToken(lList* data,char* token);
    void addNode(lList* data,char* token);
    int isempty(lList* data);
    void swapAdj(l_node* a,l_node* b,lList* data);

//debugging options
    l_node* createl_node(char* token);
    void printl_node(l_node* node);
    void printlList(lList* list);
    l_node* next(l_node* node);
    l_node* prev(l_node* node);
    l_node* head(lList* list);
    l_node* tail(lList* list);

    #define CHECKPREV(x) do{\
        if((x) == NULL){\
            printf("Couldn't prev() on line %d! value null...",(__LINE__)-1);\
            return NULL;\
        }\
    }while(0)\

    #define CHECKNEXT(x) do{\
        if((x) == NULL){\
            printf("Couldn't next() on line %d! value null...",(__LINE__)-1);\
            return NULL;\
        }\
    }while(0)\

#endif
