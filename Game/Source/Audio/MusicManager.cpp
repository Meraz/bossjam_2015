#include <Audio/MusicManager.hpp>


MusicManager* MusicManager::musicManagerContext = nullptr;

MusicManager* MusicManager::GetMusicManagerContext()
{
	if (musicManagerContext == nullptr)
	{
		musicManagerContext = new MusicManager();
		musicManagerContext->LoadSong("Audio/PATGOIN_-_SPANISH_GUITAR.flac");
		musicManagerContext->LoadSong("Audio/Dash.flac");
	}
	return musicManagerContext;
}


MusicManager::MusicManager()
{
	m_songCount = 0;
}

MusicManager::~MusicManager()
{
}


bool MusicManager::LoadSong(std::string songName)
{
	Song* song = new Song();
	song->songName = songName;
	if (!song->song.openFromFile(songName))
		return false;
	song->song.setLoop(false);
	return m_songList.AddEntry(songName, song);
}


void MusicManager::PlaySong(std::string songName)
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

void MusicManager::PlaySongFromStart(std::string songName)
{
	Song* temp = nullptr;
	m_songList.RetrieveEntry(songName, &temp);
	temp->song.play();
}

void MusicManager::PlaySongExclusive(std::string songName)
{
	StopAllOtherSongs(songName);
	PlaySongFromStart(songName);
}

void MusicManager::PlaySongExclusiveFromStart(std::string songName)
{
	StopAllMusic();
	PlaySong(songName);
}

void MusicManager::PlaySongFromTime(std::string songName, sf::Time time)
{
	Song* temp = nullptr;
	m_songList.RetrieveEntry(songName, &temp);

	temp->song.play();
	temp->song.setPlayingOffset(time);
}

void MusicManager::StopAllMusic()
{
	std::vector<Song*> all = m_songList.GetAllElements();

	for (unsigned int i = 0; i < all.size(); ++i)
	{
		all.at(i)->song.stop();
	}
}

void MusicManager::StopSong(std::string songName)
{
	Song* temp = nullptr;
	m_songList.RetrieveEntry(songName, &temp);

	temp->song.stop();
}

void MusicManager::StopAllOtherSongs(std::string songName)
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