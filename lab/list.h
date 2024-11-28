#ifndef LIST_H
#define LIST_H
struct Node {
  int data;
  struct Node* next;
};
int length(struct Node* head);
struct Node* buildOneTwoThree();
int count(struct Node* list, int n);
int getNth(struct Node* head, int index);
void deleteList(struct Node** headPtr);
int pop(struct Node** headPtr);
void insertNth(struct Node** headPtr, int index, int data);

#endif

