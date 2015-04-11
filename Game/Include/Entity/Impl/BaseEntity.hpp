#pragma once

#include <System/ColorCoding.hpp>
#include <Entity/Impl/EntityType.hpp>
#include <SFML/Graphics.hpp>
#define TILE_SIZE 50


class BaseEntity 
{
public:
	BaseEntity(EntityType type);
	~BaseEntity();

	void Initialize(float posX, float posY, const std::string& texturePath);

	void setSize(int sizeX, int sizeY);
	virtual sf::FloatRect getCollisionRect();

	virtual void Update(sf::Time deltaT);
	virtual void Render(sf::RenderWindow* window);
	
	const ColorCoding& GetColor() { return m_color; }

	EntityType GetType() { return m_type; }

protected:
	ColorCoding m_color;
	sf::Texture m_texture;
	sf::RectangleShape m_shape;
	EntityType m_type;
};