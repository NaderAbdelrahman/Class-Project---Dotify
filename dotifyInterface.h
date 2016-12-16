#ifndef DOTIFY_INTERFACE_H_
#define DOTIFY_INTERFACE_H_

#include "libraryDriver.h"

class dotifyInterface{
public:
  void run();
  void run(string filename, bool playlist);
  void run(string libraryFile, string playlistFile, bool playlist);
private:
  libraryDriver driver;
  void printHelpMenu();
  void userCommandInput();
};

#endif // DOTIFY_INTERFACE_H_