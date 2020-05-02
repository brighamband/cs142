#ifndef SONG_H
#define SONG_H

#include <string>
using namespace std;

class Song {
public:
	Song();
	Song(string name, string line);
	string GetSongName() const;
	string GetFirstLine() const;
	void PlusOnePlayCount();
	int GetPlayCount() const;
private:
	string songName;
	string firstLine;
	int playCount;
};

#endif