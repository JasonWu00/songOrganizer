#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "nodes.h"
#include "library.h"

int main() {
  srand(time(NULL));
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

  struct node * table[27];

  printf("Printing empty library of lists (nothing will print)\n");
  printEntireLibrary();

  printf("Populating the library of lists\n\n");

  addSong("Tears in Heaven", "Eric Clapton");
  addSong("Stairway to Heaven", "Led Zeppelin");
  addSong("Highway to Hell", "ACDC");
  addSong("Crossroads", "Eric Clapton");
  addSong("Hey Jude", "The Beatles");
  addSong("Coda", "Led Zeppelin");
  addSong("I Wanna Hold Your Hand", "The Beatles");

  printf("Printing populated library\n");
  printEntireLibrary();

  printf("-----Testing find song, find artist-----\n");
  printf("-----and print songs by artists starting with specifc letter-----\n\n");

  printf("Finding song \"I Wanna Hold Your Hand\" by \"The Beatles\"\n");
  printSingleNode(searchSong("I Wanna Hold Your Hand", "The Beatles"));
  printf("\n\n");

  printf("Finding all songs by artist \"Led Zeppelin\"\n");
  printSongsByArtist("Led Zeppelin");
  printf("\n");

  printf("Printing all songs with artists starting with E\n");
  printLetter("E");
  printf("\n\n");

  printf("-----Testing shuffle-----\n\n");

  printf("Printing out a random shuffle that contains all the songs in the library:\n");
  printf("(The method uses a linked list to store the shuffled songs.) \n(The list will be freed after printing.)\n");
  printShuffle();
  printf("\n");

  printf("-----Testing removing single node-----\n\n");
  printf("Removing song \"Highway to Hell\" by \"ACDC\"\n");
  removeSong("Highway to Hell", "ACDC");
  printf("Song removed, now printing list\n\n");
  printEntireLibrary();

  printf("-----Testing clearing library-----\n\n");
  clearLib();
  printf("Library cleared, now printing library (nothing will print)\n");
  printEntireLibrary();
  printf("\n");


  /*
  */
  return 0;
}
