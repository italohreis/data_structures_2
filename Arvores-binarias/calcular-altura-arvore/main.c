#include <stdio.h>
#include "arvore.h"

int main() {  
    Tree *tree = create_tree();
    int v[] = {10, 5, 15, 3, 7, 12, 18};

    int i;
    for (i = 0; i < 7; i++) {
        insert(tree, v[i]);
    }

    printf("\nPre-order: ");
    print_tree_preorder(get_root(tree));

    printf("\ntree height: %d\n", tree_height(tree));

    return 0;
}