#include <Game.hpp>

#include <SFML/Graphics.hpp>
#include <Scene/Impl/SceneManager.hpp>

Game::Game() :
m_shutdownState(ShutdownState::UNKNOWN),
m_sceneManager(nullptr),
m_hasFocus(true)
{
	m_sceneManager = new SceneManager();
	m_window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Excruciating Funk Training");
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
	m_clock.restart().asSeconds();
	while (m_window->isOpen())
	{
		m_window->clear();

		if (m_hasFocus)
		{
			Update();
		}
		Render();
		m_window->display();

		sf::Event event;
		while (m_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window->close();
			}

			if (event.type == sf::Event::GainedFocus || event.type == sf::Event::LostFocus)
			{
				m_hasFocus = !m_hasFocus;
				m_clock.restart().asSeconds();
			}
		}
	}
	return m_shutdownState;
}

void Game::CleanUp()
{

}

void Game::Update()
{
	float deltaT = m_clock.restart().asSeconds();
	if (deltaT > 0.01f)
		return;
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