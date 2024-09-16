#include <stdio.h>
#include "arvore.h"

int main() {
    Tree *tree = tree_create();
    bool h = false;

    Node *root = get_root(tree);
    
    node_insert(&root, 4, &h);
    node_insert(&root, 3, &h);
    node_insert(&root, 2, &h);
    

    printf("Pre-ordem: ");
    pre_order(root);

    return 0;
}