struct node{
  char songName[100];
  char artist[100];
  struct node *nextNode;
};

void printList(struct node *headOfList);
struct node * insertAtFront(struct node *headOfList, char *newSong, char *newArtist);
struct node * freeList(struct node *headOfList);
struct node * removeNode(struct node *headOfList, const char *targetSong, const char *targetArtist);
struct node *findSong(struct node *no, char *search);
struct node *findSongByArtist(struct node *no, char *search);
struct node *randomSong(struct node *no);
void printSingleNode(struct node *headOfList); //helper function
