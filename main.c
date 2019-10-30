#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"

int main() {
  struct node *headOfList = NULL;

  printf("Printing an empty list:\n");
  printList(headOfList);
  printf("\n");

  printf("populating the list\n\n");

  headOfList = insertAtFront(headOfList, "one", "example");
  headOfList = insertAtFront(headOfList, "two", "example");
  headOfList = insertAtFront(headOfList, "three", "example");
  headOfList = insertAtFront(headOfList, "four", "example");
  headOfList = insertAtFront(headOfList, "three", "example");
  headOfList = insertAtFront(headOfList, "two", "example");
  headOfList = insertAtFront(headOfList, "one", "example");

  printf("printing list\n");
  printList(headOfList);
  printf("\n");

  printf("removing middle node, value of node should be \"example | four\"\n");
  headOfList = removeNode(headOfList, "four", "example");
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
