#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodes.h"

void printList(struct node *headOfList) {
  if(headOfList == NULL) {printf("List is empty");}
  else {
    printf("[");
    while(headOfList != NULL) {
      printf("%s | ", headOfList->artist);
      printf("%s ; ", headOfList->songName);
      headOfList = headOfList->nextNode;
    }
    printf("]");
  }
}

struct node * insertAtFront(struct node *headOfList, char *newSong, char *newArtist) {
  struct node *newHead = calloc(sizeof(struct node), 1);
  newHead->nextNode = headOfList;
  strcpy(newHead->songName, newSong);
  strcpy(newHead->artist, newArtist);
  return newHead;
}

struct node * removeNode(struct node *headOfList, char *targetSong, char *targetArtist) {
  //renamed method due to conflict with existing inbuilt remove
  struct node *next = headOfList->nextNode;
  int isEqual = strcmp(next->songName, targetSong) + strcmp(next->artist, targetArtist);
  if (headOfList->nextNode != NULL && isEqual != 0) {
    removeNode(headOfList->nextNode, targetSong, targetArtist);
  }
  if (headOfList->nextNode == NULL) {
    printf("Node with value of %s | %s not found\n", *targetArtist, *targetSong);
    return headOfList;
  }
  if (isEqual == 0) {
    struct node *restOfList = headOfList->nextNode->nextNode;
    struct node *ax = headOfList->nextNode;
    printf("Removing node with the value of %s | %s\n", ax->artist, ax->songName);
    free(ax);
    headOfList->nextNode = restOfList;
  }
  return headOfList;
}

struct node * freeList(struct node *headOfList) {
  if (headOfList->nextNode == NULL) {
    printf("freeing node with the value of %s | %s\n", headOfList->artist, headOfList->songName);
    free(headOfList);
  }
  else {
    freeList(headOfList->nextNode);
    printf("freeing node with the value of %s | %s\n", headOfList->artist, headOfList->songName);
    free(headOfList);
  }
  return NULL;
}

void printSingleNode(struct node *headOfList) { //helper function
  if (headOfList->songName != NULL && headOfList->artist != NULL) {
    printf("[");
    printf(headOfList->artist);
    printf(" | ");
    printf(headOfList->songName);
    printf("]");
  }
  else {
    printf("Song not found");
  }
}

struct node *findSong(struct node *no, char *search) {
  while(no != NULL) {
    if(strcmp(search, no->songName) == 0) {
      return no;
    }
    no = no->nextNode;
  }
  return NULL;
}
