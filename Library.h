#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <unordered_map>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include "Library.h"
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
  void playSong(unsigned int id, int ntimes);
  unsigned int numberOfTimesPlaysGetter(unsigned int id){return library.at(id) -> numberOfPlays;}
  void libraryDisplayAll(string organizeBy);
  static bool songTitleCompareFunction (songWrapper* a, songWrapper* b);
  static bool artistNameCompareFunction (songWrapper* a, songWrapper* b);
  static bool albumTitleCompareFunction (songWrapper* a, songWrapper* b);
  static bool numPlaysCompareFunction (songWrapper* a, songWrapper* b);

private:
  // suggestion, trying making pair into a struct or something
  // in the struct we can just store the song and the number of 
  // plays and the unique id and in the key of the hashtable we can still use the unique id
  //unordered_map <int, pair <Song*, int> >;
  unordered_map <unsigned int, songWrapper*> library;
  unsigned int uniqueId = 0;
};

#endif // LIBRARY_H_