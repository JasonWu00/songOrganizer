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
  strcpy(newHead->songName, newSong);
  strcpy(newHead->artist, newArtist);
  return newHead;
}

struct node * removeNode(struct node *headOfList, char *targetSong, char *targetArtist) {
  //renamed method due to conflict with existing inbuilt remove
  char song[100];
  char artist[100];
  strcpy(song, targetSong);
  strcpy(artist, targetArtist);
  struct node *next = headOfList->nextNode;

  int nextSongEqual = abs(strcmp(next->songName, song));
  int nextArtistEqual = strcmp(next->artist, artist);
  //using abs() causes a seg fault, so I used an alternative
  int thisSongEqual = abs(strcmp(headOfList->songName, song));
  int thisArtistEqual = abs(strcmp(headOfList->artist, artist));

  int nextIsEqual = nextSongEqual + nextArtistEqual;

  printf("DEBUG: current node has value of %s | %s\n", headOfList->artist, headOfList->songName);
  printf("DEBUG: %i, %i\n", thisSongEqual, thisArtistEqual);

  if (thisSongEqual == 0 && thisArtistEqual == 0) {
    printf("Removing node with the value of %s | %s\n", headOfList->artist, headOfList->songName);
    struct node *next = headOfList->nextNode;
    free(headOfList);
    return next;
  }

  if (nextSongEqual == 0 && nextArtistEqual == 0) {
    struct node *restOfList = headOfList->nextNode->nextNode;
    struct node *ax = headOfList->nextNode;
    printf("Removing node with the value of %s | %s\n", ax->artist, ax->songName);
    free(ax);
    headOfList->nextNode = restOfList;
    return headOfList;
  }



  if (headOfList->nextNode != NULL && nextIsEqual != 0) {
    printf("Node not yet found\n");
    removeNode(headOfList->nextNode, targetSong, targetArtist);
  }

  if (headOfList->nextNode == NULL) {
    printf("Node with value of %s | %s not found\n", targetArtist, targetSong);
    return headOfList;
  }
  printf("\n");
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
    printf("");
  }
}

struct node *findSong(struct node *no, char *search) {
  while(no != NULL) {
    if(strcmp(search, no->songName) == 0) {
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
