#pragma once
#include <Scene/AbstractScene.hpp>

class BaseScene : public AbstractScene
{
public:
	BaseScene(SceneType sceneType);
	virtual ~BaseScene();

	SceneType GetSceneType() override { return m_sceneType; }
	virtual void Update(sf::Time deltaT) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;

private:
	SceneType m_sceneType;
};