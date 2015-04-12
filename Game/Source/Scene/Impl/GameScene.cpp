#include <Scene/Impl/GameScene.hpp>

#include <Player.hpp>
#include <Level/Level.hpp>

GameScene::GameScene(AbstractSceneManager* sceneManager)
: BaseScene(SceneType::GAME, sceneManager)
{
	playerCount = 0;

	m_backgroundTexture.loadFromFile("forest_background.png");
	m_backGroundRectangle = sf::RectangleShape(sf::Vector2f(1280, 720));
	m_backGroundRectangle.setTexture(&m_backgroundTexture);

	m_scoreTexture.loadFromFile("Simple_ui_forest.png");
	m_scoreRectangle = sf::RectangleShape(sf::Vector2f(1280, 720));
	m_scoreRectangle.setTexture(&m_scoreTexture);
	
	sf::Texture temp1;
	temp1.loadFromFile("ui_spritesheet_live.png");
	m_uiPlayerTexture.push_back(temp1);
	sf::RectangleShape temp2 = sf::RectangleShape(sf::Vector2f(75, 75));
	temp2.setTextureRect(sf::IntRect(0, 0, 75, 75));
	temp2.move(213, 0);
	m_uiPlayerRect.push_back(temp2);
	m_uiPlayerRect.at(0).setTexture(&m_uiPlayerTexture.at(0));

	temp2 = sf::RectangleShape(sf::Vector2f(75, 75));
	temp2.setTextureRect(sf::IntRect(0, 0, 75, 75));
	temp2.move(414, 0);
	m_uiPlayerRect.push_back(temp2);
	m_uiPlayerRect.at(1).setTexture(&m_uiPlayerTexture.at(0));

	temp2 = sf::RectangleShape(sf::Vector2f(75, 75));
	temp2.setTextureRect(sf::IntRect(0, 0, 75, 75));
	temp2.move(830, 0);
	m_uiPlayerRect.push_back(temp2);
	m_uiPlayerRect.at(2).setTexture(&m_uiPlayerTexture.at(0));

	temp2 = sf::RectangleShape(sf::Vector2f(75, 75));
	temp2.setTextureRect(sf::IntRect(0, 0, 75, 75));
	temp2.move(1026, 0);
	m_uiPlayerRect.push_back(temp2);
	m_uiPlayerRect.at(3).setTexture(&m_uiPlayerTexture.at(0));

	m_level = new Level();
	m_level->Initialize("Levels/Level-Platforms.ppm");

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
	window->draw(m_scoreRectangle);
	window->draw(m_uiPlayerRect.at(0));
	window->draw(m_uiPlayerRect.at(1));
	window->draw(m_uiPlayerRect.at(2));
	window->draw(m_uiPlayerRect.at(3));

	m_level->Render(window);

	for (int i = 0; i < playerCount; ++i)
	{
		m_players.at(i)->Render(window);
	}
}
