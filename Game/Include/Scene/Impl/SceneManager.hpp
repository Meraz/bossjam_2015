#pragma once

#include <Scene/AbstractSceneManager.hpp>
#include <Scene/AbstractScene.hpp>

class MenuScene;
class GameScene;

class SceneManager : public AbstractSceneManager
{
public:
	SceneManager();
	~SceneManager();	

	void Update(float deltaT);
	void Render(sf::RenderWindow* window);;
	SceneType GetCurrentSceneType() const { return m_currentSceneEnum; };

	void ChangeScene(SceneType newScene) override;

private:
	AbstractScene* m_currentScene;
	MenuScene* m_menuScene;
	GameScene* m_gameScene;
	SceneType m_currentSceneEnum;

	bool m_reAllocateOnChange;
};