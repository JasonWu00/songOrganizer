struct node{
  int data;
  struct node *nextNode;
};

void printList(struct node *headOfList);
struct node * insertAtFront(struct node *headOfList, int cargo);
struct node * freeList(struct node *headOfList);
struct node * removeNode(struct node *headOfList, int target);
void printSingleNode(struct node *headOfList); //helper function
