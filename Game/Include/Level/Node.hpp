#pragma once
#include <vector>
#include <SFML/Graphics/Rect.hpp>

class BaseEntity;

class Node
{
public:
	Node();
	virtual ~Node();
	void Initialize(sf::FloatRect p_rectangle);

	void AddEntity(BaseEntity* p_entity);
	std::vector<BaseEntity*>* FindNearObjects(sf::FloatRect rectangle, std::vector<BaseEntity*>* destinationVector);

private:
	void Subdivide();
	void MoveOneEntityDown(BaseEntity* p_entity);

	sf::FloatRect CalculateRectangleForchild(unsigned int p_index);

private:
	sf::FloatRect m_rectangle;

	std::vector<BaseEntity*> m_entity;
	Node* m_child[4];
	bool m_leafAvailable;
};