#pragma once
#include <Scene/Impl/BaseScene.hpp>
class Level;
class Player;

class GameScene : public BaseScene
{
public:
	GameScene();
	~GameScene();

	void Update(float deltaT) override;
	void Render(sf::RenderWindow* window) override;

private:
	Player* m_player1;
	Player* m_player2;
	Level* m_level;
	
};