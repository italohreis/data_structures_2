#ifndef ARVORE_H
#define ARVORE_H
typedef struct _no {
  int key;
  struct _no *left, *right;
} TNo;

TNo *TNo_createNFill(int);
TNo *BinTree_readFromStr(char *);
void BinTree_inorder(TNo *root);
void BinTree_posorder(TNo *root);
void BinTree_preorder(TNo *root);

#endif