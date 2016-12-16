#include "dotifyInterface.h"

using namespace std;

int main(int argc, char *argv[]){
  if(argc == 1){
    dotifyInterface pgrm;
    pgrm.run();
  }
  if(argc == 2){
    string filename = argv[1];
    bool playlist = false;
    dotifyInterface pgrm;
    pgrm.run(filename, playlist);
  }
  if(argc == 3){
    string libraryFilename = argv[1];
    string playlistFilename = argv[2];
    bool playlist = true;
    dotifyInterface pgrm;
    pgrm.run(libraryFilename, playlistFilename, playlist);
  }
  return 0;
}