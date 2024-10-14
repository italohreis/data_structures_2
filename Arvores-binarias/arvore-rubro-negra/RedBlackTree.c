#include "RedBlackTree.h"
#include <stdlib.h>
#include <stdio.h>

struct _node {
    int key;
    char color;
    struct _node *left;
    struct _node *right;
    struct _node *p;
};

struct _tree {
    Node *root;
    Node *nil;
};

Node *createNode(Tree *T, int key) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->key = key;
    node->color = 'R';
    node->left = T->nil;
    node->right = T->nil;
    node->p = T->nil;
    return node;
}

Tree *createTree() {
    Tree *T = (Tree *) malloc(sizeof(Tree));
    T->nil = createNode(T,-1);
    T->nil->left = T->nil;
    T->nil->right = T->nil;
    T->nil->p = T->nil;
    T->nil->color = 'B';
    T->root = T->nil;
    return T;
}


void RB_insert(Tree *T, int key) {
    Node *y = (T)->nil;
    Node *x = (T)->root;
    Node *z = createNode(T,key);

    while (x != (T)->nil) {
        y = x;
        if (z->key < x->key) 
            x = x->left;
        else 
            x = x->right;      
    }
    z->p = y;
    if (y == (T)->nil) {
        (T)->root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
    z->left = (T)->nil;
    z->right = (T)->nil;
    z->color = 'R';
    RB_insert_fixup((T), z);
}

void RB_insert_fixup(Tree *t, Node *z) {
    while (z->p->color == 'R') {
        if (z->p == z->p->p->left) {
            Node *y = z->p->p->right;
            if (y->color == 'R') {
                z->p->color = 'B';
                y->color = 'B';
                z->p->p->color = 'R';
                z = z->p->p;
            } else {
                if (z == z->p->right) {
                    z = z->p;
                    left_rotate((t), z);
                }
                z->p->color = 'B';
                z->p->p->color = 'R';
                right_rotate((t), z->p->p);
            }
        } else {
            Node *y = z->p->p->left;
            if (y->color == 'R') {
                z->p->color = 'B';
                y->color = 'B';
                z->p->p->color = 'R';
                z = z->p->p;
            } else {
                if (z == z->p->left) {
                    z = z->p;
                    right_rotate((t), z);
                }
                z->p->color = 'B';
                z->p->p->color = 'R';
                left_rotate((t), z->p->p);
            }
        }
    }
    (t)->root->color = 'B';
}

void left_rotate(Tree *T, Node *z) {
    Node *y = z->right;
    z->right = y->left;
    if (y->left != (T)->nil) {
        y->left->p = z;
    }
    y->p = z->p;
    if (z->p == (T)->nil) {
        (T)->root = y;
    } else if (z == z->p->left) {
        z->p->left = y;
    } else {
        z->p->right = y;
    }
    y->left = z;
    z->p = y;
}

void right_rotate(Tree *T, Node *z) {
    Node *y = z->left;
    z->left = y->right;
    if (y->right != (T)->nil) {
        y->right->p = z;
    }
    y->p = z->p;
    if (z->p == (T)->nil) {
        (T)->root = y;
    } else if (z == z->p->right) {
        z->p->right = y;
    } else {
        z->p->left = y;
    }
    y->right = z;
    z->p = y;
}

void pre_order(Tree *T, Node *node) {
    if (node != T->nil) {
        printf("%d(%c), ", node->key, node->color);
        pre_order(T, node->left);
        pre_order(T, node->right);
    }
}

Node *get_root(Tree *T) {
    return T->root;
}