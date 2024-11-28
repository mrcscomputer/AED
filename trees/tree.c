#include <stdlib.h>
 1 #include <stdio.h>
 2 #include "tree.h"
 3 
 4 struct node* newNode(int data){
 5   struct node* node = malloc(sizeof(node));
 6   node->data = data;
 7   node->left = NULL;
 8   node->right = NULL;
 9   return node;
10 }
11 
12 struct node* insert(struct node* node; int data){
13   if(node){
14     if(data <= node->data)
15       node->left = insert(node->left, data);
16     else
17       node->right = insert(node->right, data);
18   }else
19     return newNode(data);
20   return node;
21 }
22 void printArray(int path[], int size){
23    for(int i = 0; i < size; i++)
19     printf("%d, ", path[i]);
18 printf("\n");
17 }
16 void printPathsRecur(struct node* node, int path[], int pathlen){
15   if(node){
14     path[pathlen++] = node->data;
13     if(!node->left && !node->right)
12       printArray(path, pathlen);
11     else {
10       printPathsRecur(node->left, path, pathlen);
 9       printPathsRecur(node->right, path, pathlen);
 8     }
 7   }
 6 }
 5 void printPaths(struct node* node){
 4   int len = 100; //TODO lenght(node);
 3   int* argv = malloc(sizeof(int) * len);
 2   printPathsRecur(node, argv, 0);
 1 }

