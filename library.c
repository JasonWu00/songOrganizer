#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "library.h"
#include "nodes.h"
char alphabet[53] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";

int nthLetter(char *string) {//helper function
  char strToCheck[25];
  strcpy(strToCheck, string);
  int counter = 0;
  for (counter = 0; counter < 53; counter++) {
    if (alphabet[counter] == strToCheck[0]) {
      return counter/2;
    }
  }
  return 0;
}

struct node * addSong(char *songName, char *artist) {
  char addArtist[25];
  strcpy(addArtist, artist);
  int nth_letter = nthLetter(addArtist);
  //printf("DEBUG: the first letter (that being %c) is the %ith letter in the alphabet.\n", addArtist[0], nth_letter);

  //first letter of song title needs to always be upper case!
  table[nth_letter] = insertInOrder(table[nth_letter], songName, artist);
  return table[nth_letter];
}

void printEntireLibrary() {
  int counter = 0;
  for (counter = 0; counter < 27; counter++) {
    if (table[counter] != NULL) {
      printf("Artists starting with %c\n", toupper(alphabet[counter * 2]));
      printList(table[counter]);
      printf("\n");
    }
    else {
      printf("");
    }
  }
}

struct node * searchSong(char *songToFind, char *artistToFind) {
  int nth_letter = nthLetter(artistToFind);
  struct node * output = findSong(table[nth_letter], songToFind);
  return output;
}

struct node * searchArtist(char *artistToFind) {
  int nth_letter = nthLetter(artistToFind);
  struct node * output = findSongByArtist(table[nth_letter], artistToFind);
  return output;
}

void printLetter(char *letter) {
  int nth_letter = nthLetter(letter);
  printList(table[nth_letter]);
}

struct node * removeSong(char *songName, char *artistName) {
  int nth_letter = nthLetter(artistName);
  table[nth_letter] = removeNode(table[nth_letter], songName, artistName);
  return NULL;
}

void printSongsByArtist(char *artistToFind) {
  struct node * pointer = searchArtist(artistToFind);
  while (pointer != NULL) {
    if (strcmp(pointer->artist, artistToFind) == 0) {
      printSingleNode(pointer);
      printf(" ");
      pointer = pointer->nextNode;
    }
  }
}


struct node *clearLib() {
  int counter = 0;
  for (counter = 0; counter < 27; counter++) {
    freeList(table[counter]);
  }
  return NULL;
}

/*
void printArtist(char *art) {
  struct node *no = table[(int)art[0] - 65];
  for(no != NULL) {
    if(strcmp(art, no->artist) == 0) {
      printSingleNode(no);
    }
  }
}*/
