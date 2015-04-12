#include <Scene/Impl/GameScene.hpp>
#include <PlayerContext.hpp>
#include <Player.hpp>
#include <Level/Level.hpp>
#include <System/Text.hpp>
#include <Audio/MusicManager.hpp>

GameScene::GameScene(AbstractSceneManager* sceneManager)
: BaseScene(SceneType::GAME, sceneManager)
{
	srand(reinterpret_cast<unsigned int>(this));
	if (rand() % 2 == 0)
	{
		MusicManager::GetMusicManagerContext()->PlaySongExclusiveFromStart("Audio/bensound-happyrock.flac");
		MusicManager::GetMusicManagerContext()->SetVolume("Audio/bensound-happyrock.flac", 10);
		// Djungle
	}
	else 
	{
		MusicManager::GetMusicManagerContext()->PlaySongExclusiveFromStart("Audio/bensound-happyrock.flac");
		MusicManager::GetMusicManagerContext()->SetVolume("Audio/bensound-happyrock.flac", 10);

		//city
	}
	playerCount = PlayerContext::GetPlayerContext()->NrOfActivePlayers;

	m_backgroundTexture.loadFromFile("forest_background.png");
	m_backGroundRectangle = sf::RectangleShape(sf::Vector2f(1280, 720));
	m_backGroundRectangle.setTexture(&m_backgroundTexture);

	m_scoreTexture.loadFromFile("Simple_ui_forest.png");
	m_scoreRectangle = sf::RectangleShape(sf::Vector2f(1280, 720));
	m_scoreRectangle.setTexture(&m_scoreTexture);
	
	m_level = new Level();
	m_level->Initialize("Levels/Level-Platforms.ppm");


	m_maxGameTime = 120.f;
	m_startAndEndDelay = 2.f;
	m_gameTimer = m_maxGameTime + m_startAndEndDelay;

	for (size_t i = 0; i < 4; i++)
	{
		if (PlayerContext::GetPlayerContext()->GetPlayer(i)->GetColor() >= 0)
			m_players.push_back(PlayerContext::GetPlayerContext()->GetPlayer(i));
	}

	for (size_t i = 0; i < PlayerContext::GetPlayerContext()->NrOfActivePlayers; i++)
	{
		sf::Texture temp1;
		temp1.loadFromFile("ui_spritesheet_live.png");
		m_uiPlayerTexture.push_back(temp1);
		sf::RectangleShape temp2 = sf::RectangleShape(sf::Vector2f(75, 75));
		temp2.setTextureRect(sf::IntRect(PlayerContext::GetPlayerContext()->GetPlayer(i)->GetFlag() * 75, PlayerContext::GetPlayerContext()->GetPlayer(i)->GetAnimal() * 75, 75, 75));
		switch (i)
		{
		case(0) :
			temp2.move(213, 0);
			break;
		case(1) :
			temp2.move(414, 0);
			break;
		case(2) :
			temp2.move(830, 0);
			break;
		case(3) :
			temp2.move(1026, 0);
			break;
		}

		m_uiPlayerRect.push_back(temp2);
		m_uiPlayerRect.at(i).setTexture(&m_uiPlayerTexture.at(0));
	}
}

GameScene::~GameScene()
{

}

void GameScene::Update(sf::Time deltaT)
{
	if (m_gameTimer > 0.f && m_gameTimer < m_maxGameTime)
	{
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
	else if (m_gameTimer > 0.f)
	{
		//Start of game, pause for a while 
	}
	else if (m_gameTimer > -m_startAndEndDelay)
	{
		//End of game, pause here for a while maybe?
	}
	else
	{
		m_sceneManager->ChangeScene(SceneType::CHARSELECT);
	}
	m_gameTimer -= deltaT.asSeconds();
}

void GameScene::Render(sf::RenderWindow* window)
{
	window->draw(m_backGroundRectangle);
	window->draw(m_scoreRectangle);

	for (size_t i = 0; i < PlayerContext::GetPlayerContext()->NrOfActivePlayers; i++)
	{
		window->draw(m_uiPlayerRect.at(i));
	}

	m_level->Render(window);

	for (int i = 0; i < playerCount; ++i)
	{
		m_players.at(i)->Render(window);
	}

	//Draw timer
	Text time;
	time.Init("", sf::Color::White, sf::Vector2f(window->getSize().x / 2.f-10.f, 7.f));
	int minutes = (int)(m_gameTimer / 60);
	int seconds = (int)m_gameTimer % 60;
	int tenth = (int)(10 * (m_gameTimer - (int)m_gameTimer));
	if (m_gameTimer > 0 && m_gameTimer < m_maxGameTime)
	{
		std::string extraZero = "";
		if (seconds < 10)
			extraZero = "0";
		std::string print = std::to_string(minutes) + ":" + extraZero + std::to_string(seconds) + "." + std::to_string(tenth);
		time.SetText(print);
	}
	else if (m_gameTimer > 0)
	{
		std::string print = std::to_string(seconds - (int)m_maxGameTime%60) + "." + std::to_string(tenth);
		time.SetText(print);
	}
	else
	{
		time.SetText("END");
	}
	window->draw(time.GetText());
}
