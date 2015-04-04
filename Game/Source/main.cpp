#include <SFML/Graphics.hpp>
#include <Game.hpp>

int main()
{
	Game* game = nullptr;

	bool continueGame = true;

	while (continueGame)
	{
		game = new Game();
		game->Initialize();
		continueGame = false;

		if (game->Run() == ShutdownState::RESTART)
		{
			continueGame = true;
		}
		delete game;
	}

	return 0;
}