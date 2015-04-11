#include <Game.hpp>

#include <SFML/Graphics.hpp>
#include <Scene/Impl/SceneManager.hpp>

Game::Game() :
m_shutdownState(ShutdownState::UNKNOWN),
m_sceneManager(nullptr)
{
	m_sceneManager = new SceneManager();
	m_window = new sf::RenderWindow(sf::VideoMode(800, 600), "GameName");
}

Game::~Game()
{

}


void Game::Initialize()
{

}

ShutdownState Game::Run()
{
	sf::Clock clock;
	
	while (m_window->isOpen())
	{
		Update();
		Render();

		sf::Event event;
		while (m_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window->close();
		}

		m_window->clear();
		m_window->display();
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

	m_sceneManager->Render(m_window);
}

void Game::SetShutdownState(ShutdownState newState)
{

}

void Game::Shutdown()
{

}