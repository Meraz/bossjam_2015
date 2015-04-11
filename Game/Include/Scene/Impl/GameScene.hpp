#pragma once
#include <Scene/Impl/BaseScene.hpp>
#include <Player.hpp>
#include <vector>

#include <Entity/Impl/BaseEntity.hpp>
class GameScene : public BaseScene
{
public:
	GameScene();
	~GameScene();

	void Update(float deltaT) override;
	void Render(sf::RenderWindow* window) override;

private:
	BaseEntity* test;
	
	std::vector<Player*> m_players;
	int playerCount;


};