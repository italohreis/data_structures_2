#ifndef ARVORE_H
#define ARVORE_H

typedef struct _node Node;
typedef struct _tree Tree;

Tree* create_tree();

Node* create_node(int value);

void insert(Tree *tree, int value);

void print_tree_preorder(Node *node);

void print_tree_inorder(Node *node);

void print_tree_inorder(Node *node);

void print_tree_postorder(Node *node);

void transplante(Tree *tree, Node *u, Node *v);

void remove_node(Tree *tree, int value);

int tree_height(Tree *tree);

int tree_height_node(Node *node);

Node *tree_minimum(Node *node);

Node *tree_maximum(Node *node);

Node* get_root(Tree *tree);

#endif