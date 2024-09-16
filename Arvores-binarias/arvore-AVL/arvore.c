#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct _node {
    int key;
    int balance;
    struct _node *left;
    struct _node *right;
};

struct _tree {
    struct _node *root;
};

Tree *tree_create() {
    Tree *tree = (Tree *) malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

Node *node_create(int x) {
    Node *node = (Node *) malloc(sizeof(Node));
    if (node != NULL) {
        node->key = x;
        node->balance = 0;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

void node_insert(Node **pt, int x, bool *h) {
    if (*pt == NULL) {
        *pt = node_create(x);
        *h = true;
        return;
    }

    if (x < (*pt)->key) {
        node_insert(&(*pt)->left, x, h);

        if (*h == true) {
            switch ((*pt)->balance) {
                case 1:
                    (*pt)->balance = 0;
                    *h = false;
                    break;
                case 0:
                    (*pt)->balance = -1;
                    break;
                case -1:
                    case1(pt, h);  // rebalanceamento à esquerda
                    break;
            }
        }
    } else if (x > (*pt)->key) {  // nao deixa duplicação de chave
        node_insert(&(*pt)->right, x, h);

        if (*h == true) {
            switch ((*pt)->balance) {
                case -1:
                    (*pt)->balance = 0;
                    *h = false;
                    break;
                case 0:
                    (*pt)->balance = 1;
                    break;
                case 1:
                    case2(pt, h);  // rebalanceamento à direita
                    break;
            }
        }
    }
}

// Rebalanceamento à esquerda
void case1(Node **pt, bool *h) {
    Node *ptu = (*pt)->left;

    if (ptu->balance == -1) {
        (*pt)->left = ptu->right;
        ptu->right = (*pt);
        (*pt)->balance = 0;
        (*pt) = ptu;
    } else {
        Node *ptv = ptu->right;
        ptu->right = ptv->left;
        ptv->left = ptu;
        (*pt)->left = ptv->right;
        ptv->right = (*pt);

        if (ptv->balance == -1) {
            (*pt)->balance = 1;
        } else {
            (*pt)->balance = 0;
        }
        if (ptv->balance == 1) {
            ptu->balance = -1;
        } else {
            ptu->balance = 0;
        }
        (*pt) = ptv;
    }

    (*pt)->balance = 0;
    *h = false;
}

// rebalanceamento à direita
void case2(Node **pt, bool *h) {
    Node *ptu = (*pt)->right;

    if (ptu->balance == 1) {
        (*pt)->right = ptu->left;
        ptu->left = (*pt);
        (*pt)->balance = 0;
        (*pt) = ptu;
    } else {
        Node *ptv = ptu->left;
        ptu->left = ptv->right;
        ptv->right = ptu;
        (*pt)->right = ptv->left;
        ptv->left = (*pt);

        if (ptv->balance == 1) {
            (*pt)->balance = -1;
        } else {
            (*pt)->balance = 0;
        }
        if (ptv->balance == -1) {
            ptu->balance = 1;
        } else {
            ptu->balance = 0;
        }
        (*pt) = ptv;
    }

    (*pt)->balance = 0;
    *h = false;
}

Node *get_root(Tree *tree) {
    return tree->root;
}

void tree_insert(Tree *tree, int x) {
    bool h = false;
    node_insert(&tree->root, x, &h);
}

void pre_order(Node *pt) {
    if (pt != NULL) {
        printf("%d, ", pt->key);
        pre_order(pt->left);
        pre_order(pt->right);
    }
}
