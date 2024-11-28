#include<stdio.h>
#include "avl.h"
int main(int argc, char* argv[]){
  struct AVL* root = 0;
  printf("%d\n", height(root));
  root = insert(root, 5);
  printf("%d\n", height(root));
  root = insert(root, 3);
  printf("%d\n", height(root));
  root = insert(root, 9);
  printf("%d\n", height(root));
  root = insert(root, 1);
  printf("%d\n", height(root));
  root = insert(root, 4);
  printf("%d\n", height(root));
  root = insert(root, 6);
  printf("%d\n", height(root));
}

