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
  delete library.at(id) -> theSong;
  delete library.at(id);
  library.erase(id);
}
void Library::playSong(unsigned int id, int ntimes){
  // Output like the spec
  library.at(id) -> numberOfPlays += ntimes;

}
void Library::libraryDisplayAll(string organizeBy){
  if(organizeBy == "NAME"){
    vector<songWrapper*> temp;
    for (auto it = library.begin(); it != library.end(); ++it){
      temp.push_back(it -> second);
    }
    sort(temp.begin(), temp.end(), songTitleCompareFunction);
    for (unsigned int i = 0; i < temp.size(); ++i){
      cout << *(temp.at(i) -> theSong);
    }
  }
  else if(organizeBy == "ARTIST"){
    vector<songWrapper*> temp;
    for (auto it = library.begin(); it != library.end(); ++it){
      temp.push_back(it -> second);
    }
    sort(temp.begin(), temp.end(), artistNameCompareFunction);
    for (unsigned int i = 0; i < temp.size(); ++i){
      cout << *(temp.at(i) -> theSong);
    }
  }
  else if(organizeBy == "ALBUM"){
  vector<songWrapper*> temp;
    for (auto it = library.begin(); it != library.end(); ++it){
      temp.push_back(it -> second);
    }
    sort(temp.begin(), temp.end(), albumTitleCompareFunction);
    for (unsigned int i = 0; i < temp.size(); ++i){
      cout << *(temp.at(i) -> theSong);
    }
  }
  else if(organizeBy == "PLAYS"){
  vector<songWrapper*> temp;
    for (auto it = library.begin(); it != library.end(); ++it){
      temp.push_back(it -> second);
    }
    sort(temp.begin(), temp.end(), numPlaysCompareFunction);
    for (unsigned int i = 0; i < temp.size(); ++i){
      cout << *(temp.at(i) -> theSong);
    }
  }
  else{
    vector<songWrapper*> temp;
    for (auto it = library.begin(); it != library.end(); ++it){
      temp.push_back(it -> second);
    }
    sort(temp.begin(), temp.end(), songTitleCompareFunction);
    for (unsigned int i = 0; i < temp.size(); ++i){
      cout << *(temp.at(i) -> theSong);
    }
  }
}
bool Library::songTitleCompareFunction(songWrapper* a, songWrapper* b){
  string a1, b1;
  a1 = a -> theSong -> songTitleGetter();
  transform(a1.begin(), a1.end(), a1.begin(), ::tolower);
  b1 = b -> theSong -> songTitleGetter();
  transform(b1.begin(), b1.end(), b1.begin(), ::tolower);
  return a1 < b1;
}
bool Library::artistNameCompareFunction(songWrapper* a, songWrapper* b){
  string a1, b1;
  a1 = a -> theSong -> artistNameGetter();
  transform(a1.begin(), a1.end(), a1.begin(), ::tolower);
  b1 = b -> theSong -> artistNameGetter();
  transform(b1.begin(), b1.end(), b1.begin(), ::tolower);
  return a1 < b1;
}
bool Library::albumTitleCompareFunction(songWrapper* a, songWrapper* b){
  string a1, b1;
  a1 = a -> theSong -> albumTitleGetter();
  transform(a1.begin(), a1.end(), a1.begin(), ::tolower);
  b1 = b -> theSong -> albumTitleGetter();
  transform(b1.begin(), b1.end(), b1.begin(), ::tolower);
  return a1 < b1;
}
bool Library::numPlaysCompareFunction(songWrapper* a, songWrapper* b){
  return a -> numberOfPlays < b -> numberOfPlays;
}

#endif // LIBRARY_CPP_