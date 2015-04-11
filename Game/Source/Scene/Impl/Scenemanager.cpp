#include <Scene/Impl/SceneManager.hpp>

#include <Scene/Impl/MenuScene.hpp>
#include <Scene/Impl/GameScene.hpp>

SceneManager::SceneManager() :
m_currentScene(nullptr),
m_menuScene(nullptr),
m_gameScene(nullptr)
{
	m_currentScene = new GameScene();
	m_reAllocateOnChange = false;
}

SceneManager::~SceneManager()
{

}
void SceneManager::Update(float deltaT)
{
	m_currentScene->Update(deltaT);
}

void SceneManager::Render(sf::RenderWindow* window)
{
	m_currentScene->Render(window);
}

void SceneManager::ChangeScene(SceneType newScene)
{

}