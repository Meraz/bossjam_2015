#include <Entity/Impl/BaseEntity.hpp>
#include <sstream>

BaseEntity::BaseEntity(EntityType type):
m_shape(sf::Vector2f(TILE_SIZE, TILE_SIZE)),
m_type(type)
{
}

BaseEntity::~BaseEntity()
{

}

void BaseEntity::Initialize(float posX, float posY, const std::string& texturePath)
{
	m_texture.loadFromFile(texturePath);
	m_shape.setTexture(&m_texture);
	m_shape.setPosition(sf::Vector2f(posX+25, posY));
}

void BaseEntity::Update(sf::Time deltaT)
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

sf::FloatRect BaseEntity::getCollisionRect()
{
	return m_shape.getGlobalBounds();
}