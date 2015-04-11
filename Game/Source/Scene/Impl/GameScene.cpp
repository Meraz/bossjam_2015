#include <Scene/Impl/GameScene.hpp>

GameScene::GameScene()
: BaseScene(SceneType::GAME)
{
	test = new BaseEntity();
	test->Initialize(50,50);
}

GameScene::~GameScene()
{

}

void GameScene::Update(float deltaTime)
{

}

void GameScene::Render(sf::RenderWindow* window)
{
	test->Render(window);
}