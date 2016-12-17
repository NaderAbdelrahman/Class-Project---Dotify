#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Song.h"
#include "Playlist.h"

using namespace std;

struct songWrapper{
  Song* theSong;
  unsigned int numberOfPlays;
  unsigned int id;
  friend ostream& operator<<(ostream& os, const songWrapper& wrapper){
    os << *wrapper.theSong << " - " << wrapper.numberOfPlays
    << " plays [#" << wrapper.id << "]" << endl;
    return os;
  }
};

class Library{
public:
  bool addSong(Song* aSong);
  bool addSong(Song* aSong, int nplay, int id);
  void removeSong(unsigned int id);
  bool playSong(unsigned int id, unsigned int ntimes);
  void libraryDisplayAll(string organizeBy);
  unsigned int numberOfTimesPlaysGetter(unsigned int id){return library.at(id) -> numberOfPlays;}
  static bool songTitleCompareFunction (songWrapper* a, songWrapper* b);
  static bool artistNameCompareFunction (songWrapper* a, songWrapper* b);
  static bool albumTitleCompareFunction (songWrapper* a, songWrapper* b);
  static bool numPlaysCompareFunction (songWrapper* a, songWrapper* b);
  bool songExists(Song* aSong);
  bool songExists(unsigned int id);
  void printSongFromId(unsigned int id);
  void printSongFromIdBasic(unsigned int id);
  unsigned int findId(Song* aSong);
  void printSongFromId2(unsigned int id);
  unsigned int returnValidId();
  void exportLibrary(string nameOfFile);
  void exportPlaylistSongFromId(ostream& write, unsigned int id);
  vector<unsigned int> returnIdsFromSongName(string name);
  vector<unsigned int> returnIdsFromArtistName(string name);
  vector<unsigned int> returnIdsFromAlbumName(string name);
  vector<unsigned int> magic();
private:
  unordered_map <unsigned int, songWrapper*> library;
  unsigned int uniqueId = 1;
};

#endif // LIBRARY_H_