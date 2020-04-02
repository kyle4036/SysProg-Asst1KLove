#ifndef LLIST_H
#define LLIST_H

  typedef struct l_node_{char* token;int freq;l_node_* next;l_node_* prev;} l_node;
  typedef struct lList_{l_node* head;} lList;

  lList createList(char* token);
  void sortList(lList data);
  void addToken(lList data,char* token);

#endif
