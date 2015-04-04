#include "MusicManager.hpp"


MusicManager::MusicManager()
{
	m_songCount = 0;
}

MusicManager::~MusicManager()
{
}


bool MusicManager::loadSong(std::string songName)
{
	Song* song = new Song();
	song->songName = songName;
	if (!song->song.openFromFile(songName))
		return false;

	return m_songList.AddEntry(songName, song);
}


void MusicManager::playSong(std::string songName)
{
	Song* temp = nullptr;
	m_songList.RetrieveEntry(songName, &temp);

	if (temp->song.getStatus() != sf::Music::Playing)
	{
		temp->song.play();
	}
	else
	{
		//It will continue playing the song
	}
}

void MusicManager::playSongFromStart(std::string songName)
{
	Song* temp = nullptr;
	m_songList.RetrieveEntry(songName, &temp);


	temp->song.play();
}

void MusicManager::playSongExclusive(std::string songName)
{
	stopAllOtherSongs(songName);
	playSongFromStart(songName);
}

void MusicManager::playSongExclusiveFromStart(std::string songName)
{
	stopAllMusic();
	playSong(songName);
}

void MusicManager::PlaySongFromTime(std::string songName, sf::Time time)
{
	Song* temp = nullptr;
	m_songList.RetrieveEntry(songName, &temp);

	temp->song.play();
	temp->song.setPlayingOffset(time);
}

void MusicManager::stopAllMusic()
{
	std::vector<Song*> all = m_songList.GetAllElements();

	for (unsigned int i = 0; i < all.size(); ++i)
	{
		all.at(i)->song.stop();
	}
}

void MusicManager::stopSong(std::string songName)
{
	Song* temp = nullptr;
	m_songList.RetrieveEntry(songName, &temp);

	temp->song.stop();
}

void MusicManager::stopAllOtherSongs(std::string songName)
{
	std::vector<Song*> all = m_songList.GetAllElements();

	for (unsigned int i = 0; i < all.size(); ++i)
	{
		if (all.at(i)->songName != songName)
		{
			all.at(i)->song.stop();
		}
		else
		{
			//If it goes here it is on the song it shouldn't stop
		}
	}
}