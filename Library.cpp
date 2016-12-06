#ifndef LIBRARY_CPP_
#define LIBRARY_CPP_

#include "Library.h"

bool Library::addSong(Song* aSong){
  ++uniqueIdentifier;
  // We return this so that it can tell the function whether the insert was sucessful or not
  return unordered_map.insert(uniqueIdentifier, make_pair(aSong, 0));
}
Song* Library::removeSong(unsigned int id){
  // Does this so that the library driver class can delete the pointer
  return data -> first; // or instead of first, simply, x;
}
bool Library::playSong(int id, int ntimes){
  // Output like the spec

}

#endif // LIBRARY_CPP_