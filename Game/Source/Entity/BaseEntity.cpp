#include <Entity/Impl/BaseEntity.hpp>

BaseEntity::BaseEntity()
{
	m_shape = sf::RectangleShape(sf::Vector2f(50, 50));

	std::string name = "tile";
	std::stringstream stream;
	stream << name << "_r" << m_color.r << "_g" << m_color.g << "_b" << m_color.b << ".png";
	m_texture.loadFromFile(stream.str());
	m_shape.setTexture(&m_texture);
}

BaseEntity::~BaseEntity()
{

}

void BaseEntity::Initialize(float posX, float posY)
{
	m_shape.setPosition(sf::Vector2f(posX, posY));
}

void BaseEntity::Update(float deltaT)
{

}

void BaseEntity::Render(sf::RenderWindow* window)
{
	window->draw(m_shape);
}

void BaseEntity::setSize(int sizeX, int sizeY)
{
	m_shape.setSize(sf::Vector2f(sizeX, sizeY));
}