struct node{
  char songName[100];
  struct node *nextNode;
};

void printList(struct node *headOfList);
struct node * insertAtFront(struct node *headOfList, char *cargo);
struct node * freeList(struct node *headOfList);
struct node * removeNode(struct node *headOfList, char *target);
void printSingleNode(struct node *headOfList); //helper function
