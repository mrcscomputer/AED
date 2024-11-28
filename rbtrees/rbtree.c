#include <stdlib.h>
#include "rbtree.h"

RBNode* createRBNode(int key){
  RBNode* newNode = malloc(sizeof(RBNode));
  newNode->parent = NULL;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->color = RED;
  newNode->key = key ;
  return newNode;
}

RBTree* createRBTree(){
  RBTree* rbTree = malloc(sizeof(RBTree));
  rbTree->root = NULL;
  return rbTree;
}

void insertRBT(RBTree *t, RBNode *z){
  RBNode* x = t->root;
  RBNode* y = NULL;
  
  while(x != NULL){
    y = x;
    if(z->key < x->key)
      x = x->left;
    else
      x = x->right;
  }

  z->parent = y;

  if(y){
    if(z->key < y->key)
      y->left = z;
    else
      y->right = z;
  }else{
    t->root = z;
  }
  //rbInsertFixUp(t, z);
}
void leftRotate(RBTree* t, RBNode* x){
  RBNode* y = x->right;
  assert(y);
  x->right = y->left;
  if(y->left)
    y->left->parent = x;
  y->parent = x->parent;
  if(!x->parent)
    t->root = y;
  else if(x == x->parent->left)
    x->parent->left = y;
  else
    x->parent->right = y;
  y->left = x;
  x->parent = y;
}

void rigthRotate(RBTree* t, RBNode* y){
  RBNode* x = y->left;
  assert(x);
  y->left = x->right;
  if(x->rigth)//se usa esto para evitar segmentation fault
    x->right->parent = y;
  x->parent = y->parent;
 5   if(!x->parent)
 4     t->root = y;
 3   else if(x == x->parent->left)
 2     x->parent->left = y;
 1   else
56     x->parent->right = y;
 1   y->left = x;
 2   x->parent = y;
 3 }
  
