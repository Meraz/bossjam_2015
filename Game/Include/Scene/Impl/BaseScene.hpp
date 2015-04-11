#pragma once
#include <Scene/AbstractScene.hpp>
#include <Scene/AbstractSceneManager.hpp>

class BaseScene : public AbstractScene
{
public:
	BaseScene(SceneType sceneType, AbstractSceneManager* sceneManager);
	virtual ~BaseScene();

	SceneType GetSceneType() override { return m_sceneType; }
	virtual void Update(sf::Time deltaT) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	virtual void ChangeScene(SceneType sceneType);

protected:
	AbstractSceneManager* m_sceneManager;

private:
	SceneType m_sceneType;
};