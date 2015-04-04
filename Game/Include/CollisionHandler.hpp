#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

class CollisionHandler
{
public:
	CollisionHandler();
	~CollisionHandler();

	bool IsIntersecting(sf::RectangleShape a, sf::RectangleShape b);
	sf::Vector2f GetIntersectionVector(sf::RectangleShape a, sf::RectangleShape b);
	sf::RectangleShape GetIntersectingBox(sf::RectangleShape a, sf::RectangleShape b);
private:
};

#endif