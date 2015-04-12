#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H

#include <SFML/Audio.hpp>
#include <vector>
#include "System/DataManager.hpp"

class SoundManager
{
public:
	static SoundManager* GetSoundManagerContext();
private:
	static SoundManager* soundManagerContext;
	SoundManager();
	~SoundManager();
	struct Sound
	{
		std::string soundName;
		sf::Sound sound;
		sf::SoundBuffer buffer;
	};
	DataManager<Sound> m_songList;
	int m_songCount;

	std::string currentlyPlaying;
	
public:	
	bool LoadSound(std::string soundName);

	//Will continue playing the song if it is already playing
	void PlaySound(std::string soundName);

	//Stops chosen song
	void StopSound(std::string soundName);
};

#endif