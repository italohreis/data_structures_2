#include <stdio.h>
#include "arvore.h"

int main() {

    //inserir 10, 20, 30

    Tree *tree = tree_create();
    bool h = false;

    Node *root = get_root(tree);

    node_insert(&root, 10, &h);

    //pre-ordem
    printf("Pre-ordem: ");
    pre_order(root);

    return 0;
}