#pragma once

#include <SFML/Audio.hpp>
#include <vector>
#include "System/DataManager.hpp"

class MusicManager
{
public:
	static MusicManager* GetMusicManagerContext();
private:
	static MusicManager* musicManagerContext;
	MusicManager();
	~MusicManager();
	struct Song
	{
		std::string songName;
		sf::Music song;
	};
	DataManager<Song> m_songList;
	int m_songCount;


	std::string currentlyPlaying;
	
public:
	
	bool LoadSong(std::string songName);

	//Will continue playing the song if it is already playing
	void PlaySong(std::string songName);

	//Will restart the song if its playing already
	void PlaySongFromStart(std::string songName);

	//Will stop all other songs and start chosen song if it isn't already playing
	void PlaySongExclusive(std::string songName);

	//Will stop all other songs and start chosen song from the start
	void PlaySongExclusiveFromStart(std::string songName);

	//Starts playing at a certain time in the song
	void PlaySongFromTime(std::string songName, sf::Time time);

	//Stops all music
	void StopAllMusic();

	//Stops chosen song
	void StopSong(std::string songName);

	//Stops all except chosen song
	void StopAllOtherSongs(std::string songName);

	void SetVolume(const std::string& songName, float volume);
};