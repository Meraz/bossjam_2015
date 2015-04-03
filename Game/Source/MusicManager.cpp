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
	m_songList.RetrieveEntry(songName, temp);

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
	m_songList.RetrieveEntry(songName, temp);


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

void MusicManager::stopAllMusic()
{
	//Song* temp;
	//m_songList.RetrieveEntry(songName, temp);

	//for (int i = 0; i < m_songList.size(); i++)
	//{
	//	temp->song.stop();
	//}
}

void MusicManager::stopSong(std::string songName)
{
	Song* temp = nullptr;
	m_songList.RetrieveEntry(songName, temp);

	temp->song.stop();
}

void MusicManager::stopAllOtherSongs(std::string songName)
{
	//for (int i = 0; i < m_songList.size(); i++)
	//{
	//	if (m_songList.at(i)->songName != songName)
	//	{
	//		m_songList.at(i)->song.stop();
	//	}
	//	else
	//	{
	//		//If it goes here it is on the song it shouldn't stop
	//	}
	//}
}