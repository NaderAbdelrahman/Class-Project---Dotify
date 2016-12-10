#include "Song.h"
#include "Library.h"
#include "Playlist.h"

using namespace std;

int main() {

  Library lib;
  Playlist ply;

  // Song * obj = new Song("a", "zArtist", "HTrash Talk2");
  // Song * obj2 = new Song("az", "cArtist", "JTrash Talk2");
  // Song * obj3 = new Song("z", "Xartist", "KTrash Talk2");
  // Song * obj4 = new Song("C", "AArtist", "ITrash Talk2");

  // lib.addSong(obj);
  // lib.addSong(obj2);
  // lib.addSong(obj3);
  // lib.addSong(obj4);
  // lib.libraryDisplayAll("ARTIST");
  // // lib.removeSong(0);
  // // lib.libraryDisplayAll("NAME");
  // lib.playSong(0, 5);

  // lib.libraryDisplayAll("ARTIST");
  // //lib.numberOfTimesPlaysGetter(0);

  lib.addPlaylist("test");
  lib.displayAllPlaylists();


  return 0;
}