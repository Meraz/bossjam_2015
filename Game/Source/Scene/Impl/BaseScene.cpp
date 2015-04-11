#include <Scene/Impl/BaseScene.hpp>

BaseScene::BaseScene(SceneType sceneType, AbstractSceneManager* sceneManager)
{
	m_sceneType = sceneType;
	m_sceneManager = sceneManager;
}

BaseScene::~BaseScene()
{
	 
}

void BaseScene::ChangeScene(SceneType sceneType)
{
	m_sceneManager->ChangeScene(sceneType);
}
