#ifndef SONG_CPP_
#define SONG_CPP_

#include "Song.h"

Song::Song(string songTitleSet, string artistNameSet, string albumTitleSet){
  songTitle = songTitleSet;
  artistName = artistNameSet;
  albumTitle = albumTitleSet;
}
ostream& operator<<(ostream& os, const Song& song){
  os << "\"" <<song.songTitle << "\" by " << song.artistName << " (" << song.albumTitle << ")" << endl;
  return os;
}
bool Song::operator==(const Song& rhs){
  return songTitle == rhs.songTitle && artistName == rhs.artistName && albumTitle == rhs.albumTitle;
}


#endif // SONG_CPP_