#include <stdio.h>
#include "arvore.h"

int main() {
    
    Tree *tree = create_tree();

    int v[] = {5, 9, 3, 2, 1, 6, 10};
    int i;
    for (i = 0; i < 7; i++) {
        insert(tree, v[i]);
    }

    printf("\nPre-order: ");
    print_tree_preorder(get_root(tree));

    printf("\nIn order: ");
    print_tree_inorder(get_root(tree));

    printf("\nPost-order: ");
    print_tree_postorder(get_root(tree));

    remove_node(tree, 2);
    printf("removed node 3: \n");
    print_tree_preorder(get_root(tree));

    return 0;
}