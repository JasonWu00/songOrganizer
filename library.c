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
    table[counter] = freeList(table[counter]);
  }
  return NULL;
}

struct node * insertAtRandom(struct node *output, int nthLetter) {//helper function
  //takes the values of the nodes of one part of the library
  //and adds them into another output list randomly

  //output is the linked list to randomly add nodes to
  //nthLetter tells which section of the library to copy nodes from

  struct node *listHead = table[nthLetter];//start of list
  struct node *rememberHead = listHead;

  int nodesInLibrary = 0;//how many nodes in this part of the library
  if (listHead == NULL) {
    nodesInLibrary = 0;
    //printf("Empty library, exiting function\n");
    return output;
  }
  else {
    while (listHead != NULL) {//
      nodesInLibrary++;
      listHead = listHead->nextNode;
    }
  }
  listHead = rememberHead; //reset listHead back to before the while loop
  //printf("\ninsertAtRandom debug: nodesInLibrary = %i\n", nodesInLibrary);

  int nodesInOutput = 0;//how many nodes in output
  struct node *startOfOutput = output;//to remember the original output
  if (output == NULL) {
    nodesInOutput = 0;
  }
  else {
    while (output != NULL) {
      nodesInOutput++;
      output = output->nextNode;
    }
  }
  output = startOfOutput;//reset output back to the start
  //printf("insertAtRandom debug: nodesInOutput = %i\n", nodesInOutput);

  //printList(table[nthLetter]);
  //printf("\n");

  //iterate through the linkedList, adding its contents randomly
  int nodesInserted = 0;

  if (nodesInLibrary == 0) {
    //return listHead;
    //printf("Empty list, exiting loop\n");
  }
  else {
    //printf("Now in the else\n");

    while (listHead != NULL) {
      //printf("Now in the for loop\n");
      /*if (listHead = NULL) {//empty list, exit loop
        printf("Empty list, exiting loop\n");
        nodesInserted = nodesInLibrary;
      }*/
      if (nodesInOutput == 0) {//empty output, put in first node trivially
        //printf("Inserting first node\n");
        output = insertAtFront(output, listHead->songName, listHead->artist);
        //printList(output);
        nodesInOutput++;
        listHead = listHead->nextNode;
      }

      else {
        //printf("Now in the second else\n");
        struct node *cloneOutput = output;

        int goToHere;
        if (nodesInOutput <= 1) {
          goToHere = 1;
        }
        else {
          goToHere = rand() % nodesInOutput;
        }
        //printf("DEBUG: nodesInOutput = %i, goToHere = %i\n", nodesInOutput, goToHere);

        int weThereYet = 0;
        while (weThereYet < goToHere && cloneOutput != NULL) {
          weThereYet++;
          cloneOutput = cloneOutput->nextNode;
        }
        //printf("DEBUG: weThereYet = %i\n", weThereYet);
        //cloneOutput = insertAtFront(output, listHead->songName, listHead->artist);
        output = insertInMiddle(output, listHead->songName, listHead->artist, weThereYet);
        nodesInOutput++;

        //printf("Inserted node randomly, hopefully. Printing list.\n");
        //printList(output);
        listHead = listHead->nextNode;
      }
      //printf("End of the for loop\n");
    }
    //printf("End of the else block\n");
  }
  //printf("Quick debug: printing out the linked list\n");
  //printList(output);
  return output;
}

void printShuffle() {//uses insertAtRandom for every linkedList in the library
  struct node *output = NULL;
  int counter = 0;
  for(counter = 0; counter < 27; counter++) {
    output = insertAtRandom(output, counter);
  }
  printf("\nPrinting shuffled list here\n");
  printList(output);
  printf("\n");
  freeList(output);
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
