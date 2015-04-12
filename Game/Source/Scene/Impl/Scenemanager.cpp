#include <Scene/Impl/SceneManager.hpp>
#include <Scene/Impl/GameScene.hpp>
#include <Scene/Impl/CharacterSelectScene.hpp>
#include <Audio/MusicManager.hpp>

SceneManager::SceneManager() :
m_currentScene(nullptr),
m_menuScene(nullptr),
m_gameScene(nullptr),
m_currentSceneEnum(SceneType::UNKNOWN)
{
	m_musicManager = new MusicManager();
	ChangeScene(SceneType::CHARSELECT);
}

SceneManager::~SceneManager()
{

}
void SceneManager::Update(sf::Time deltaT)
{
	m_currentScene->Update(deltaT);
}

void SceneManager::Render(sf::RenderWindow* window)
{
	m_currentScene->Render(window);
}

void SceneManager::ChangeScene(SceneType newScene)
{
	if (m_currentSceneEnum == newScene || newScene == SceneType::UNKNOWN)
		return;
	delete m_currentScene;

	if (newScene == SceneType::GAME)
	{
		m_currentScene = new GameScene(this);
	}
	else if (newScene == SceneType::CHARSELECT)
	{
		m_currentScene = new CharacterSelectScene(this);
	}	
	else if (newScene == SceneType::SCORE)
	{
		m_currentScene = new CharacterSelectScene(this);
	}
}

MusicManager* SceneManager::GetMusicManager()
{
	return m_musicManager;
}