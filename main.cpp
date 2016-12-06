#include "Song.h"

using namespace std;

int main() {

  Song obj("The Final Bloatdown", "Simon Ayzman", "Trash Talk2");
  Song obj2("The Final Bloatdown", "Simon Ayzman", "Trash Talk2");
  bool x = obj == obj2;
  cout << x << endl;

  return 0;
}