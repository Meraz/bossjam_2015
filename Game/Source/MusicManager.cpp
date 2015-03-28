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
	m_songList.push_back(song);

	if (!m_songList[m_songCount]->song.openFromFile(songName))
		return false;
}


void MusicManager::playMusic(std::string songName)
{
	for (int i = 0; i < m_songList.size(); i++)
	{
		if (m_songList[i]->songName == songName)
			m_songList[i]->song.play();
	}
}