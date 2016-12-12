#ifndef LIBRARY_DRIVER_H_
#define LIBRARY_DRIVER_H_

#include <string>
#include "Library.h"
#include "Song.h"


class libraryDriver{

public:
  bool addSong(string title, string artist, string album);
  void removeSong(unsigned int id){return libObj.removeSong(id);}
  bool playSong(unsigned int id, unsigned int times){return libObj.playSong(id, times);}
  void displayAllLibrary(string sortBy){libObj.libraryDisplayAll(sortBy);}
  bool addPlaylist(string plyTitle){return libObj.addPlaylist(plyTitle);}
  bool removePlaylist(string plyTitle){return libObj.removePlaylist(plyTitle);}
  void renamePlaylist(string oName, string nName){libObj.renamePlaylist(oName, nName);}
  void addSongPlaylist(string title, unsigned int id){libObj.addSongPlaylist(title, id);}
  void removeSongPlaylist(string title, unsigned int id){libObj.removeSongPlaylist(title, id);}
  void ratePlaylist(string plyTitle, unsigned int rate){libObj.ratePlaylist(plyTitle, rate);}
  //bool playlistPrintContents(string title){return libObj.songPlaylistPrint(title);}
  bool playlistExists(string title){return libObj.playlistExists(title);}
  bool songExists(unsigned int id){return libObj.songExists(id);}
  void printSongFromId(unsigned int id){libObj.printSongFromId(id);}
  void printSongFromId2(unsigned int id){libObj.printSongFromId2(id);}
  void displayAllPlaylists(){libObj.displayAllPlaylists();}
  void songPlaylistPrint(string title){libObj.songPlaylistPrint(title);}
private:
  Library libObj;
};



#endif // LIBRARY_DRIVER_H_