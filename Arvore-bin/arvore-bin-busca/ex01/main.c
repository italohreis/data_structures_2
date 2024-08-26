#include <stdio.h>
#include "arvore.h"

int main() {
    
    Tree *tree = create_tree();

    insert(tree, 5);
    insert(tree, 2);
    insert(tree, 3);
    insert(tree, 4);
    insert(tree, 1);
    insert(tree, 6);

    printf("\nPre-order: ");

    print_tree_preorder(get_root(tree));
    printf("\nIn order: ");

    print_tree_inorder(get_root(tree));
    printf("\nPost-order: ");
    print_tree_postorder(get_root(tree));

    return 0;
}