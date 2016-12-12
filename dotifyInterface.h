#ifndef DOTIFY_INTERFACE_H_
#define DOTIFY_INTERFACE_H_

#include "libraryDriver.h"

class dotifyInterface{

public:
  void run();

private:
  libraryDriver driver;
  void printHelpMenu();
  void userCommandInput();
};


#endif // DOTIFY_INTERFACE_H_