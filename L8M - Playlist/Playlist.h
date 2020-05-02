#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
#include <vector>
#include "Song.h"
using namespace std;

class Playlist {
public:
	Playlist();
	Playlist(string name);
	string GetPlaylistName() const;
	void AddSongToPlaylist(Song* songToAdd);
	void RemoveSongFromPlaylist(Song* songToRemove, int songIndex);
	int FindSongInPlaylist(string songToFind);
	void PlayFirstLinesOfPlaylist() const;
	void PrintPlaylistSongs() const;
private:
	vector<Song*> listOfSongs;
	string playlistName;
};

#endif