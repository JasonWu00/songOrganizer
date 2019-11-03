#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "library.h"
#include "nodes.h"

struct node *array[27];


struct node *addSong(char *songName, char *artist) {
//first letter of song title needs to always be upper case!
  array[(int)artist[0] - 65] = insertInOrder(array[(int)artist[0] - 65], songName, artist);
  return array[(int)artist[0]];
}

struct node *searchSong(char *sn, char *art) {
  struct node *no = array[(int)artist[0] - 65];
  for(no != NULL) {
    if(strcmp(sn, no->songName) == 0) {
      return no;
    }
    no = no->nextNode;
  }
  return NULL;
}

bool searchArtist(char *art) {
  struct node *no = array[(int)art[0] - 65];
  for(no != NULL) {
    if(strcmp(art, no->artist) == 0) {return true;}
  }
  return false;
}

void printLetter(char let) {
  int le = (int)let;
  if(le > 96) {le = le - 32;}
  printList(array[le - 65]);
}

void printArtist(char *art) {
  struct node *no = array[(int)art[0] - 65];
  for(no != NULL) {
    if(strcmp(art, no->artist) == 0) {
      printSingleNode(no);
    }
  }
}

void printLib() {
  for(int q = 0; q < 27; q++) {
    struct no = array[q];
    printList(no);
  }
}

struct node *removeSong(char *sn) {
  for(int q = 0; q < 27; q++) {
    struct node *no = array[q];
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
