#ifndef LIBRARY_CPP_
#define LIBRARY_CPP_

#include "Library.h"
#include "Song.h"

void Library::addSong(Song* aSong){
  ++uniqueId;
  // We return this so that it can tell the function whether the insert was sucessful or not
  //return unordered_map.insert(uniqueIdentifier, make_pair(aSong, 0));

  songWrapper *wrapper = new songWrapper;
  wrapper -> theSong = aSong;
  wrapper -> id = uniqueId;
  wrapper -> numberOfPlays = 0;
  library.insert({uniqueId, wrapper});
}
void Library::removeSong(unsigned int id){
  // Does this so that the library driver class can delete the pointer
  //return data -> first; // or instead of first, simply, x;
  // DONT FORGET TO DELETE
  delete library.at(id);
  library.erase(id);
}
void Library::playSong(int id, int ntimes){
  // Output like the spec
  library.at(id)-> numberOfPlays = ntimes;

}

#endif // LIBRARY_CPP_