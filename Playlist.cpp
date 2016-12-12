#ifndef PLAYLIST_CPP_
#define PLAYLIST_CPP_

#include "Playlist.h"

Playlist::Playlist(string title){
  playlistTitle = title;
}
void Playlist::addSong(unsigned int id){playlistVector.push_back(id);}
bool Playlist::removeSong(unsigned int id){
  for (auto it = playlistVector.begin(); it < playlistVector.end(); ++it){
    if (*it == id){
      playlistVector.erase(it);
      return true;
    }
  }

  return false;
}
ostream& operator<<(ostream& os, const Playlist& playlist){
  os << "\"" << playlist.playlistTitle << "\" - Rating: "
  << playlist.playlistRating << " - " << playlist.playlistVector.size() << " songs" << endl;
  return os;
}

#endif // PLAYLIST_CPP_