#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"

int main() {
  struct node *headOfList = NULL;

  printf("Printing an empty list:\n");
  printList(headOfList);
  printf("\n");

  //headOfList = calloc(sizeof(struct node), 1);
  printf("populating the list\n\n");

  headOfList = insertAtFront(headOfList, "Tears in Heaven", "Eric Clapton");
  headOfList = insertAtFront(headOfList, "Stairway to Heaven", "Led Zeppelin");
  headOfList = insertAtFront(headOfList, "Highway to Hell", "ACDC");
  headOfList = insertAtFront(headOfList, "Crossroads", "Eric Clapton");
  headOfList = insertAtFront(headOfList, "Hey Jude", "The Beatles");
  headOfList = insertAtFront(headOfList, "Coda", "Led Zeppelin");
  headOfList = insertAtFront(headOfList, "I Wanna Hold Your Hand", "The Beatles");

  printf("printing list\n");
  printList(headOfList);
  printf("\n\n");

  printf("Finding crossroads:\n");
  printSingleNode(findSong(headOfList, "Crossroads"));
  printf("\n");
  printf("Finding imagine:\n");
  printSingleNode(findSong(headOfList, "Imagine"));
  printf("\n\n");
  printf("Finding first song by led zeppelin:\n");
  printSingleNode(findSongByArtist(headOfList, "Led Zeppelin"));
  printf("\n");
  printf("Finding first song by Guns n Roses:\n");
  printSingleNode(findSongByArtist(headOfList, "Guns n Roses"));
  printf("\n\n");

  printf("removing middle node, value of node should be \"Eric Clapton | Crossroads\"\n");
  headOfList = removeNode(headOfList, "Crossroads", "Eric Clapton");
  printf("printing list\n");
  printf("\n");
  printf("removing node of \"StringStorm | Cadian Blood\", which does not exist\n");
  headOfList = removeNode(headOfList, "Cadian Blood", "StringStorm");

  printList(headOfList);
  printf("\n\n");

  printf("Freeing entire list\n");
  headOfList = freeList(headOfList);
  //the first freeList print message, with "Freeing" instead of "freeing",
  //was for the first node to be made which had a NULL for its data field.
  printf("list head pointer value should be NULL, actually %lu\n\n", headOfList);

  printf("printing list, the method will catch the null pointer: \n");
  printList(headOfList);
  /*
  */
  return 0;
}
