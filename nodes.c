#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodes.h"

void printList(struct node *headOfList) {
  printf("[");
  if (headOfList != NULL) {
    printSingleNode(headOfList);
  }
  else {
    printf(" EMPTY LIST ");
  }
  printf("]\n");
}

struct node * insertAtFront(struct node *headOfList, char *cargo) {
  struct node *newHead = calloc(sizeof(struct node), 1);
  newHead->nextNode = headOfList;
  strcpy(newHead->songName, cargo);
  return newHead;
}

struct node * removeNode(struct node *headOfList, char *target) {
  //renamed method due to conflict with existing inbuilt remove
  if (headOfList->nextNode != NULL && headOfList->nextNode->songName != target) {
    removeNode(headOfList->nextNode, target);
  }
  if (headOfList->nextNode == NULL) {
    return headOfList;
  }
  if (headOfList->nextNode->songName == target) {
    struct node *restOfList = headOfList->nextNode->nextNode;
    struct node *ax = headOfList->nextNode;
    printf("Removing node with the value of %i\n", ax->songName);
    free(ax);
    headOfList->nextNode = restOfList;
  }
  return headOfList;
}

struct node * freeList(struct node *headOfList) {
  if (headOfList->nextNode == NULL) {
    printf("Freeing node with the value of %i (base case)\n", headOfList->songName);
    free(headOfList);
  }
  else {
    freeList(headOfList->nextNode);
    printf("freeing node with the value of %i (recursive case)\n", headOfList->songName);
    free(headOfList);
  }
  return NULL;
}

void printSingleNode(struct node *headOfList) { //helper function
  if (headOfList->songName != NULL) {
    printf(" ");
    printf(headOfList->songName);
    printf(" ");
  }
  if (headOfList->nextNode != NULL) {
    printSingleNode(headOfList->nextNode);
  }
}
