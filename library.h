struct node * table[27];

int nthLetter(char *string);
void printEntireLibrary();
struct node * addSong(char *songName, char *artist);
struct node * searchSong(char *songToFind, char *artistoFind);
//struct node * searchArtist(char *artistToFind);
void printLetter(char *letter);
void printArtist(char *art);
void printSongsByArtist(char *artistToFind);
void printLib();
struct node * removeSong(char *songName, char *artistName);
struct node * clearLib();
void printShuffle();
