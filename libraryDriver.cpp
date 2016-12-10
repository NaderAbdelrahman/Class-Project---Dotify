#ifndef LIBRARY_DRIVER_CPP_
#define LIBRARY_DRIVER_CPP_

bool libraryDriver::addSong(string title, string artist, string album){
  Song *song = new Song(title, artist, album);
  return libObj.addSong(song);
}


#endif // LIBRARY_DRIVER_CPP_