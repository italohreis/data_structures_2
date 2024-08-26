#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>

struct _node {
    int key;
    struct _node *left;
    struct _node *right;
    struct _node *p;
};

struct _tree {
    Node *root;
};

Tree* create_tree() {
    Tree *tree = (Tree*) malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

Node* create_node(int key) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->p = NULL;
    return node;
}

void insert(Tree *tree, int value) {
    Node *node = create_node(value);
    
    Node *y = NULL;
    Node *x = tree->root;

    while (x != NULL) {
        y = x;
        if (node->key < x->key) 
            x = x->left;
        else 
            x = x->right;
    }
    node->p = y;
    if (y == NULL) {
        tree->root = node;
    } else if (node->key < y->key) {
        y->left = node;
    } else {
        y->right = node;
    }
}

void print_tree_preorder(Node *node) {
    if (node != NULL) {
        printf("%d, ", node->key);  
        print_tree_preorder(node->left);
        print_tree_preorder(node->right);
    }
}

void print_tree_inorder(Node *node) {
    if (node != NULL) {
        print_tree_inorder(node->left);
        printf("%d, ", node->key);
        print_tree_inorder(node->right);
    }
}

void print_tree_postorder(Node *node) {
    if (node != NULL) {
        print_tree_postorder(node->left);
        print_tree_postorder(node->right);
        printf("%d, ", node->key);
    }
}

Node* get_root(Tree *tree) {
    return tree->root;
}
