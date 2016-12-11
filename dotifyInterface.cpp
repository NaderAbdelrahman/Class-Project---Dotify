#ifndef DOTIFY_INTERFACE_CPP_
#define DOTIFY_INTERFACE_CPP_

#include "dotifyInterface.h"

void dotifyInterface::run(){

  cout << "Welcome to Dotify! For a full list of commands, type \"HELP\"." << endl << endl << "> ";
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
  << "EXIT: Exits the program" << endl;
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

  }
  else if (userInput == "AP"){

  }
  else if (userInput == "RP"){

  }
  else if (userInput == "RN"){

  }
  else if (userInput == "AG"){

  }
  else if (userInput == "ASP"){

  }
  else if (userInput == "RSP"){

  }
  else if (userInput == "LB"){
    string sort;
    cout << "What category should the songs be ordered by? (NAME/ARTIST/ALBUM/PLAYS)" << endl << "> ";
    getline(cin, sort);
    driver.displayAllLibrary(sort);
  }
  else if (userInput == "PLS"){

  }
  else if (userInput == "PL"){

  }
  else if (userInput == "RT"){

  }
  else if (userInput == "PLY"){

  }
  else if (userInput == "EXP"){

  }
  else if (userInput == "HELP"){
    printHelpMenu();
  }
  else if (userInput == "EXIT"){
    cout << "Thank you for using Dotify!";
    return;
  }
  else{
  cout << "Invalid input" << endl;
  return;
  }
}


#endif // DOTIFY_INTERFACE_CPP_