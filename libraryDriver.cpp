#ifndef LIBRARY_DRIVER_CPP_
#define LIBRARY_DRIVER_CPP_

#include "libraryDriver.h"
// Makes pointer to song object and passes it a title, artist, and album
// if addSong returns false that means that it already exists
// so it deletes the song pointer it just made and returns false
bool libraryDriver::addSong(string title, string artist, string album){
  Song *song = new Song(title, artist, album);
  if(!libObj.addSong(song)){
    delete song;
    return false;
  }
  return true;
}
// addSong used by import function
bool libraryDriver::addSong(string title, string artist, string album, int nplays, int id){
  Song *song = new Song(title, artist, album);
  return libObj.addSong(song, nplays, id);
}
// Passes the songs id to library's removeSong func
// Then deletes all ids of the song to be deleted in all playlists
// At the same time it removes the song from the playlists
// it dumps the names of the playlists the song was deleted from into
// a vector, in order to print the the playlists the song was removed from
void libraryDriver::removeSong(unsigned int id){
  libObj.removeSong(id);
  vector<string> temp;
  for(auto it = playlistLibrary.begin(); it != playlistLibrary.end(); ++it){
    if(it -> second -> removeSong(id)){
        temp.push_back(it -> first);
    }
  }
  if(!temp.empty()){
    cout << "and from playlists ";
    for(unsigned int i = 0; i < temp.size(); ++i){
      cout << "\"" << temp[i] << "\", ";
    }
    temp.clear();
    cout << endl << "> ";
  }
}
// Checks if the playlist exists
// makes a pointer to a Playlist object
// then adds it to a map based on it's title
bool libraryDriver::addPlaylist(string title){
  if (playlistExists(title)) {return false;}
  Playlist *p1 = new Playlist(title);
  playlistLibrary.insert({title, p1});
  return true;
}
// Checks if the playlist exists
// Deletes the pointer in the map
// Then removes the entry from the map
bool libraryDriver::removePlaylist(string title){
  if (playlistExists(title)){
    delete playlistLibrary.at(title);
    playlistLibrary.erase(title);
    return true;
  }
  return false;
}
// Makes a new playlist based on the new name
// Copies the pointer from the old playlist to the new playlist
// Then removes the old playlist from the map
void libraryDriver::renamePlaylist(string oldName, string newName){
  playlistLibrary.insert({newName, playlistLibrary.at(oldName)});
  playlistLibrary.at(newName) -> playlistTitleSetter(newName);
  playlistLibrary.erase(oldName);
  cout << "\"" << oldName << "\"" << " playlist renamed successfully to \"" << newName << "\"." << endl << "> ";
  return;
}
bool libraryDriver::playlistCompareFunction (Playlist* a, Playlist* b){
  // If the rating of a is greater than b return true
  // I ask if it is greater because I want
  // higher numbers to be higher on the list
  if (a -> playlistRatingGetter() > b -> playlistRatingGetter()){return true;}
  // If the ratings are the same, dump strings to temporary strings for sorting
  // I transform the strings to lowercase that way I don't have issues with ACII values
  else if(a -> playlistRatingGetter() == b -> playlistRatingGetter()){
    string a1, a2;
    a1 = a -> playlistTitleGetter();
    a2 = b -> playlistTitleGetter();
    transform(a1.begin(), a1.end(), a1.begin(), ::tolower);
    transform(a2.begin(), a2.end(), a2.begin(), ::tolower);
    // If the value of string a1 is less than string a2 return true
    if (a1 < a2){return true;}
    else{return false;}
  }
  // Else they are not sorted, return false
  else {return false;}
}
void libraryDriver::displayAllPlaylists(){
  vector<Playlist*> temp;
  // If the map is empty, there are no playlists
  if(playlistLibrary.size() == 0){
    cout << "You have no playlists." << endl << "> ";
    return;
  }
  // Dumping map into vector for sorting
  for (auto it = playlistLibrary.begin(); it != playlistLibrary.end(); ++it){
    temp.push_back(it -> second);
  }
  // Sorting vector by rating then title using playlistCompareFunction
  sort(temp.begin(), temp.end(), playlistCompareFunction);
  for (unsigned int i = 0; i < temp.size(); ++i){
    cout << i + 1 << ". " <<  *temp.at(i);
  }
  cout << "> ";
}
void libraryDriver::ratePlaylist(string title, unsigned int rating){
  playlistLibrary.at(title) -> playlistRatingSetter(rating);
  return;  
}
// Iterates through the map and checks if it exists
// worst case O(n)
bool libraryDriver::playlistExists(string name){
  for(auto it = playlistLibrary.begin(); it != playlistLibrary.end(); ++it){
    if (name == it -> first){return true;}
  }
  return false;
}
void libraryDriver::songPlaylistPrint(string title){
  if(playlistLibrary.at(title) -> playlistVectorSize() == 0){
    cout << "\"" << title << "\" playlist has no songs." << endl << "> ";
    return;
  }
  // Calls printSongFromId function for every song in the playlist
  for(unsigned int i = 0; i <  playlistLibrary.at(title) -> playlistVectorSize(); ++i){
    cout << i + 1 << ". ";
    printSongFromId(playlistLibrary.at(title) -> playlistElementFetcher(i));
  }
  cout << "> ";
  return;
}
void libraryDriver::addSongPlaylist(string title, unsigned int id){
 playlistLibrary.at(title) -> addSong(id);
}
void libraryDriver::removeSongPlaylist(string title, unsigned int id){
  playlistLibrary.at(title) -> removeSong(id);
}
void libraryDriver::loadLibrary(string filename, bool playlist){
  ifstream load;
  string title, artist, album, tmp, nplays, id;
  int plays, ID;
  load.open(filename);
  if(load.fail()){
    cout << "Could not load library from \'" << filename << "\". Skipping." << endl;
    return;
  }
  cout << "Loading library from \"" << filename << "\"." << endl;
  // Keep reading the untill the end of the file
  while(getline(load, title, '|')){
    getline(load, artist, '|');
    getline(load, album, '|');
    getline(load, nplays, '|');
    getline(load, id);
    plays = stoi(nplays);
    ID = stoi(id);
    addSong(title, artist, album, plays, ID);
  }
  load.close();
  if(!playlist){cout << "No playlists file provided." << endl; }
}
void libraryDriver::loadPlaylists(string filename){
  ifstream load;
  load.open(filename);
  if(load.fail()){
    cout << "Could not load playlists from \'" << filename << "\". Skipping." << endl;
    return;
  }
  cout << "Loading playlists from \"" << filename << "\"." << endl;
  string title, plytitle, rating, nsongs, artist, album;
  while(getline(load, plytitle, '|')){
    int numsongs, rate;
    getline(load, rating, '|');
    getline(load, nsongs);
    numsongs = stoi(nsongs);
    rate = stoi(rating);
    addPlaylist(plytitle);
    ratePlaylist(plytitle, rate);
    for(int i = 0; i < numsongs; ++i){
      getline(load, title, '|');
      getline(load, artist, '|');
      getline(load, album);
      if(!songExists(title, artist, album)){
        cout << "Could not find song in library: "
        << "\"" << title << "|" << artist << "|" << album << "\"" << endl;
      }
      else{
        addSongPlaylist(plytitle, songToId(title, artist, album));
      }
    }
  }
}
bool libraryDriver::songExists(string title, string artist, string album){
  Song *song = new Song(title, artist, album);
  if(libObj.songExists(song)){
    delete song;
    return true;
  }
  else{
    delete song;

    return false;
  }
}
// Makes a pointer to a Song obj
// if the song exists, find the songs id and temporarily store it
// delete the pointer and return the value
unsigned int libraryDriver::songToId(string title, string artist, string album){
  Song *song = new Song(title, artist, album);
  if(libObj.songExists(song)){
    unsigned int tmp;
    tmp = libObj.findId(song);
    delete song;
    return tmp;
  }
}
void libraryDriver::exportPlaylist(string nameOfFile){
  ofstream write;
  write.open(nameOfFile);
  for(auto it = playlistLibrary.begin(); it != playlistLibrary.end(); ++it){
    write << it -> second -> playlistTitleGetter() << "|"
    << it -> second -> playlistRatingGetter() << "|"
    << it -> second -> playlistVectorSize() << endl;
    for (unsigned int i = 0; i < it -> second-> playlistVectorSize(); ++i){
      libObj.exportPlaylistSongFromId(write, it -> second -> playlistElementFetcher(i));
    }
  }
}
void libraryDriver::autogenerate(string name){
  if(name == "NAME"){
    cout << "What is the song name you’d like to autogenerate a playlist from?" << endl << "> ";
    string title;
    getline(cin, title);
    if(!addPlaylist(title)){
      cout << "\"" << title << "\" playlist already exists." << endl << "> ";
      return;
    }
    vector<unsigned int> tmp = libObj.returnIdsFromSongName(title);
    for(unsigned int i = 0; i < tmp.size(); ++i){
      addSongPlaylist(title, tmp[i]);
    }
    cout << "\"" << title << "\" " << "playlist autogenerated successfully." << endl << "> ";
    return;
  }
  if(name == "ARTIST"){
    cout << "Who is the song artist you’d like to autogenerate a playlist from?" << endl << "> ";
    string title;
    getline(cin, title);
    if(!addPlaylist(title)){
      cout << "\"" << title << "\" playlist already exists." << endl << "> ";
      return;
    }
    vector<unsigned int> tmp = libObj.returnIdsFromArtistName(title);
    for(unsigned int i = 0; i < tmp.size(); ++i){
      addSongPlaylist(title, tmp[i]);
    }
    cout << "\"" << title << "\" " << "playlist autogenerated successfully." << endl << "> ";
    return;
  }
  if(name == "ALBUM"){
    cout << "What is the song album you’d like to autogenerate a playlist from?" << endl << "> ";
    string title;
    getline(cin, title);
    if(!addPlaylist(title)){
      cout << "\"" << title << "\" playlist already exists." << endl << "> ";
      return;
    }
    vector<unsigned int> tmp = libObj.returnIdsFromAlbumName(title);
    for(unsigned int i = 0; i < tmp.size(); ++i){
      addSongPlaylist(title, tmp[i]);
    }
    cout << "\"" << title << "\" " << "playlist autogenerated successfully." << endl << "> ";
    return;
  }
  if(name == "MAGIC"){
    if(playlistExists("AUTOGENERATED")){
      cout << "\"AUTOGENERATED\" playlist already exists." << endl << "> ";
      return;
    }
    vector<unsigned int> tmp = libObj.magic();
    if(tmp.size() > 0){
      addPlaylist("AUTOGENERATED");
      for(unsigned int i = 0; i < tmp.size(); ++i){
        addSongPlaylist("AUTOGENERATED", tmp[i]);
      }
      cout << "\"" << "AUTOGENERATED" << "\" " << "playlist autogenerated successfully." << endl << "> ";
      return;
    }
  }
  else{
    cout << "\"" << name << "\" is not a valid criterion to autogenerate a playlist with." << endl << "> ";
  }
}

#endif // LIBRARY_DRIVER_CPP_