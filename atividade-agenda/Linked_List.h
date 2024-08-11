#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _list List;
typedef struct _node Node;

List* createList();

Node *createNode(char *name, char *tel, unsigned int ID);

void list_insert(char *name, char *tel, unsigned int ID, List *list);

void verificar_agenda(List *list, char *str);

void list_print(List *list);

unsigned int list_size(List *list);

#endif