#include <stdlib.h>
#include "rbtree.h"
#include <assert.h>

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
  RBNode* x = y->left;//crea x y sera el nodo izq de y
  assert(x);//existe el nodo izquierdo? termina si es falso//necesario? creo q no, xq no estaria desbalanceado
  y->left = x->right;//al ser girado a la derecha x ya no sera left de y, x.rigth apunta a y

  if(x->right)//se usa esto para evitar segmentation fault
    x->right->parent = y;// y apunta a x.rigth
  x->parent = y->parent;//x e y apuntan al mismo padre
  if(!y->parent)//y es raiz'?
    t->root=x;//x ahora es raiz
  else if(y==y->parent->right)//y es derecho de su padre?
    y->parent->right=x;//x ahora es derecho de su padre
  else 
    y->parent->left=x;//x ahora es izq de su padre
  x->right=y;//y apunta a x, como hijo derecho
  y->parent=x;//x apunta a y, como padre
}


