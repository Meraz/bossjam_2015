#include <Scene/Impl/GameScene.hpp>

#include <Player.hpp>
#include <Level/Level.hpp>

GameScene::GameScene()
: BaseScene(SceneType::GAME)
{
	playerCount = 0;

	//m_world.push_back(new BaseEntity());
	//m_world.at(0)->Initialize(0, 550);
	//m_world.at(0)->setSize(800, 50);


	m_level = new Level();
	m_level->Initialize("test.ppm");

	m_players.push_back(new Player(playerCount++));
	m_players.push_back(new Player(playerCount++));

	m_players.at(0)->LoadStats("tiger.lua");
	m_players.at(1)->LoadStats("tiger.lua");
}

GameScene::~GameScene()
{

}

void GameScene::Update(float deltaTime)
{
	sf::FloatRect test = m_players.at(0)->getCollisionRect();
	for (int i = 0; i < playerCount; ++i)
	{
		m_players.at(i)->Update(deltaTime);
		//m_players.at(i)->CollisionEvent(collisionHandler.GetIntersectionVector(m_players.at(i)->getCollisionRect(), m_world.at(0)->getCollisionRect()));
	}

}

void GameScene::Render(sf::RenderWindow* window)
{
	//m_world.at(0)->Render(window);

	for (int i = 0; i < playerCount; ++i)
	{
		m_players.at(i)->Render(window);
	}

	m_level->Render(window);
	std::vector<BaseEntity*>* all = new std::vector<BaseEntity*>;
	all = m_level->FindNearObjects(sf::FloatRect(sf::Vector2f(0,0), sf::Vector2f(50,50)), all);
}
