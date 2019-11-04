#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodes.h"

void printList(struct node *headOfList) {
  if(headOfList == NULL) {
    printf("[ List is empty ]\n");
  }
  else {
    printf("[");
    while(headOfList != NULL) {
      if (headOfList->songName == NULL && headOfList->artist == NULL) {
        printf("");
      }
      else {
        printf("%s | ", headOfList->artist);
        printf("%s ; ", headOfList->songName);
      }
      headOfList = headOfList->nextNode;
    }
    printf("]\n");
  }
}

struct node * insertAtFront(struct node *headOfList, char *newSong, char *newArtist) {
  struct node *newHead = calloc(sizeof(struct node), 1);
  newHead->nextNode = headOfList;
  if (headOfList != NULL) {//special case, the list is empty
    headOfList->previousNode = newHead;
  }
  strcpy(newHead->songName, newSong);
  strcpy(newHead->artist, newArtist);
  return newHead;
}

struct node * insertInOrder(struct node *headOfList, char *newSong, char *newArtist) {
  char targetSong[25];
  char targetArtist[25];
  //printf("-----INSERT IN ORDER DEBUG PRINTS-----\n");
  strcpy(targetSong, newSong);
  strcpy(targetArtist, newArtist);
  //check for correct artist position
  //if correct:
  //printf("debug\n");

  if (headOfList == NULL) {//special case, empty list
    //printf("Inserting first node\n");
    headOfList = insertAtFront(headOfList, newSong, newArtist);
    return headOfList;
  }

  int artistCompare = strcmp(newArtist, headOfList->artist);
  int songCompare = strcmp(newSong, headOfList->songName);

  if (headOfList->nextNode == NULL && headOfList->previousNode == NULL) {
    //another special case, only 1 node in list
    if (artistCompare < 0) {//node to insert go to back
      //printf("DEBUG: value of artistCompare: %i\n", artistCompare);
      headOfList->previousNode = insertAtFront(headOfList, newSong, newArtist);
      //printf("Inserting second node (value %s | %s) at the front\n", newArtist, newSong);
      return headOfList->previousNode;
    }
    else if (artistCompare > 0){//node to insert go to front
      headOfList->nextNode = insertAtFront(headOfList->nextNode, newSong, newArtist);
      //printf("Inserting second node (value %s | %s) at the back\n", newArtist, newSong);
      return headOfList;
    }
    else if (artistCompare == 0 && songCompare < 0) {//node go to front
      headOfList->previousNode = insertAtFront(headOfList, newSong, newArtist);
      //printf("Inserting second node (value %s | %s) at the front (second case)\n", newArtist, newSong);
      return headOfList->previousNode;
    }
    else {//previousNode go to back
      headOfList->nextNode = insertAtFront(headOfList->nextNode, newSong, newArtist);
      //printf("Inserting second node (value %s | %s) at the back (second case)\n", newArtist, newSong);
      return headOfList;
    }
  }

  if (headOfList->nextNode == NULL) {//end of list reached
    //printf("Somehow, the program reached the end. Guess I will plop down the node here.\n");
    headOfList->nextNode = insertAtFront(headOfList, newSong, newArtist);
    return headOfList;
  }

  else if (artistCompare <= 0) {
    //check for correct song position
    if (songCompare <= 0) {//we found the proper place to insert the node
      headOfList = insertAtFront(headOfList, newSong, newArtist);
      //printf("We have found the correct position\n");
      return headOfList;
    }

    else {//right artist, not the right song
      headOfList->nextNode = insertInOrder(headOfList->nextNode, newSong, newArtist);
      //printf("Correct artist but not correct position\n");
      return headOfList;
    }
  }

  else {//not at the right spot yet, keep moving
    //printf("Not at the correct artist yet\n");
    headOfList->nextNode = insertInOrder(headOfList->nextNode, newSong, newArtist);
    return headOfList;
    //no option for correct song position but not artist position
  }
}

struct node * removeNode(struct node *headOfList, const char *targetSong, const char *targetArtist) {
  char thisSong[25];
  char thisArtist[25];
  strcpy(thisSong, targetSong);
  strcpy(thisArtist, targetArtist);
  int songCompare = strcmp(thisSong, headOfList->songName);
  int artistCompare = strcmp(thisArtist, headOfList->artist);
  //printf("DEBUG: thisSong: %s, thisArtist: %s\n", thisSong, thisArtist);
  //printf("DEBUG: comparison of song: %i, comparison of artist: %i\n", songCompare, artistCompare);

  //base case, the current node is the one we must remove
  if (songCompare == 0 && artistCompare == 0) {
    printf("Removing node with the value of %s | %s\n", headOfList->artist, headOfList->songName);
    struct node *restOfList = headOfList->nextNode;
    free(headOfList);
    return restOfList;
  }
  //recursive case, the current node is not the one we seek, and it is the end
  else if (headOfList->nextNode == NULL) {
    printf("Node with value of %s | %s not found\n", targetArtist, targetSong);
    return headOfList;
  }
  //recursive case, the current node is not the one we seek and there are more nodes
  else {
    printf("Passing through node with values %s | %s\n", headOfList->artist, headOfList->songName);
    headOfList->nextNode = removeNode(headOfList->nextNode, targetSong, targetArtist);
    return headOfList;
  }
  printf("\n");
}

struct node * freeList(struct node *headOfList) {
  if (headOfList == NULL) {
    printf("List already cleared");
  }
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
    printf("");
  }
}

struct node *findSong(struct node *no, char *search) {
  while(no != NULL) {
    if(strcmp(search, no->songName) == 0) {
      //printSingleNode(no);
      return no;
    }
    no = no->nextNode;
  }
  printf("Song not found!");
  return NULL;
}

struct node *findSongByArtist(struct node *no, char *search) {
  while(no != NULL) {
    if(strcmp(search, no->artist) == 0) {
      //printList(no);
      return no;
    }
    no = no->nextNode;
  }
  printf("No songs by this artist found!\n");
  return NULL;
}

struct node *randomSong(struct node *no) {
  int q = 0;
  struct node *noo = no;
  while(no != NULL) {
    q++;
    no = no->nextNode;
  }
  int rno = rand() % q;
  for(int w = 0; w < rno; w++) {
    noo = noo->nextNode;
  }
  return noo;
}
