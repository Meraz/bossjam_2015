#include <Audio/SoundManager.hpp>


SoundManager* SoundManager::soundManagerContext = nullptr;

SoundManager* SoundManager::GetSoundManagerContext()
{
	if (soundManagerContext == nullptr)
	{
		soundManagerContext = new SoundManager();
		SoundManager::GetSoundManagerContext()->LoadSound("Audio/Dash.flac");

	}
	return soundManagerContext;
}

SoundManager::SoundManager()
{
}

SoundManager::~SoundManager()
{
}

bool SoundManager::LoadSound(std::string songName)
{
	Sound* sound = new Sound();
	sound->soundName = songName;
	if (!sound->buffer.loadFromFile(songName))
		return false;
	sound->sound.setBuffer(sound->buffer);
	return m_songList.AddEntry(songName, sound);
}

void SoundManager::PlaySound(std::string songName)
{
	Sound* temp = nullptr;
	m_songList.RetrieveEntry(songName, &temp);
	temp->sound.play();
}

void SoundManager::StopSound(std::string songName)
{
	Sound* temp = nullptr;
	m_songList.RetrieveEntry(songName, &temp);

	temp->sound.stop();
}
