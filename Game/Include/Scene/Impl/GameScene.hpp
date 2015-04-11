#pragma once
#include <Scene/Impl/BaseScene.hpp>
#include <Player.hpp>

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

	Player* m_player1;
	Player* m_player2;


};