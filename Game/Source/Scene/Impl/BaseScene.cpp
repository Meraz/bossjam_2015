#include <Scene/Impl/BaseScene.hpp>

BaseScene::BaseScene(SceneType sceneType)
{
	m_sceneType = sceneType;
}

BaseScene::~BaseScene()
{
	 
}

void BaseScene::Update(float deltaT)
{

}

void BaseScene::Render(sf::RenderWindow* m_window)
{

}