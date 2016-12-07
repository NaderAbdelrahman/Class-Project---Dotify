#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <unordered_map>
#include <utility>
#include <string>
#include "Song.h"

using namespace std;

struct songWrapper{
  Song* theSong;
  unsigned int numberOfPlays;
  unsigned int id;
};

class Library{

public:
  void addSong(Song* aSong);
  void removeSong(unsigned int id);
  void playSong(int id, int ntimes);
private:
  // suggestion, trying making pair into a struct or something
  // in the struct we can just store the song and the number of 
  // plays and the unique id and in the key of the hashtable we can still use the unique id
  //unordered_map <int, pair <Song*, int> >;
  unordered_map <unsigned int, songWrapper*> library;
  unsigned int uniqueId = 0;
};

#endif // LIBRARY_H_