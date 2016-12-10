#ifndef LIBRARY_CPP_
#define LIBRARY_CPP_

#include "Library.h"

bool Library::addSong(Song* aSong){
  if (songExists(aSong)){return false;}

  songWrapper *wrapper = new songWrapper;
  wrapper -> theSong = aSong;
  wrapper -> id = uniqueId;
  wrapper -> numberOfPlays = 0;
  library.insert({uniqueId, wrapper});
  ++uniqueId;
  return true;
    
}
bool Library::removeSong(unsigned int id){
  if (library.at(id) == NULL){return false;}
  delete library.at(id) -> theSong;
  delete library.at(id);
  library.erase(id);
  return true;
}
bool Library::playSong(unsigned int id, int ntimes){
  if (library.at(id) == NULL){return false;}
  unsigned int numberOfPlaysPrev;
  numberOfPlaysPrev = library.at(id) -> numberOfPlays;
  library.at(id) -> numberOfPlays += ntimes;
  cout << *(library.at(id) -> theSong) << " played successfully " << ntimes
  << " times (" << numberOfPlaysPrev << " plays -> "
  << library.at(id) -> numberOfPlays << " plays)." << endl;
  return true;
}
void Library::libraryDisplayAll(string organizeBy){
  if (library.empty()){
    cout << "You have no songs in your library." << endl;
    return;
  }
  if(organizeBy == "NAME"){
    vector<songWrapper*> temp;
    for (auto it = library.begin(); it != library.end(); ++it){
      temp.push_back(it -> second);
    }
    sort(temp.begin(), temp.end(), songTitleCompareFunction);
    for (unsigned int i = 0; i < temp.size(); ++i){
    cout << *temp.at(i);
    }
  }
  else if(organizeBy == "ARTIST"){
    vector<songWrapper*> temp;
    for (auto it = library.begin(); it != library.end(); ++it){
      temp.push_back(it -> second);
    }
    sort(temp.begin(), temp.end(), artistNameCompareFunction);
    for (unsigned int i = 0; i < temp.size(); ++i){
      cout << *temp.at(i);
    }
  }
  else if(organizeBy == "ALBUM"){
  vector<songWrapper*> temp;
    for (auto it = library.begin(); it != library.end(); ++it){
      temp.push_back(it -> second);
    }
    sort(temp.begin(), temp.end(), albumTitleCompareFunction);
    for (unsigned int i = 0; i < temp.size(); ++i){
      cout << *temp.at(i);
    }
  }
  else if(organizeBy == "PLAYS"){
  vector<songWrapper*> temp;
    for (auto it = library.begin(); it != library.end(); ++it){
      temp.push_back(it -> second);
    }
    sort(temp.begin(), temp.end(), numPlaysCompareFunction);
    for (unsigned int i = 0; i < temp.size(); ++i){
      cout << *temp.at(i);
    }
  }
  else{
    vector<songWrapper*> temp;
    for (auto it = library.begin(); it != library.end(); ++it){
      temp.push_back(it -> second);
    }
    sort(temp.begin(), temp.end(), songTitleCompareFunction);
    for (unsigned int i = 0; i < temp.size(); ++i){
      //cout << *(temp.at(i) -> theSong);
      cout << *temp.at(i);
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
bool Library::addPlaylist(string title){
  if (playlistExists(title)) {return false;}
  Playlist *p1 = new Playlist(title);
  playlistLibrary.insert({title, p1});
  return true;
}
bool Library::removePlaylist(string title){
  if (playlistExists(title)){
    delete playlistLibrary.at(title);
    playlistLibrary.erase(title);
    return true;
  }
  return false;
}
bool Library::renamePlaylist(string oldName, string newName){
  if(!playlistExists(oldName)){return false;}
  if(playlistExists(newName)){return false;}
  playlistLibrary.insert({newName, playlistLibrary.at(oldName)});
  playlistLibrary.at(newName) -> playlistTitleSetter(newName);
  playlistLibrary.erase(oldName);
  return true;
}
void Library::displayAllPlaylists(){
  vector<Playlist*> temp;
    for (auto it = playlistLibrary.begin(); it != playlistLibrary.end(); ++it){
      temp.push_back(it -> second);
    }
    sort(temp.begin(), temp.end(), playlistCompareFunction);
    for (unsigned int i = 0; i < temp.size(); ++i){
      cout << *temp.at(i);
    }
}
bool Library::playlistCompareFunction (Playlist* a, Playlist* b){
  if (a -> playlistRatingGetter() > b -> playlistRatingGetter()){return true;}
  else if(a -> playlistRatingGetter() == b -> playlistRatingGetter()){
    string a1, a2;
    a1 = a -> playlistTitleGetter();
    a2 = b -> playlistTitleGetter();
    transform(a1.begin(), a1.end(), a1.begin(), ::tolower);
    transform(a2.begin(), a2.end(), a2.begin(), ::tolower);
    if (a1 < a2){return true;}
  }
  else {return false;}
}
bool Library::ratePlaylist(string title, unsigned int rating){
  if (rating > 5 || rating <= 0){return false;}
  if(playlistExists(title)){
    playlistLibrary.at(title) -> playlistRatingSetter(rating);
    return true;
  }
  return false;
  
}
bool Library::songExists(Song* aSong){
  for(auto it = library.begin(); it != library.end(); ++it){
    if (*aSong == *(it -> second -> theSong)){return true;}
  }
  return false;
}
bool Library::playlistExists(string name){
  for(auto it = playlistLibrary.begin(); it != playlistLibrary.end(); ++it){
    if (name == it -> first){return true;}
  }
  return false;
}
void Library::songPrint(unsigned int id){
  cout << *(library.at(id) -> second); 
}

#endif // LIBRARY_CPP_