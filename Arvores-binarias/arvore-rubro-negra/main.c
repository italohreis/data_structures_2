#include <stdio.h>
#include "RedBlackTree.h"

int main() {
    //28,30,1,5,13,8,25,12,6,2
    int keys[] = {28,30,1,5,13,8,25,12,6,2};
    Tree *tree = createTree();
    
    int i;
    for (i = 0; i < 10; i++) {
        printf("Inserindo %d\n", keys[i]);
        RB_insert(tree, keys[i]);
    }

    pre_order(tree, get_root(tree));

    return 0;
}