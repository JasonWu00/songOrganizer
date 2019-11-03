#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "library.h"
#include "nodes.h"

struct node * table[27];

char alphabet[53] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
char *alpha = &alphabet[53];

struct node * addSong(char *songName, char *artist) {
  char addArtist[25];
  strcpy(addArtist, artist);
  char *firstLetter = strchr(alpha, addArtist[0]);
  int nthLetter = firstLetter - &alphabet[0];
  printf("DEBUG: the first letter (that being %c) is the %ith letter in the alphabet.\n", firstLetter, nthLetter);
  //first letter of song title needs to always be upper case!
  //table[(int)artist[0] - 65] = insertInOrder(table[(int)artist[0] - 65], songName, artist);
  //return table[(int)artist[0]];
  return NULL;
}
/*

struct node * searchSong(char *sn, char *art) {
  struct node *no = table[(int)artist[0] - 65];
  for(no != NULL) {
    if(strcmp(sn, no->songName) == 0) {
      return no;
    }
    no = no->nextNode;
  }
  return NULL;
}

int searchArtist(char *art) {
  struct node *no = table[(int)art[0] - 65];
  for(no != NULL) {
    if(strcmp(art, no->artist) == 0) {
      return true;
    }
  }
  return NULL;
}

void printLetter(char let) {
  int le = (int)let;
  if(le > 96) {le = le - 32;}
  printList(table[le - 65]);
}

void printArtist(char *art) {
  struct node *no = table[(int)art[0] - 65];
  for(no != NULL) {
    if(strcmp(art, no->artist) == 0) {
      printSingleNode(no);
    }
  }
}

void printLib() {
  for(int q = 0; q < 27; q++) {
    struct no = table[q];
    printList(no);
  }
}

struct node * removeSong(char *sn) {
  for(int q = 0; q < 27; q++) {
    struct node *no = table[q];
    struct node *begin = no;
    while(no != NULL) {
      if(strcmp(sn, no->songName) == 0) {
        return removeNode(begin, no->songName, no->artist);
      }
    }
  }
  return NULL;
}

struct node *clearLib() {

}
*/
