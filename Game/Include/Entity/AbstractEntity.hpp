#pragma once

#include <SFML/Graphics.hpp>
#include <System/ColorCoding.hpp>

class AbstractEntity
{
public:
	virtual void Initialize(float posX, float posY) = 0;
	virtual void Update(float deltaT) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;

	virtual const ColorCoding& GetColor() = 0;
};