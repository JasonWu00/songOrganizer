#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodes.h"
#include "library.h"

int main() {
  struct node *headOfList = NULL;

  printf("Printing an empty list:\n");
  printList(headOfList);
  printf("\n");

  printf("-----TESTING LINKED LIST-----\n\n");

  //headOfList = calloc(sizeof(struct node), 1);
  printf("populating the list, in order\n\n");

  headOfList = insertInOrder(headOfList, "Tears in Heaven", "Eric Clapton");
  headOfList = insertInOrder(headOfList, "Stairway to Heaven", "Led Zeppelin");
  headOfList = insertInOrder(headOfList, "Highway to Hell", "ACDC");
  headOfList = insertInOrder(headOfList, "Crossroads", "Eric Clapton");
  headOfList = insertInOrder(headOfList, "Hey Jude", "The Beatles");
  headOfList = insertInOrder(headOfList, "Coda", "Led Zeppelin");
  headOfList = insertInOrder(headOfList, "I Wanna Hold Your Hand", "The Beatles");

  printf("printing list\n");
  printList(headOfList);
  printf("\n");

  printf("-----Testing finding node by song and artist-----\n\n");

  printf("Finding crossroads:\n");
  findSong(headOfList, "Crossroads");
  printf("\n");
  printf("Finding imagine:\n");
  findSong(headOfList, "Imagine");
  printf("\n\n");
  printf("Finding first song by led zeppelin:\n");
  findSongByArtist(headOfList, "Led Zeppelin");
  printf("\n");
  printf("Finding first song by Guns n Roses:\n");
  findSongByArtist(headOfList, "Guns n Roses");
  printf("\n");

  printf("-----Testing remove nodes by value----\n\n");

  printf("removing middle node, value of node should be \"Eric Clapton | Crossroads\"\n");
  headOfList = removeNode(headOfList, "Crossroads", "Eric Clapton");
  printf("printing list\n");
  printList(headOfList);
  printf("\n");
  printf("removing node of \"StringStorm | Cadian Blood\", which is not in the list\n");
  headOfList = removeNode(headOfList, "Cadian Blood", "StringStorm");
  printf("\n");

  printf("After removing nodes:\n");
  printList(headOfList);
  printf("\n");

  printf("-----Testing freeing entire list-----\n\n");

  printf("Freeing entire list\n");
  headOfList = freeList(headOfList);
  //the first freeList print message, with "Freeing" instead of "freeing",
  //was for the first node to be made which had a NULL for its data field.
  printf("list head pointer value should be NULL, actually %lu\n\n", headOfList);

  printf("printing list, the method will catch the null pointer: \n");
  printList(headOfList);
  printf("\n");

  printf("-----TESTING SONG LIBRARY-----\n\n");
  /*
  */
  return 0;
}
