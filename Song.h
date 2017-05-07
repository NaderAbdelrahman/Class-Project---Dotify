#ifndef SONG_H_
#define SONG_H_

#include <iostream>
#include <string>

using namespace std;

class Song{
public:
  // Constructor, initializes a song's, title, artist, and album name
  Song(string songTitleSet, string artistNameSet, string albumTitleSet);
  // Overloading << operator (the operator that is used to cout and write to a file)
  // It is overloaded to take a Song object and print it in this format:
  // “Asymptote” by The Mathematicians (Differentials)
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