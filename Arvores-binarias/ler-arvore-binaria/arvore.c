#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
TNo *TNo_createNFill(int key) {
  TNo *novo = malloc(sizeof(TNo));
  if (novo) {
    novo->key = key;
    novo->left = NULL;
    novo->right = NULL;
  }
  return novo;
}

void BinTree_inorder(TNo *root) {
  if (root) {
    BinTree_inorder(root->left);
    printf("%d, ", root->key);
    BinTree_inorder(root->right);
  }
}

TNo *BinTree_readFromStr(char *str) {
  TNo *root = NULL;
  if (*str == '(') {
    str++;
    if (*str != ')') {
      int key;
      if (sscanf(str, "%d", &key) == 1) {
        root = TNo_createNFill(key);
        while (*str != ')' && *str != '\0' && *str != '(')
          str++;
        root->left = BinTree_readFromStr(str);
        root->right = BinTree_readFromStr(str);
      }
    }
  }
  if (*str == ')')
    str++;
  return root;
}
