#pragma once

#include <Scene/SceneType.hpp>

#include <SFML/Graphics.hpp>

class AbstractScene
{
public:
	virtual SceneType GetSceneType() = 0;
	virtual void Update(sf::Time deltaT) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
};