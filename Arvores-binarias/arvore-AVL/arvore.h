#ifndef ARVORE_H
#define ARVORE_H
#include <stdbool.h>

typedef struct _tree Tree;
typedef struct _node Node;

Tree *tree_create();

Node *node_create(int x);

void node_insert(Node **pt, int x, bool *h);

void case1(Node **pt, bool *h);

void case2(Node **pt, bool *h);

Node *get_root(Tree *tree);

void tree_insert(Tree *tree, int x);

void pre_order(Node *pt);


#endif