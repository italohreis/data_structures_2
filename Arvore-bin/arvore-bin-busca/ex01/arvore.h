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
void transplante();




Node* get_root(Tree *tree);

#endif