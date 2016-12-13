#ifndef LIBRARY_DRIVER_H_
#define LIBRARY_DRIVER_H_

#include <string>
#include <fstream>
#include "Library.h"
#include "Song.h"


class libraryDriver{

public:
  bool addSong(string title, string artist, string album);
  bool addSong(string title, string artist, string album, int nplays, int id);
  bool songExists(string title, string artist, string album);
  void removeSong(unsigned int id);
  bool playSong(unsigned int id, unsigned int times){return libObj.playSong(id, times);}
  void displayAllLibrary(string sortBy){libObj.libraryDisplayAll(sortBy);}
  bool songExists(unsigned int id){return libObj.songExists(id);}
  void printSongFromId(unsigned int id){libObj.printSongFromId(id);}
  void printSongFromId2(unsigned int id){libObj.printSongFromId2(id);}
  bool addPlaylist(string title);
  bool removePlaylist(string title);
  void renamePlaylist(string oldName, string newName);
  static bool playlistCompareFunction (Playlist* a, Playlist* b);
  void displayAllPlaylists();
  void ratePlaylist(string title, unsigned int rating);
  bool playlistExists(string name);
  void songPlaylistPrint(string title);
  void addSongPlaylist(string title, unsigned int id);
  void removeSongPlaylist(string title, unsigned int id);
  void loadLibrary(string filename, bool playlist);
  void loadPlaylists(string filename);
  unsigned int songToId(string title, string artist, string album);
private:
  Library libObj;
  unordered_map <string, Playlist*> playlistLibrary;
};



#endif // LIBRARY_DRIVER_H_