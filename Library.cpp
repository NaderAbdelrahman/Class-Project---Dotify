#ifndef LIBRARY_CPP_
#define LIBRARY_CPP_

#include "Library.h"

bool Library::addSong(Song* aSong){
  if (songExists(aSong)){
    cout << *aSong << ", identified as #" << findId(aSong)
    << ", already exists in your library." << endl << "> ";
    return false;
  }
  songWrapper *wrapper = new songWrapper;
  wrapper -> theSong = aSong;
  wrapper -> id = uniqueId;
  wrapper -> numberOfPlays = 0;
  library.insert({uniqueId, wrapper});
  cout << *aSong << ", identified as #" << uniqueId
    << ", purchased successfully to your library." << endl << "> ";
  ++uniqueId;
  return true;
    
}
void Library::removeSong(unsigned int id){

  if (!songExists(id)){
    cout << "No song with identifier #" << id <<" exists in your library." << endl << "> ";
    return;
  }
  vector<string> temp;
  cout << *(library.at(id) -> theSong) << ", identified as #" << library.at(id) -> id << " removed successfully from your library" << endl << "> ";
  for(auto it = playlistLibrary.begin(); it != playlistLibrary.end(); ++it){
    if(it -> second -> removeSong(id)){
        temp.push_back(it -> first);
      }
  }
  if(!temp.empty()){
    cout << "and from playlists ";
    for(unsigned int i = 0; i < temp.size(); ++i){
      cout << temp[i] << ", ";
    }
  }
  delete library.at(id) -> theSong;
  delete library.at(id);
  library.erase(id);
}
bool Library::playSong(unsigned int id, unsigned int ntimes){
  unsigned int numberOfPlaysPrev;
  numberOfPlaysPrev = library.at(id) -> numberOfPlays;
  library.at(id) -> numberOfPlays += ntimes;
  cout << *(library.at(id) -> theSong) << " played successfully " << ntimes
  << " times (" << numberOfPlaysPrev << " plays -> "
  << library.at(id) -> numberOfPlays << " plays)." << endl << "> ";
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
void Library::renamePlaylist(string oldName, string newName){
  playlistLibrary.insert({newName, playlistLibrary.at(oldName)});
  playlistLibrary.at(newName) -> playlistTitleSetter(newName);
  playlistLibrary.erase(oldName);
  cout << "\"" << oldName << "\"" << " playlist renamed successfully to \"" << newName << "\"." << endl << "> ";
  return;
}
void Library::displayAllPlaylists(){
  vector<Playlist*> temp;
  if(playlistLibrary.size() == 0){
    cout << "You have no playlists." << endl << "> ";
    return;
  }
  for (auto it = playlistLibrary.begin(); it != playlistLibrary.end(); ++it){
    temp.push_back(it -> second);
  }
  sort(temp.begin(), temp.end(), playlistCompareFunction);
  for (unsigned int i = 0; i < temp.size(); ++i){
    cout << i + 1 << ". " <<  *temp.at(i);
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
void Library::ratePlaylist(string title, unsigned int rating){
  playlistLibrary.at(title) -> playlistRatingSetter(rating);
  return;  
}
bool Library::songExists(Song* aSong){
  for(auto it = library.begin(); it != library.end(); ++it){
    if (*aSong == *(it -> second -> theSong)){return true;}
  }
  return false;
}
bool Library::songExists(unsigned int id){
  for(auto it = library.begin(); it != library.end(); ++it){
    if (id == it -> first){return true;}
  }
  return false;
}
bool Library::playlistExists(string name){
  for(auto it = playlistLibrary.begin(); it != playlistLibrary.end(); ++it){
    if (name == it -> first){return true;}
  }
  return false;
}
void Library::songPlaylistPrint(string title){
  if(playlistLibrary.at(title) -> playlistVectorSize() == 0){
    cout << "\"" << title << "\" playlist has no songs." << endl << "> ";
    return;
  }
  for(unsigned int i = 0; i <  playlistLibrary.at(title) -> playlistVectorSize(); ++i){
    cout << i + 1 << ". ";
    printSongFromId(playlistLibrary.at(title) -> playlistElementFetcher(i));
  }
  return;
}
void Library::printSongFromId(unsigned int id){
  cout << *(library.at(id)) << endl;
}
void Library::addSongPlaylist(string title, unsigned int id){
 playlistLibrary.at(title) -> addSong(id);
}
void Library::removeSongPlaylist(string title, unsigned int id){
  playlistLibrary.at(title) -> removeSong(id);
}
unsigned int Library::findId(Song* aSong){
  for(auto it = library.begin(); it != library.end(); ++it){
    if (*aSong == *(it -> second -> theSong)){return it -> first;}
  }
}
void Library::printSongFromId2(unsigned int id){
  cout << "\"" << library.at(id) -> theSong -> songTitleGetter() << "\" by "
  << library.at(id) -> theSong -> artistNameGetter()
  << " (" << library.at(id) -> theSong -> albumTitleGetter()
  << "), identified as #" << id;
}

#endif // LIBRARY_CPP_