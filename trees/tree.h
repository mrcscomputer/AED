#ifndef TREE_H
#define TREE_H
struct node {
  int data;
  struct node* left;
  struct node* rigth;
};
struct node* newNode(int data);
struct node* insert(struct node* node, int data);
void printPaths(struct node* node);
#endif
~         
