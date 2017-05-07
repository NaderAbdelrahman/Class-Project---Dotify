#include "dotifyInterface.h"

using namespace std;

int main(int argc, char *argv[]){
  // If there is only one argument when the program is run
  // i.e. ./ProgramName it runs the program without loading files
  if(argc == 1){
    dotifyInterface pgrm;
    pgrm.run();
  }
  // If there are two arguments, the first one being ./ProgramName
  // the second one being the name of the library file to load
  // It runs the program while loading the library file name provided
  if(argc == 2){
    string filename = argv[1];
    bool playlist = false;
    dotifyInterface pgrm;
    pgrm.run(filename, playlist);
  }
  // If there are three arguments, the first one being ./ProgramName
  // the second one being the name of the library file to load, and
  // the third one being the name of the playlists file to load
  // It runs the program while loading the library, and playlists file names provided
  if(argc == 3){
    string libraryFilename = argv[1];
    string playlistFilename = argv[2];
    bool playlist = true;
    dotifyInterface pgrm;
    pgrm.run(libraryFilename, playlistFilename, playlist);
  }
  return 0;
}