#include <Scene/Impl/GameScene.hpp>

#include <Player.hpp>
#include <Level/Level.hpp>

GameScene::GameScene()
: BaseScene(SceneType::GAME)
{
	playerCount = 0;

	m_level = new Level();
	m_level->Initialize("Levels/Level0.ppm");

	m_players.push_back(new Player(playerCount++));
	m_players.push_back(new Player(playerCount++));

	m_players.at(0)->LoadInitStats("CharacterScripts/tiger.lua");
	m_players.at(1)->LoadInitStats("CharacterScripts/tiger.lua");
}

GameScene::~GameScene()
{

}

void GameScene::Update(sf::Time deltaT)
{
	sf::FloatRect test = m_players.at(0)->getCollisionRect();
	std::vector<BaseEntity*>* all;
	for (int i = 0; i < playerCount; ++i)
	{
		m_players.at(i)->Update(deltaT);
		m_players.at(i)->LoadStats("CharacterScripts/tiger.lua");
		all = m_level->GetAllObjects();
		for (int j = 0; j < all->size(); ++j)
		{
			if (all->at(j)->GetType() != EntityType::EMPTY)
			{
				m_players.at(i)->CollisionEvent(collisionHandler.GetIntersectionVector(m_players.at(i)->getCollisionRect(), all->at(j)->getCollisionRect()));
			}
		}
	}
}

void GameScene::Render(sf::RenderWindow* window)
{
	m_level->Render(window);

	for (int i = 0; i < playerCount; ++i)
	{
		m_players.at(i)->Render(window);
	}
}
