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

void remove_node(Tree *tree, int value) {
    Node *z = tree->root;
    while (z != NULL && z->key != value) {
        if (value < z->key) {
            z = z->left;
        } else {
            z = z->right;
        }
    }
    if (z == NULL) {
        return;
    }

    if (z->left == NULL) {
        transplante(tree, z, z->right);
    } else if(z->right == NULL) {
        transplante(tree, z, z->left);
    } else {
        Node *y = tree_minimum(z->right);
        if (y->p != z) {
            transplante(tree, y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        transplante(tree, z, y);
        y->left = z->left;
        y->left->p = y;
    }    

    free(z);
}

void transplante(Tree *tree, Node *u, Node *v) {
    if (u->p == NULL) {
        tree->root = v; 
    } else if(u == u->p->left) {
        u->p->left = v;
    } else {
        u->p->right = v;
    }

    if (v != NULL)
        v->p = u->p;
}

Node *tree_minimum(Node *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

Node *tree_maximum(Node *node) {
    while (node->right != NULL) {
        node = node->right;
    }
    return node;
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
