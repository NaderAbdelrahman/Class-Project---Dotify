#ifndef DOTIFY_INTERFACE_CPP_
#define DOTIFY_INTERFACE_CPP_

#include "dotifyInterface.h"

void dotifyInterface::run(string filename, bool playlist){
  driver.loadLibrary(filename, playlist);
  cout << "Welcome to Dotify! For a full list of commands, type \"HELP\"." << endl << "> ";
  while (true) {
    userCommandInput();

  }
}
void dotifyInterface::run(){
  cout << "No library file provided." << endl
  << "No playlists file provided." << endl;
  cout << "Welcome to Dotify! For a full list of commands, type \"HELP\"." << endl << "> ";
  while (true) {
    userCommandInput();
  }
}
void dotifyInterface::run(string libraryFile, string playlistFile, bool playlist){
  driver.loadLibrary(libraryFile, playlist);
  driver.loadPlaylists(playlistFile);
  cout << "Welcome to Dotify! For a full list of commands, type \"HELP\"." << endl << "> ";
  while (true) {
    userCommandInput();
  }
}
void dotifyInterface::printHelpMenu(){
  cout << "AS: Purchases a new song to your library" << endl
  << "RS: Removes a specific song from your library" << endl
  << "AP: Creates an empty playlist" << endl
  << "RP: Removes a specific playlist" << endl
  << "RN: Renames a specific playlist" << endl
  << "AG: Autogenerates a playlist based on song name, artist, album, or magic" << endl
  << "ASP: Adds a specific song from your library to a playlist" << endl
  << "RSP: Removes a specific song from a playlist" << endl
  << "LB: Displays all the songs in your library" << endl
  << "PLS: Displays all the of the playlists in alphabetical order of title" << endl
  << "PL: Displays all the songs in a specific playlist in the order added" << endl
  << "RT: Rates a specific playlist from 1 to 5" << endl
  << "PLY: Plays a specific song in your library a specified number of time" << endl
  << "EXP: Exports the song library and playlists to files" << endl
  << "HELP: Displays this help menu" << endl
  << "EXIT: Exits the program" << endl << "> ";
}
void dotifyInterface::userCommandInput(){
  string userInput;
  getline(cin, userInput);
  if(userInput == "AS"){
    string songTitle, artistName, albumName;
    cout << "What is the name of the song you’d like to purchase?" << endl << "> ";
    getline(cin, songTitle);
    cout << "Who is its artist?" << endl << "> ";
    getline(cin, artistName);
    cout << "Which album does it belong to?" << endl << "> ";
    getline(cin, albumName);
    driver.addSong(songTitle, artistName, albumName);
  } 
  else if (userInput == "RS"){
    cout << "What is the identifier of the song you'd like to remove from your library?" << endl << "> ";
    unsigned int id;
    cin >> id;
    string temp;
    getline(cin, temp); // remove unnecessary chars
    driver.removeSong(id);
  }
  else if (userInput == "AP"){
    cout << "What is the title of the playlist you’d like to create?" << endl << "> ";
    string title;
    getline(cin, title);
    if(!driver.addPlaylist(title)){
      cout << "\"" << title << "\" playlist already exists." << endl <<  "> ";
      return;
    }
    cout << "\"" << title << "\" playlist created successfully." << endl << "> ";
  }
  else if (userInput == "RP"){
    cout << "What is the title of the playlist you’d like to remove?" << endl << "> ";
    string title;
    getline(cin, title);
    if(!driver.removePlaylist(title)){
      cout << "\"" << title << "\" playlist does not exist." << endl << "> ";
      return;
    }
    cout << "\"" << title << "\" playlist removed successfully." << endl << "> ";
  }
  else if (userInput == "RN"){
    string oldTitle, newTitle;
    cout << "What is the title of the playlist you’d like to rename?" << endl << "> ";
    getline(cin, oldTitle);
    if(!driver.playlistExists(oldTitle)){
      cout << "\"" << oldTitle << "\" playlist does not exist." << endl << "> ";
      return;
    }
    cout << "What is the new title that you’d like to rename it to?" << endl << "> ";
    getline(cin, newTitle);
    if(driver.playlistExists(newTitle)){
      cout << "\"" << newTitle << "\" playlist already exists." << endl << "> ";
      return;
    }
    driver.renamePlaylist(oldTitle, newTitle);
    return;
  }
  else if (userInput == "AG"){
    cout << "NOT YET FAMS" << endl << "> ";
    return;
  }
  else if (userInput == "ASP"){
    string title;
    unsigned int id;
    cout << "What is the title of the playlist you’d like to add a song to?" << endl << "> ";
    getline(cin, title);
    if(!driver.playlistExists(title)){
      cout << "\"" << title << "\" playlist does not exist." << endl << "> ";
      return;
    }
    cout << "What is identifier of the song to add to the playlist?" << endl << "> ";
    cin >> id;
    string temp;
    getline(cin, temp); // remove unnecessary chars
    if(!driver.songExists(id)){
      cout << "No song with identifier #" << id << " exists in your library." << endl << "> ";
      return;
    }
    driver.addSongPlaylist(title, id);
    driver.printSongFromId2(id);
    cout << ", added successfully to playlist \"" << title << "\"." << endl << "> ";
  }
  else if (userInput == "RSP"){
    string title;
    unsigned int id;
    cout << "What is the title of the playlist you’d like to remove a song from?" << endl << "> ";
    getline(cin, title);
    if(!driver.playlistExists(title)){
      cout << "\"" << title << "\"" << " playlist does not exist." << endl;
      return;
    }
    cout << "What is identifier of the song to remove from the playlist?" << endl << "> ";
    cin >> id;
    string temp;
    getline(cin, temp); // remove unnecessary chars
    if(!driver.songExists(id)){
      cout << "No song with identifier #" << id << " exists in your library." << endl;
      return;
    }
    driver.removeSongPlaylist(title, id);
    driver.printSongFromId2(id);
    cout << ", removed successfully from playlist \"" << title << "\"." << endl << "> ";
    return;
  }
  else if (userInput == "LB"){
    string sort;
    cout << "What category should the songs be ordered by? (NAME/ARTIST/ALBUM/PLAYS)" << endl << "> ";
    getline(cin, sort);
    driver.displayAllLibrary(sort);
    cout << "> ";
  }
  else if (userInput == "PLS"){
    driver.displayAllPlaylists();
  }
  else if (userInput == "PL"){
    string title;
    cout << "What is the title of the playlist you’d like to display?" << endl << "> ";
    getline(cin, title);
    if(!driver.playlistExists(title)){
      cout << "\"" << title << "\" playlist does not exist." << endl << "> ";
      return;
    }
    driver.songPlaylistPrint(title);
  }
  else if (userInput == "RT"){
    string title, rating;
    unsigned int rate;
    cout << "What is the title of the playlist you’d like to rate?" << endl << "> ";
    getline(cin, title);
    if(!driver.playlistExists(title)){
      cout << "\"" << title << "\" playlist does not exist." << endl << "> ";
      return;
    }
    cout << "What rating would you like to give this playlist? (1 to 5)" << endl << "> ";
    getline(cin, rating);
    if(rating == "1"){rate = 1;}
    else if(rating == "2"){rate = 2;}
    else if(rating == "3"){rate = 3;}
    else if(rating == "4"){rate = 4;}
    else if(rating == "5"){rate = 5;}
    else{
      cout << "\"" << rating << "\"" << "is not a valid rating." << endl << "> ";
      return;
    }
    driver.ratePlaylist(title, rate);
    cout << "\"" << title << "\"" << " playlist rated successfully as a " << rate << "." << endl << "> ";
  }
  else if (userInput == "PLY"){
    unsigned int id, nTimes;
    cout << "What is the identifier of the song you’d like to listen to?" << endl << "> ";
    cin >> id;
    string temp;
    getline(cin, temp); // remove unnecessary chars
    if(!driver.songExists(id)){
      cout << "No song with identifier #" << id << " exists in your library." << endl << "> ";
      return;
    }
    cout << "How many times would you like to play this song?" << endl << "> ";
    cin >> nTimes;
    if(cin.fail()){
      cin.clear();
      driver.playSong(id, 0);
      string temp;
      getline(cin, temp); // remove unnecessary chars
      return;
    }
    driver.playSong(id, nTimes);
  }
  else if (userInput == "EXP"){
    cout << "NOT YET FAMS" << endl << "> ";
    return;
  }
  else if (userInput == "HELP"){
    printHelpMenu();
  }
  else if (userInput == "EXIT"){
    cout << "Thank you for using Dotify!" << endl;
    exit(EXIT_SUCCESS);
  }
  else if(userInput == ""){
    cout << endl << "> ";
    return;
  }
  else{
  cout << "Invalid input" << endl << "> ";
  return;
  }
}


#endif // DOTIFY_INTERFACE_CPP_