#include <Game.hpp>

#include <SFML/Graphics.hpp>
#include <Scene/Impl/SceneManager.hpp>

Game::Game() :
m_shutdownState(ShutdownState::UNKNOWN),
m_sceneManager(nullptr)
{
	m_sceneManager = new SceneManager();
}

Game::~Game()
{

}


void Game::Initialize()
{

}

ShutdownState Game::Run()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "GameName");
	sf::Clock clock;
	
	while (window.isOpen())
	{
		Update();
		Render();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.display();
	}
	return m_shutdownState;
}

void Game::CleanUp()
{

}

void Game::Update()
{
	float deltaT = m_clock.restart().asSeconds();
	m_sceneManager->Update(deltaT);
}

void Game::Render()
{
	m_sceneManager->Render();
}

void Game::SetShutdownState(ShutdownState newState)
{

}

void Game::Shutdown()
{

}