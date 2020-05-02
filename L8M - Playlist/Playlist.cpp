#include <iostream>
#include <string>
#include <vector>
#include "Playlist.h"
using namespace std;

// default constructor
Playlist::Playlist() {
	playlistName = "Default Playlist";
}

// parameterized constructor
Playlist::Playlist(string name) {
	playlistName = name;
}

string Playlist::GetPlaylistName() const {
	return playlistName;
}

void Playlist::AddSongToPlaylist(Song* songToAdd) {
	listOfSongs.push_back(songToAdd);
}

void Playlist::RemoveSongFromPlaylist(Song* songToRemove, int songIndex) {
	listOfSongs.erase(listOfSongs.begin() + songIndex);
}

int Playlist::FindSongInPlaylist(string songToFind) {
	int playlistIndex = -1;
	for (unsigned int i = 0; i < listOfSongs.size(); ++i) {
		if (songToFind == listOfSongs.at(i)->GetSongName()) {
			playlistIndex = i;
			break;
		}
	}
	return playlistIndex;
}

void Playlist::PlayFirstLinesOfPlaylist() const {
	for (unsigned int i = 0; i < listOfSongs.size(); ++i) {
		cout << listOfSongs.at(i)->GetFirstLine() << endl;
		listOfSongs.at(i)->PlusOnePlayCount();
	}
	cout << endl;	
}

void Playlist::PrintPlaylistSongs() const {
	for (unsigned int i = 0; i < listOfSongs.size(); ++i) {
		cout << i << ": " << listOfSongs.at(i)->GetSongName() << endl;
	}
}