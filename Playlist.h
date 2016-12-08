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
  void renamePlaylist(string newTitle);
  void playlistDisplayAll();
  // the reason why I dont need to overload the == operator
  // is because when we store the playlists in to the hashtable
  // using the name as the key (becaus it is unique among all playlists)
  // we can just search the hastable to se if the playlist name exists
  //bool operator==(Playlist& rhs);
  // for overloading the << we can just implement a function that can do this instead
  // friend operator<<()
private:
  string playlistTitle;
  unsigned int playlistRating = 1; 
  vector<unsigned int> playlist; 

};
#endif // PLAYLIST_H_