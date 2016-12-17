#ifndef PLAYLIST_CPP_
#define PLAYLIST_CPP_

#include "Playlist.h"

Playlist::Playlist(string title){
  playlistTitle = title;
}
// Pushes back a songs ID into the vector
// Worst case O(1)
void Playlist::addSong(unsigned int id){playlistVector.push_back(id);}
// Removes a songs ID from the vector
// Worst case O(n) [has to check every value in the vector]
bool Playlist::removeSong(unsigned int id){
  for (auto it = playlistVector.begin(); it < playlistVector.end(); ++it){
    if (*it == id){
      playlistVector.erase(it);
      return true;
    }
  }
  return false;
}
// << overloaded to output Playlist object in this format:
// “Happy Dance” – Rating: 5 – 25 songs
ostream& operator<<(ostream& os, const Playlist& playlist){
  os << "\"" << playlist.playlistTitle << "\" - Rating: "
  << playlist.playlistRating << " - " << playlist.playlistVector.size() << " songs" << endl;
  return os;
}

#endif // PLAYLIST_CPP_