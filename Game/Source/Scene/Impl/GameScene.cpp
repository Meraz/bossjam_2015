#include <Scene/Impl/GameScene.hpp>

#include <Player.hpp>
#include <Level/Level.hpp>

GameScene::GameScene()
: BaseScene(SceneType::GAME)
{
	m_level = new Level();
	m_level->Initialize("test.ppm");

	m_player1 = new Player(1);
	m_player2 = new Player(2);

	m_player1->LoadStats("tiger.lua");
	m_player2->LoadStats("tiger.lua");
}

GameScene::~GameScene()
{

}

void GameScene::Update(float deltaTime)
{

}

void GameScene::Render(sf::RenderWindow* window)
{
	m_level->Render(window);
	std::vector<BaseEntity*>* all = new std::vector<BaseEntity*>;
	all = m_level->FindNearObjects(sf::FloatRect(sf::Vector2f(0,0), sf::Vector2f(50,50)), all);
	//m_player1->Render(window);
	//m_player2->Render(window);
}