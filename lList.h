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

//debugging options
  l_node* createl_node(char* token);
  void printl_node(l_node*);

#endif
