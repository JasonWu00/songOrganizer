struct node{
  char songName[100];
  char artist[100];
  struct node *nextNode;
};

void printList(struct node *headOfList);
struct node * insertAtFront(struct node *headOfList, char *newSong, char *newArtist);
struct node * freeList(struct node *headOfList);
struct node * removeNode(struct node *headOfList, char *targetSong, char *targetArtist);
void printSingleNode(struct node *headOfList); //helper function
