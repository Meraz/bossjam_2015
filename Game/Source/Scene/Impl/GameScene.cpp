#include <Scene/Impl/GameScene.hpp>

GameScene::GameScene()
: BaseScene(SceneType::GAME)
{
	playerCount = 0;

	m_world.push_back(new BaseEntity());
	m_world.at(0)->Initialize(0, 550);
	m_world.at(0)->setSize(800, 50);

	m_players.push_back(new Player(playerCount++, 10, 10, 10, 10, 10, 10));
	m_players.push_back(new Player(playerCount++, 10, 10, 10, 10, 10, 10));
}

GameScene::~GameScene()
{

}

void GameScene::Update(float deltaTime)
{
	for (int i = 0; i < playerCount; ++i)
	{
		m_players.at(i)->Update(deltaTime);
	}
}

void GameScene::Render(sf::RenderWindow* window)
{
	m_world.at(0)->Render(window);

	for (int i = 0; i < playerCount; ++i)
	{
		m_players.at(i)->Render(window);
	}
}