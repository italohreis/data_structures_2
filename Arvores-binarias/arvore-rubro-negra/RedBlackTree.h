#ifndef REDBLACKTREE
#define REDBLACKTREE

typedef struct _node Node;
typedef struct _tree Tree;

Tree *createTree();

Node *createNode(Tree *T, int key);

void RB_insert(Tree *T, int key);

void RB_insert_fixup(Tree *T, Node *z);

void left_rotate(Tree *T, Node *z);

void right_rotate(Tree *T, Node *z);

void pre_order(Tree *T, Node *node);

Node *get_root(Tree *T);

#endif