#pragma once

#include <Entity/AbstractEntity.hpp>
#include <sstream>
#include <ostream>

class BaseEntity : public AbstractEntity
{
public:
	BaseEntity();
	~BaseEntity();

	void Initialize(float posX, float posY) override;

	void Update(float deltaT) override;
	void Render(sf::RenderWindow* window) override;
	
	const ColorCoding& GetColor() override { return m_color; }

	void setSize(int sizeX, int sizeY);

protected:
	
	ColorCoding m_color;
	sf::Texture m_texture;
	sf::RectangleShape m_shape;
};