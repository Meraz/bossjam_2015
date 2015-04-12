#pragma once

#include <Scene/AbstractSceneManager.hpp>
#include <Scene/AbstractScene.hpp>

class MenuScene;
class GameScene;
class CharacterSelectScene;

class SceneManager : public AbstractSceneManager
{
public:
	SceneManager();
	~SceneManager();	

	void Update(sf::Time deltaT);
	void Render(sf::RenderWindow* window);
	SceneType GetCurrentSceneType() const { return m_currentSceneEnum; };

	void ChangeScene(SceneType newScene) override;

private:
	AbstractScene* m_currentScene;
	MenuScene* m_menuScene;
	GameScene* m_gameScene;
	CharacterSelectScene* m_characterScene;
	SceneType m_currentSceneEnum;
};