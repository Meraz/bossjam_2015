#pragma once

#include <SFML/Graphics.hpp>

class AbstractEntity
{
public:

	AbstractEntity(){ m_texture.loadFromFile("test.png"); }
	~AbstractEntity(){}

	size_t color;
	sf::Texture m_texture;
};