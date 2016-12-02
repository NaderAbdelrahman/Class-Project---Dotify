#ifndef SONG_H_
#define SONG_H_

#include <iostream>
#include <string>

using namespace std;

class Song{

public:
  // Default constructor
  Song(){};
  // In cpp initialize numberOfPlays to 0
  // Figure out uniqueIdentifier
  // Constructor, initializes a song's, title, artist, and album
  Song(string songTitleSet, string artistNameSet, string albumTitleSet){};


private:
  string songTitle;
  string artistName;
  string albumTitle;
  unsigned int numberOfPlays;
  unsigned int uniqueIdentifier;
};


#endif // SONG_H_