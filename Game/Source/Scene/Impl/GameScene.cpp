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
	m_level->Initialize("Levels/Level0.ppm");

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
	std::vector<BaseEntity*>* all = new std::vector<BaseEntity*>;
	for (int i = 0; i < playerCount; ++i)
	{
		m_players.at(i)->Update(deltaTime);
		m_players.at(i)->LoadStats("tiger.lua");
		all = m_level->FindNearObjects(m_players.at(i)->getCollisionRect(), all);
		for (int j = 0; j < all->size(); ++j)
		{
			m_players.at(i)->CollisionEvent(collisionHandler.GetIntersectionVector(m_players.at(i)->getCollisionRect(), all->at(j)->GetCollisionRectangle()));
		}
	}

	delete all;
}

void GameScene::Render(sf::RenderWindow* window)
{

	m_level->Render(window);

	for (int i = 0; i < playerCount; ++i)
	{
		m_players.at(i)->Render(window);
	}

}
