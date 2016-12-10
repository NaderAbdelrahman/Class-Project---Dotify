#ifndef PLAYLIST_CPP_
#define PLAYLIST_CPP_

#include "Playlist.h"

Playlist::Playlist(string title){
  playlistTitle = title;
}
void Playlist::addSong(unsigned int id){playlistVector.push_back(id);}
void Playlist::removeSong(unsigned int id){
  for (int i = 0; i < playlistVector.size(); ++i){
    if (playlistVector.at(i) == id){
      playlistVector.erase(playlistVector.begin() + i - 1);
    }
  }
}
void Playlist::playlistDisplayAll(){
  for (int i = 0; i < playlistVector.size(); ++i){
    Library::songPrint(playlistVector[i]);
  }
}
ostream& operator<<(ostream& os, const Playlist& playlist){
  os << "\"" << playlist.playlistTitle << "\" - Rating: "
  << playlist.playlistRating << " - " << playlist.playlistVector.size() << " songs" << endl;
  return os;
}
// void Playlist::ratePlaylist(unsigned int rating){
//   playlistRating = rating;
// }
#endif // PLAYLIST_CPP_