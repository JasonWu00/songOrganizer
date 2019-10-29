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

  headOfList = insertAtFront(headOfList, "one");
  headOfList = insertAtFront(headOfList, "two");
  headOfList = insertAtFront(headOfList, "three");
  headOfList = insertAtFront(headOfList, "four");
  headOfList = insertAtFront(headOfList, "three");
  headOfList = insertAtFront(headOfList, "two");
  headOfList = insertAtFront(headOfList, "one");

  printf("printing list\n");
  printList(headOfList);
  printf("\n");
  /*

  printf("removing middle node, value of node should be 4\n");
  headOfList = removeNode(headOfList, 4);
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
  */
  return 0;
}
