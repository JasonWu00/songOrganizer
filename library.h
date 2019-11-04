struct node * table[27];

int nthLetter(char *string);
void printEntireLibrary();
struct node * addSong(char *songName, char *artist);
struct node * searchSong(char *sn, char *art);
int searchArtist(char *art);
void printLetter(char let);
void printArtist(char *art);
void printLib();
struct node * removeSong(char *sn);
struct node * clearLib();
