## Dotify

In order to compile use the provided makefile

The structure of the program is as follows:

At the lowest level
There is a Song class, that stores:
- A song title
- An artist name
- An album name

There is a Library class:
- It has a structure that wraps a pointer to a Song object and an id and the number of plays
- It uses an unordered_map to store pointers to the song wrapper

There is a Playlist class:
- It stores a playlist title, and a rating
- It uses a vector to store song ids (I use a vector inorder to keep order)

There is a libraryDriver class:
- This class ties together playlists and libraries
- It uses an unordered_map to store pointer to Playlist objects
- It initializes a library obj
- For the majority of functions in the driver class, it will simply call on library's functions.

There is a dotifyInterface class:
- This initializes a libraryDriver object
- This class communicates with the user and gets input from the user, it also does some minor error handling
- This class calls on drivers functions to get things done.

User -> dotifyInterface -> libraryDriver

While libraryDriver does these functions:
- Add a song
- Remove a song
- Add a playlist
- Remove a playlist
- Play a song
- Rename a playlist
- Rate a playlist
- Add a song to a playlist
- Remove a song from a playlist
- Can load and export files
- Display library, playlists, and Songs in a playlist
etc......
And there are a lot more internal functions to get the job done