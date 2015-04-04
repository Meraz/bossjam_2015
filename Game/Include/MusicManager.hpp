#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H

#include <SFML/Audio.hpp>
#include <vector>
#include "Media/Manager.hpp"

class MusicManager
{
private:
	struct Song
	{
		std::string songName;
		sf::Music song;
	};
	Manager<Song> m_songList;
	int m_songCount;


	std::string currentlyPlaying;
	
public:
	MusicManager();
	~MusicManager();

	bool loadSong(std::string songName);

	//Will continue playing the song if it is already playing
	void playSong(std::string songName);
	//Will restart the song if its playing already
	void playSongFromStart(std::string songName);
	//Will stop all other songs and start chosen song if it isn't already playing
	void playSongExclusive(std::string songName);
	//Will stop all other songs and start chosen song from the start
	void playSongExclusiveFromStart(std::string songName);
	//Starts playing at a certain time in the song
	void PlaySongFromTime(std::string songName, sf::Time time);

	//Stops all music
	void stopAllMusic();
	//Stops chosen song
	void stopSong(std::string songName);
	//Stops all except chosen song
	void stopAllOtherSongs(std::string songName);
};

#endif