#ifndef LIBRARY_DRIVER_H_
#define LIBRARY_DRIVER_H_

#include <string>
#include "Library.h"
#include "Song.h"


class libraryDriver{

public:
  //libraryDriver(){Library libObj;}
  bool addSong(string title, string artist, string album);
  bool removeSong(unsigned int id){return libObj.removeSong(id);}
  bool playSong(unsigned int id, unsigned int times){return libObj.playSong(id, times);}
  void displayAllLibrary(string sortBy){libObj.libraryDisplayAll(sortBy);}
  bool addPlaylist(string plyTitle){return libObj.addPlaylist(plyTitle);}
  bool removePlaylist(string plyTitle){return libObj.removePlaylist(plyTitle);}
  bool renamePlaylist(string oName, string nName){return libObj.renamePlaylist(oName, nName);}
  void addSongPlaylist(string title, unsigned int id){libObj.addSongPlaylist(title, id);}
  void removeSongPlaylist(string title, unsigned int id){libObj.removeSongPlaylist(title, id);}
  bool ratePlaylist(string plyTitle, unsigned int rate){return libObj.ratePlaylist(plyTitle, rate);}
  bool playlistPrintContents(string title){return libObj.songPlaylistPrint(title);}
private:
  Library libObj;
};



#endif // LIBRARY_DRIVER_H_