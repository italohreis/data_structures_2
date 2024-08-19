#ifndef ARVORE_H
#define ARVORE_H

typedef struct _arvore {
    struct _Node *raiz;
}Arvore;

typedef struct _Node {
    struct _Node *left, *right;
    int info;
}Node;

#endif


