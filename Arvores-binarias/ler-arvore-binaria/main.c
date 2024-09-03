#include "arvore.h"
#include <stdio.h>

void printTree(TNo *root) {
  printf("\nInorder:");
  BinTree_inorder(root);
  printf("\n");
}
int main(void) {
  TNo *root = NULL;
  char str[4096];
  if (scanf("%s", str) == 1)
    printf("%s", str);
  
  char *p = str;
  root = BinTree_readFromStr(&p);
  printTree(root);
  return 0;
}