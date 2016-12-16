#ifndef SONG_H_
#define SONG_H_

#include <iostream>
#include <string>

using namespace std;

class Song{
public:
  // Constructor, initializes a song's, title, artist, and album name
  Song(string songTitleSet, string artistNameSet, string albumTitleSet);
  friend ostream& operator<<(ostream& os, const Song& song);
  bool operator==(const Song& rhs);
  string songTitleGetter(){return songTitle;}
  string artistNameGetter(){return artistName;}
  string albumTitleGetter(){return albumTitle;}
private:
  string songTitle;
  string artistName;
  string albumTitle;
};

#endif // SONG_H_