#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
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
  bool removeSong(unsigned int id);
  bool playSong(unsigned int id, unsigned int ntimes);
  void libraryDisplayAll(string organizeBy);
  bool addPlaylist(string title);
  bool removePlaylist(string title); 
  bool renamePlaylist(string oldName, string newName);
  void displayAllPlaylists();
  unsigned int numberOfTimesPlaysGetter(unsigned int id){return library.at(id) -> numberOfPlays;}
  static bool songTitleCompareFunction (songWrapper* a, songWrapper* b);
  static bool artistNameCompareFunction (songWrapper* a, songWrapper* b);
  static bool albumTitleCompareFunction (songWrapper* a, songWrapper* b);
  static bool numPlaysCompareFunction (songWrapper* a, songWrapper* b);
  static bool playlistCompareFunction (Playlist* a, Playlist* b);
  bool ratePlaylist(string title, unsigned int rating);
  bool songExists(Song* aSong);
  bool songExists(unsigned int id);
  bool playlistExists(string name);
  bool songPlaylistPrint(string title);
  void printSongFromId(unsigned int id);
  void addSongPlaylist(string title, unsigned int id);
  void removeSongPlaylist(string title, unsigned int id);
  unsigned int findId(Song* aSong);
private:
  unordered_map <unsigned int, songWrapper*> library;
  unsigned int uniqueId = 0;
  unordered_map <string, Playlist*> playlistLibrary;
};

#endif // LIBRARY_H_