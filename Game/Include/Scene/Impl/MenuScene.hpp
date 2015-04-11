#pragma once
#include <Scene/Impl/BaseScene.hpp>

class MenuScene : public BaseScene
{
public:
	MenuScene();
	~MenuScene();

	void Update(sf::Time deltaT) override;
	void Render(sf::RenderWindow* window) override;

private:



};