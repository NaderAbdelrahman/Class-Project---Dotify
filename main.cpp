#include "Song.h"
#include "Library.h"
#include "Playlist.h"

using namespace std;

int main() {

  Song obj("a", "zArtist", "HTrash Talk2");
  Song obj2("az", "cArtist", "JTrash Talk2");
  Song obj3("z", "Xartist", "KTrash Talk2");
  Song obj4("C", "AArtist", "ITrash Talk2");

  // Song obj2("The Final Bloatdown", "Simon Ayzman", "Trash Talk2");
  // bool x = obj == obj2;
  // cout << x << endl;
  Library lib;
  Song* objPtr = &obj;
  Song* objPtr2 = &obj2;
  Song* objPtr3 = &obj3;
  Song* objPtr4 = &obj4;
  lib.addSong(objPtr);
  lib.addSong(objPtr2);
  lib.addSong(objPtr3);
  lib.addSong(objPtr4);
  lib.libraryDisplayAll("ALBUvffM");

  return 0;
}