#ifndef PLAYLIST_CPP_
#define PLAYLIST_CPP_

#include "Playlist.h"

Playlist::Playlist(string title){
  playlistTitle = title;
}
void Playlist::addSong(unsigned int id){
  playlist.push_back(id);

}
void Playlist::removeSong(unsigned int id){
  for (int i = 0; i < playlist.size(); ++i){
    if (playlist.at(i) == id){
      playlist.erase(playlist.begin() + i - 1);
    }
  }
}
void Playlist::renamePlaylist(string newTitle){
  playlistTitle = newTitle;
}
void Playlist::playlistDisplayAll(){
  for (int i = 0; i < playlist.size(); ++i){

  }
}
// bool Playlist::operator==(Playlist& rhs){
//   return playlistTitle == rhs.playlistTitle;
// }

#endif // PLAYLIST_CPP_