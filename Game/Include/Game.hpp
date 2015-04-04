#pragma once

#include <ShutdownState.hpp>
#include <AbstractGame.hpp>
#include <Scene/Impl/SceneManager.hpp>
#include <SFML/System/Clock.hpp>

class Game : AbstractGame
{
public:
	Game();
	~Game();

	void Initialize();
	ShutdownState Run();
	void CleanUp();

	void SetShutdownState(ShutdownState newState) override;
	void Shutdown() override;
	
private:
	void Update();
	void Render();

private:
	ShutdownState m_shutdownState;
	SceneManager* m_sceneManager;
	sf::Clock m_clock;
};