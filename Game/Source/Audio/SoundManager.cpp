#include <Audio/SoundManager.hpp>


SoundManager* SoundManager::soundManagerContext = nullptr;

SoundManager* SoundManager::GetSoundManagerContext()
{
	if (soundManagerContext == nullptr)
	{
		soundManagerContext = new SoundManager();
		SoundManager::GetSoundManagerContext()->LoadSound("Audio/Dash.flac");
		SoundManager::GetSoundManagerContext()->LoadSound("Audio/LockIn.flac");
		SoundManager::GetSoundManagerContext()->LoadSound("Audio/Jump.flac");
		SoundManager::GetSoundManagerContext()->LoadSound("Audio/DeathSound.flac");


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

void SoundManager::SetVolume(const std::string& songName, float volume)
{
	Sound* temp = nullptr;
	m_songList.RetrieveEntry(songName, &temp);
	temp->sound.setVolume(volume);
}