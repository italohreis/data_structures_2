#include "arvore.h"
#include <stdio.h>

void printTree(TNo *root) {
  printf("Inorder:");
  BinTree_inorder(root);
  printf("\n");
}
int main(void) {
  TNo *root = NULL;
  char str[4096];
  if (scanf("%s", str) == 1)
    printf("%s", str);
  root = BinTree_readFromStr(str);
  printTree(root);
  return 0;
}