#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

class CollisionHandler
{
public:
	CollisionHandler();
	~CollisionHandler();

	bool AreBoxesIntersecting(const sf::FloatRect& a, const sf::FloatRect& b);
	sf::Vector2f GetIntersectionVector(const sf::FloatRect& a, const sf::FloatRect& b);
	sf::FloatRect GetIntersectingBox(const sf::FloatRect& a, const sf::FloatRect& b);
private:
};

#endif