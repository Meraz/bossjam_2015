#pragma once
#include <Scene/AbstractScene.hpp>

class BaseScene : public AbstractScene
{
public:
	BaseScene(SceneType sceneType);
	virtual ~BaseScene();

	SceneType GetSceneType() override { return m_sceneType; }
	virtual void Update(float deltaT) override;
	virtual void Render(sf::RenderWindow* window) override;

private:
	SceneType m_sceneType;
};