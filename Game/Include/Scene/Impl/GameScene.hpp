#pragma once
#include <Scene/Impl/BaseScene.hpp>
#include <Player.hpp>
#include <vector>
#include <Collision\CollisionHandler.hpp>

class Level;
class Player;

class GameScene : public BaseScene
{
public:
	GameScene(AbstractSceneManager* sceneManager);
	~GameScene();

	void Update(sf::Time deltaT) override;

	void Render(sf::RenderWindow* window) override;

private:
	std::vector<Player*> m_players;
	int playerCount;

	Level* m_level;

	CollisionHandler collisionHandler; 

	sf::Texture m_backgroundTexture;
	sf::RectangleShape m_backGroundRectangle;

	sf::Texture m_scoreTexture;
	sf::RectangleShape m_scoreRectangle;

	std::vector<sf::Texture> m_uiPlayerTexture;
	std::vector<sf::RectangleShape> m_uiPlayerRect;
};