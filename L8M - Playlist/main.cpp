#include <iostream>
#include <string>
#include <vector>
#include "Playlist.h"
#include "Song.h"
using namespace std;

void PrintAllPlaylists (vector<Playlist*> playlistLibrary) {
	for (unsigned int i = 0; i < playlistLibrary.size(); ++i) {
		cout << i << ": " << playlistLibrary.at(i)->GetPlaylistName() << endl;
	}
}

void PrintAllSongs (vector<Song*> songLibrary) {
	for (unsigned int i = 0; i < songLibrary.size(); ++i) {
		cout << i << ": " << songLibrary.at(i)->GetSongName() << endl;
	}
}

int main() {
	vector<Song*> songLibrary;
	vector<Playlist*> playlistLibrary;
	string menuInput = "";
	string name = "";
	string line = "";
	int playlistIndex = 0;
	int songIndex = 0;

	// welcome screen
	cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl << endl;

	do {
		cout << "Enter your selection now: ";
		cin >> menuInput;
		cin.ignore();
		
		if (menuInput == "quit") {
			break;
		}

		// add
		else if (menuInput == "add") {
			cout << "Read in Song names and first lines (type \"STOP\" when done): " << endl;
			while (name != "STOP") {
				Song* newSong = nullptr; // create space for new song

				cout << "Song Name: ";
				getline(cin, name);
				if (name == "STOP") { // exit loop if STOP is entered
					break;
				}

				cout << "Song's first line: ";
				getline(cin, line);				
				newSong = new Song(name, line);

				songLibrary.push_back(newSong); // add new song to library
			}
			cout << endl;
		}

		// list
		else if (menuInput == "list") {
			for (unsigned int i = 0; i < songLibrary.size(); ++i) {
				cout << songLibrary.at(i)->GetSongName() << ": \"" << songLibrary.at(i)->GetFirstLine();
				cout << "\", " << songLibrary.at(i)->GetPlayCount() << " play(s)." << endl;
			}
			cout << endl;
		}

		// addp
		else if (menuInput == "addp") {
			Playlist* newPlaylist = nullptr; // create space for new playlist 

			cout << "Playlist name: ";
			getline(cin, name);
			newPlaylist = new Playlist(name);

			playlistLibrary.push_back(newPlaylist); // add new playlist to library of all playlists
			cout << endl;
		}

		// addsp
		else if (menuInput == "addsp") {
			PrintAllPlaylists(playlistLibrary);
			cout << "Pick a playlist index number: ";
			cin >> playlistIndex;
			cin.ignore();

			PrintAllSongs(songLibrary);
			cout << "Pick a song index number: ";
			cin >> songIndex;
			cin.ignore();

			playlistLibrary.at(playlistIndex)->AddSongToPlaylist(songLibrary.at(songIndex));

			cout << endl;
		}

		// listp
		else if (menuInput == "listp") {
			PrintAllPlaylists(playlistLibrary);
			cout << endl;
		}

		// play
		else if (menuInput == "play") {
			PrintAllPlaylists(playlistLibrary);
			cout << "Pick a playlist index number: ";
			cin >> playlistIndex;
			cin.ignore();
			cout << endl;

			cout << "Playing first lines of playlist: ";
			cout << playlistLibrary.at(playlistIndex)->GetPlaylistName() << endl;
		
			playlistLibrary.at(playlistIndex)->PlayFirstLinesOfPlaylist();
		}

		// remp
		else if (menuInput == "remp") {
			PrintAllPlaylists(playlistLibrary);
			cout << "Pick a playlist index number to remove: ";
			cin >> playlistIndex;
			cin.ignore();

			// deallocate memory and delete pointer for playlist
			delete playlistLibrary.at(playlistIndex); // FREEING MEMORY
			playlistLibrary.erase(playlistLibrary.begin() + playlistIndex);
			cout << endl;
		}

		// remsp
		else if (menuInput == "remsp") {
			PrintAllPlaylists(playlistLibrary);
			cout << "Pick a playlist index number: ";
			cin >> playlistIndex;
			cin.ignore();

			playlistLibrary.at(playlistIndex)->PrintPlaylistSongs();
			cout << "Pick a song index number to remove: ";
			cin >> songIndex;
			cin.ignore();

			// delete pointer for playlist
			playlistLibrary.at(playlistIndex)->RemoveSongFromPlaylist(songLibrary.at(songIndex), songIndex);

			cout << endl;
		}

		// remsl
		else if (menuInput == "remsl") {
			PrintAllSongs(songLibrary);
			cout << "Pick a song index number to remove: ";
			cin >> songIndex;
			cin.ignore();

			// deallocate memory and delete pointer for playlist
			for (unsigned int i = 0; i < playlistLibrary.size(); i++) {
				playlistIndex = playlistLibrary.at(i)->FindSongInPlaylist(songLibrary.at(songIndex)->GetSongName());
				if (playlistIndex != -1) {
					playlistLibrary.at(i)->RemoveSongFromPlaylist(songLibrary.at(songIndex),playlistIndex);
				}
			}

			// delete song from library (free up space too)
			delete songLibrary.at(songIndex); // FREEING MEMORY
			songLibrary.erase(songLibrary.begin() + songIndex);

			cout << endl;
		}

		else { // invalid selection OR user types "options" 
			cout << "add\t\t\tAdds a list of songs to the library" << endl;
			cout << "list\t\tLists all the songs in the library" << endl;
			cout << "addp\t\tAdds a new playlist" << endl;
			cout << "addsp\t\tAdds a song to a playlist" << endl;
			cout << "listp\t\tLists all the playlists" << endl;
			cout << "play\t\tPlays a playlist" << endl;
			cout << "remp\t\tRemoves a playlist" << endl;
			cout << "remsp\t\tRemoves a song from a playlist" << endl;
			cout << "remsl\t\tRemoves a song from the library (and all playlists)" << endl;
			cout << "options\t\tPrints this options menu" << endl;
			cout << "quit\t\tQuits the program" << endl << endl;
		}

	}
	while (menuInput != "quit");
	// once quitted, say goodbye
	cout << "Goodbye!" << endl;

	// delete all playlists, songs, and pointers
	for (unsigned int i = 0; i < playlistLibrary.size(); ++i) {
		delete playlistLibrary.at(i);  // FREEING MEMORY
	}
	for (unsigned int i = 0; i < songLibrary.size(); ++i) {
		delete songLibrary.at(i);  // FREEING MEMORY
	}

	return 0;
}