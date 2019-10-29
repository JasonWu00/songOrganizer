#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"

int main() {
  struct node *headOfList;
  headOfList = calloc(sizeof(struct node), 1);

  printf("Printing an empty list:\n");
  printList(headOfList);
  printf("\n");


  printf("populating the list with the following numbers, in that order: 1 2 3 4 3 2 1\n\n");

  headOfList = insertAtFront(headOfList, 1);
  headOfList = insertAtFront(headOfList, 2);
  headOfList = insertAtFront(headOfList, 3);
  headOfList = insertAtFront(headOfList, 4);
  headOfList = insertAtFront(headOfList, 3);
  headOfList = insertAtFront(headOfList, 2);
  headOfList = insertAtFront(headOfList, 1);

  printf("printing list\n");
  printList(headOfList);
  printf("\n");

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
  return 0;
}
