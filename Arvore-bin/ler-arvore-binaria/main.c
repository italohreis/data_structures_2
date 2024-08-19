#include <stdio.h>
#include "arvore.h"
#include <stdlib.h>
#include <ctype.h>

Node *ler_arvore(char *input, int *index) {
    Node *raiz = NULL;
    if (input[*index] == ')') {
        (*index)++;

        if(input[*index] == '(') {
            (*index)++;    
        }
        else {  //é um numero
            int num = 0;
            while (isdigit(input[*index])) {
                num = num * 10 + (input[*index] - '0');
                (*index)++;
            }
            printf("num: %d\n", num);
            raiz = (Node*) malloc(sizeof(Node));
            raiz->info = num;
            raiz->left = ler_arvore(input, index);
            raiz->right = ler_arvore(input, index);
            (*index)++;
        }
    }
    
    return raiz;
}

//ler arvore em parenteses
int main() {
    
    char input[] = "(7(5()(6))(10()(12)))";

    int index = 0;
    Node *raiz = ler_arvore(input, &index);

    //printar
    if (raiz != NULL) {
        printf("raiz: %d\n", raiz->info);
        if (raiz->left != NULL) {
            printf("raiz->left: %d\n", raiz->left->info);
        } else {
            printf("raiz->left: NULL\n");
        }
        if (raiz->right != NULL) {
            printf("raiz->right: %d\n", raiz->right->info);
        } else {
            printf("raiz->right: NULL\n");
        }
    } else {
        printf("raiz: NULL\n");
    }



    return 0;
}