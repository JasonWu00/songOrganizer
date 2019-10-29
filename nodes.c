#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"

void printList(struct node *headOfList) {
  printf("[");
  if (headOfList != NULL) {
    printSingleNode(headOfList);
  }
  else {
    printf(" NULL POINTER ");
  }
  printf("]\n");
}

struct node * insertAtFront(struct node *headOfList, int cargo) {
  struct node *newHead = calloc(sizeof(struct node), 1);
  newHead->nextNode = headOfList;
  newHead->data = cargo;
  return newHead;
}

struct node * removeNode(struct node *headOfList, int target) {
  //renamed method due to conflict with existing inbuilt remove
  if (headOfList->nextNode != NULL && headOfList->nextNode->data != target) {
    removeNode(headOfList->nextNode, target);
  }
  if (headOfList->nextNode == NULL) {
    return headOfList;
  }
  if (headOfList->nextNode->data == target) {
    struct node *restOfList = headOfList->nextNode->nextNode;
    struct node *ax = headOfList->nextNode;
    printf("Removing node with the value of %i\n", ax->data);
    free(ax);
    headOfList->nextNode = restOfList;
  }
  return headOfList;
}

struct node * freeList(struct node *headOfList) {
  if (headOfList->nextNode == NULL) {
    printf("Freeing node with the value of %i (base case)\n", headOfList->data);
    free(headOfList);
  }
  else {
    freeList(headOfList->nextNode);
    printf("freeing node with the value of %i (recursive case)\n", headOfList->data);
    free(headOfList);
  }
  return NULL;
}

void printSingleNode(struct node *headOfList) { //helper function
  if (headOfList->data != NULL) {
    printf(" %i ", headOfList->data);
  }
  if (headOfList->nextNode != NULL) {
    printSingleNode(headOfList->nextNode);
  }
}
