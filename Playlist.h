#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Playlist{
public:
  Playlist(string title);
  void addSong(unsigned int id);
  void removeSong(unsigned int id);
  void playlistDisplayAll();
  // void playlistTitleSetter(string title){playlistTitle = title;}
  // string playlistTitleGetter(){return playlistTitle;}
  // void playlistRatingSetter(unsigned int rating){playlistRating = rating;}
  // unsigned int playlistRatingGetter(){return playlistRating;}
  friend ostream& operator<<(ostream& os, const Playlist& playlist);
private:
  string playlistTitle;
  unsigned int playlistRating = 1; 
  vector<unsigned int> playlistVector;
};
#endif // PLAYLIST_H_