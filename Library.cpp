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
  wrapper -> id = returnValidId();
  wrapper -> numberOfPlays = 0;
  library.insert({uniqueId, wrapper});
  cout << *aSong << ", identified as #" << uniqueId
    << ", purchased successfully to your library." << endl << "> ";
  return true;
}
unsigned int Library::returnValidId(){
  while(library.count(uniqueId) == 1){
    ++uniqueId;
  }
  return uniqueId;
}
// Used when adding from file
bool Library::addSong(Song* aSong, int nplay, int id){
  songWrapper *wrapper = new songWrapper;
  wrapper -> theSong = aSong;
  wrapper -> id = id;
  wrapper -> numberOfPlays = nplay;
  library.insert({id, wrapper});
  return true;
}
void Library::removeSong(unsigned int id){
  if (!songExists(id)){
    cout << "No song with identifier #" << id <<" exists in your library." << endl << "> ";
    return;
  }
    cout << *(library.at(id) -> theSong) << ", identified as #" << library.at(id) -> id << " removed successfully from your library " << endl;
    // Must deleted the pointer to the Song object that the wrapper makes
    // and the song wrapper pointer itself
    delete library.at(id) -> theSong;
    delete library.at(id);
    library.erase(id);}
bool Library::playSong(unsigned int id, unsigned int ntimes){
  unsigned int numberOfPlaysPrev;
  numberOfPlaysPrev = library.at(id) -> numberOfPlays;
  library.at(id) -> numberOfPlays += ntimes;
  cout << *(library.at(id) -> theSong) << " played successfully " << ntimes
  << " times (" << numberOfPlaysPrev << " plays -> "
  << library.at(id) -> numberOfPlays << " plays).";
  return true;
}
// Dumps to a vector for sorting
// then prints from the vector
void Library::libraryDisplayAll(string organizeBy){
  if (library.empty()){
    cout << "You have no songs in your library." << endl << "> ";
    return;
  }
  if(organizeBy == "NAME"){
    vector<songWrapper*> temp;
    for (auto it = library.begin(); it != library.end(); ++it){
      temp.push_back(it -> second);
    }
    sort(temp.begin(), temp.end(), songTitleCompareFunction);
    for (unsigned int i = 0; i < temp.size(); ++i){
    cout << i + 1 << ". " << *temp.at(i);
    }
  }
  else if(organizeBy == "ARTIST"){
    vector<songWrapper*> temp;
    for (auto it = library.begin(); it != library.end(); ++it){
      temp.push_back(it -> second);
    }
    sort(temp.begin(), temp.end(), artistNameCompareFunction);
    for (unsigned int i = 0; i < temp.size(); ++i){
      cout  << i + 1 << ". " << *temp.at(i);
    }
  }
  else if(organizeBy == "ALBUM"){
  vector<songWrapper*> temp;
    for (auto it = library.begin(); it != library.end(); ++it){
      temp.push_back(it -> second);
    }
    sort(temp.begin(), temp.end(), albumTitleCompareFunction);
    for (unsigned int i = 0; i < temp.size(); ++i){
      cout  << i + 1 << ". " << *temp.at(i);
    }
  }
  else if(organizeBy == "PLAYS"){
  vector<songWrapper*> temp;
    for (auto it = library.begin(); it != library.end(); ++it){
      temp.push_back(it -> second);
    }
    sort(temp.begin(), temp.end(), numPlaysCompareFunction);
    for (unsigned int i = 0; i < temp.size(); ++i){
      cout  << i + 1 << ". " << *temp.at(i);
    }
  }
  else{
    vector<songWrapper*> temp;
    for (auto it = library.begin(); it != library.end(); ++it){
      temp.push_back(it -> second);
    }
    sort(temp.begin(), temp.end(), songTitleCompareFunction);
    for (unsigned int i = 0; i < temp.size(); ++i){
      cout  << i + 1 << ". " << *temp.at(i);
    }
  }
}
// For the next three compare functions I transform the strings
// to lowercase because the string class overloads < operator
// based of ACII values and captial letters have different
// values from lowercase values
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
  return a -> numberOfPlays > b -> numberOfPlays;
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
// Prints in this format:
// “Hillary O’ Hillary” by Sam Bundy (2016) - 68 plays [#4]
void Library::printSongFromId(unsigned int id){
  cout << *(library.at(id));
}
// Prints in this format:
// “Love” by Simon Ayzman (CSCI 235 Blues)
void Library::printSongFromIdBasic(unsigned int id){
  cout << *(library.at(id) -> theSong);
}
unsigned int Library::findId(Song* aSong){
  for(auto it = library.begin(); it != library.end(); ++it){
    if (*aSong == *(it -> second -> theSong)){return it -> first;}
  }
}
// Prints in this format:
// “The Final Countdown” by Simon Ayzman (Trash Talk), identified as #27
void Library::printSongFromId2(unsigned int id){
  cout << "\"" << library.at(id) -> theSong -> songTitleGetter() << "\" by "
  << library.at(id) -> theSong -> artistNameGetter()
  << " (" << library.at(id) -> theSong -> albumTitleGetter()
  << "), identified as #" << id;
}
void Library::exportLibrary(string nameOfFile){
  ofstream write;
  write.open(nameOfFile);
  for(auto it = library.begin(); it != library.end(); ++it){
    write << it -> second -> theSong -> songTitleGetter() << "|"
    << it -> second -> theSong -> artistNameGetter() << "|"
    << it -> second -> theSong -> albumTitleGetter() << "|"
    << it -> second -> numberOfPlays << "|"
    << it -> second -> id << endl;
  }
  write.close();
}
void Library::exportPlaylistSongFromId(ostream& write, unsigned int id){
  write << library.at(id) -> theSong -> songTitleGetter() << "|"
  << library.at(id) -> theSong -> artistNameGetter() << "|"
  << library.at(id) -> theSong -> albumTitleGetter() << endl;
}
// Returns a vector with the ids of the songs that have the same name
vector<unsigned int> Library::returnIdsFromSongName(string name){
  vector<unsigned int> ids;
  for(auto it = library.begin(); it != library.end(); ++it){
    if(it -> second -> theSong -> songTitleGetter() == name){
      ids.push_back(it -> second -> id);
    }
  }
  return ids;
}
vector<unsigned int> Library::returnIdsFromArtistName(string name){
  vector<unsigned int> ids;
  for(auto it = library.begin(); it != library.end(); ++it){
    if(it -> second -> theSong -> artistNameGetter() == name){
      ids.push_back(it -> second -> id);
    }
  }
  return ids;
}
vector<unsigned int> Library::returnIdsFromAlbumName(string name){
  vector<unsigned int> ids;
  for(auto it = library.begin(); it != library.end(); ++it){
    if(it -> second -> theSong -> albumTitleGetter() == name){
      ids.push_back(it -> second -> id);
    }
  }
  return ids;
}
// Its magic
vector<unsigned int> Library::magic(){
vector<songWrapper*> temp;
vector<songWrapper*> topFive;
vector<unsigned int> tempIds;
vector<unsigned int> allIdsUsed;
int randNum;
srand(time(0));
  for (auto it = library.begin(); it != library.end(); ++it){
    temp.push_back(it -> second);
  }
  sort(temp.begin(), temp.end(), numPlaysCompareFunction);
  random_shuffle(temp.begin(), temp.end());
  if(temp.size() >= 5){
    for(int i = 0; i < 5; ++i){
      topFive.push_back(temp[i]);
    }
  }
  else if(temp.size() < 5 && temp.size() > 0){
    for(unsigned int i = 0; i < temp.size(); ++i){
      topFive.push_back(temp[i]);
    }
  }
  else{
    cout << "You have no songs in you library!" << endl << "> ";
    return allIdsUsed;
  }
  cout << "Autogenerating based on the following songs:" << endl;
  for(unsigned int i = 0; i < topFive.size(); ++i){
    randNum = rand() % 3 + 1;
    if(randNum == 1){
      // Find Similar songs via song title
      cout << "  " << *topFive[i] -> theSong << ". Similar songs by NAME:" << endl;
      tempIds = returnIdsFromSongName(topFive[i] -> theSong -> songTitleGetter());
      if(tempIds.size() >= 3){
        for(int i = 0; i < 3; ++i){
          cout << "     ";
          printSongFromIdBasic(tempIds[i]);
          cout << endl;
          allIdsUsed.push_back(tempIds[i]);
        }
      }
      else{
        for(unsigned int i = 0; i < tempIds.size(); ++i){
          cout << "     ";
          printSongFromIdBasic(tempIds[i]);
          cout << endl;
          allIdsUsed.push_back(tempIds[i]);
        }
      }
    }
    if(randNum == 2){
      // Find Similar songs via artist
      cout << "  " << *topFive[i] -> theSong << ". Similar songs by ARTIST:" << endl;
      tempIds = returnIdsFromArtistName(topFive[i] -> theSong -> artistNameGetter());
      if(tempIds.size() >= 3){
        for(int i = 0; i < 3; ++i){
          cout << "     ";
          printSongFromIdBasic(tempIds[i]);
          cout << endl;
          allIdsUsed.push_back(tempIds[i]);
        }
      }
      else{
        for(unsigned int i = 0; i < tempIds.size(); ++i){
          cout << "     ";
          printSongFromIdBasic(tempIds[i]);
          cout << endl;
          allIdsUsed.push_back(tempIds[i]);
        }
      }
    }
    if(randNum == 3){
      // Find Similar songs via album
      cout << "  " << *topFive[i] -> theSong << ". Similar songs by ALBUM:" << endl;
      tempIds = returnIdsFromAlbumName(topFive[i] -> theSong -> albumTitleGetter());
      if(tempIds.size() >= 3){
        for(int i = 0; i < 3; ++i){
          cout << "     ";
          printSongFromIdBasic(tempIds[i]);
          cout << endl;
          allIdsUsed.push_back(tempIds[i]);
        }
      }
      else{
        for(unsigned int i = 0; i < tempIds.size(); ++i){
          cout << "     ";
          printSongFromIdBasic(tempIds[i]);
          cout << endl;
          allIdsUsed.push_back(tempIds[i]);
        }
      }
    }
  }
  return allIdsUsed;
}

#endif // LIBRARY_CPP_