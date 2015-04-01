#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H

#include <SFML/Audio.hpp>
#include <vector>

class MusicManager
{
private:
	struct Song
	{
		std::string songName;
		sf::Music song;
	};

	std::vector<Song*> m_songList;
	int m_songCount;


	std::string currentlyPlaying;
	
public:
	MusicManager();
	~MusicManager();

	bool loadSong(std::string songName);

	void playSong(std::string songName);
	void playSongExclusive(std::string songName);

	void stopAllMusic();
	void stopSong();
};

#endif