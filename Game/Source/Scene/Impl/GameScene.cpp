#include <Scene/Impl/GameScene.hpp>
#include <PlayerContext.hpp>
#include <Player.hpp>
#include <Level/Level.hpp>

GameScene::GameScene(AbstractSceneManager* sceneManager)
: BaseScene(SceneType::GAME, sceneManager)
{
	playerCount = PlayerContext::GetPlayerContext()->NrOfActivePlayers;

	m_backgroundTexture.loadFromFile("forest_background.png");
	m_backGroundRectangle = sf::RectangleShape(sf::Vector2f(1280, 720));
	m_backGroundRectangle.setTexture(&m_backgroundTexture);

	m_level = new Level();
	m_level->Initialize("Levels/Level-Platforms.ppm");

	for (size_t i = 0; i < 4; i++)
	{
		if (PlayerContext::GetPlayerContext()->GetPlayer(i)->GetColor() >= 0)
			m_players.push_back(PlayerContext::GetPlayerContext()->GetPlayer(i));
	}
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
		m_players.at(i)->LoadStats(m_players.at(i)->GetScriptName());
		all = m_level->GetAllObjects();
		for (int j = 0; j < all->size(); ++j)
		{
			if (all->at(j)->GetType() != EntityType::EMPTY && !m_players.at(i)->IsDead())
			{
				m_players.at(i)->CollisionEvent(collisionHandler.GetIntersectionVector(m_players.at(i)->getCollisionRect(), all->at(j)->getCollisionRect()));
			}
		}

		for (int j = 0; j < playerCount; ++j)
		{
			if (i != j && !m_players.at(i)->IsDead() && !m_players.at(j)->IsDead())
			{
				m_players.at(i)->PlayerCollisionEvent(collisionHandler.GetIntersectionVector(m_players.at(i)->getCollisionRect(), m_players.at(j)->getCollisionRect()));
			}
		}
	}
}

void GameScene::Render(sf::RenderWindow* window)
{

	window->draw(m_backGroundRectangle);

	m_level->Render(window);

	for (int i = 0; i < playerCount; ++i)
	{
		m_players.at(i)->Render(window);
	}
}
