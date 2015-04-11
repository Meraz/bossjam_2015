#include <Scene/Impl/GameScene.hpp>

GameScene::GameScene()
: BaseScene(SceneType::GAME)
{
	test = new BaseEntity();
	test->Initialize(50,50);

	m_player1 = new Player(1, 10, 10, 10, 10, 10, 10);
	m_player2 = new Player(2, 10, 10, 10, 10, 10, 10);
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

	m_player1->Render(window);
	//m_player2->Render(window);
}