#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"

int main() {
  struct node *headOfList = NULL;

  printf("Printing an empty list:\n");
  printList(headOfList);
  printf("\n");

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
  printf("\n");

  printf("Finding hey jude:\n");
  printSingleNode(findSong(headOfList, "Hey Jude"));
  printf("\n");

  printf("removing middle node, value of node should be \"Eric Clapton | Crossroads\"\n");
  headOfList = removeNode(headOfList, "Crossroads", "Eric Clapton");
  printf("printing list\n");
  printList(headOfList);
  printf("\n");

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
