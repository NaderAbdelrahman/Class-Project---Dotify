#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include <iostream>

class Playlist{
public:
  Playlist(string title);
  void addSong(unsigned int id);
  void removeSong(unsigned int id);
  void renamePlaylist(string newTitle);
  bool operator==()
  friend
private:
  string playlistTitle;
  unsigned int playlistRating = 1; 
  vector<unsigned int> playlist; 

};
#endif // PLAYLIST_H_