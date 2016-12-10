#ifndef LIBRARY_DRIVER_H_
#define LIBRARY_DRIVER_H_

#include "Song.h"

class libraryDriver{

public:
  libraryDriver(){Library libObj;}
  bool addSong(string title, string artist, string album);
  bool removeSong(unsigned int )
private:

};



#endif // LIBRARY_DRIVER_H_