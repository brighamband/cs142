#include <iostream>
#include <string>
#include <vector>
#include "Song.h"
using namespace std;

// default constructor
Song::Song() {
	songName = "Untitled";
	firstLine = "Empty first line";
	playCount = 0;
}

// parameterized constructor
Song::Song(string name, string line) { // for setting song names and first lines when created
	songName = name;
	firstLine = line;
	playCount = 0;
}

string Song::GetSongName() const {
	return songName;
}

string Song::GetFirstLine() const {
	return firstLine;
}

void Song::PlusOnePlayCount() {
	playCount++;
}

int Song::GetPlayCount() const {
	return playCount;
}