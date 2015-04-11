#include <Scene/Impl/SceneManager.hpp>

#include <Scene/Impl/MenuScene.hpp>
#include <Scene/Impl/GameScene.hpp>
#include <Scene/Impl/CharacterSelectScene.hpp>

SceneManager::SceneManager() :
m_currentScene(nullptr),
m_menuScene(nullptr),
m_gameScene(nullptr)
{
	m_currentScene = new CharacterSelectScene();
	m_reAllocateOnChange = false;
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
	if (newScene == SceneType::GAME)
	{
		m_currentScene = m_gameScene;
	}
	else if (newScene == SceneType::MENU)
	{
		m_currentScene = m_menuScene;
	}
	else if (newScene == SceneType::CHARSELECT)
	{
		//m_currentScene = m_characterScene;
	}
}