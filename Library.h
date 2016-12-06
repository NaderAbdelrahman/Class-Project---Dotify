#ifndef LIBRARY_H_
#define LIBRARY_H_
#include <unordered_map>
#include <utility>

class Library{

public:
  bool addSong(Song* aSong);
  Song* removeSong(unsigned int id);
  bool playSong(int id, int ntimes);
private:
  unordered_map <int, pair <Song*, int> >;
  unsigned int numberOfPlays = 0;
  unsigned int uniqueId = 0;
};
#endif // LIBRARY_H_