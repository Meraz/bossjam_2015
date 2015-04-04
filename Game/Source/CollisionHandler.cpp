#include <Collision/CollisionHandler.hpp>


CollisionHandler::CollisionHandler()
{
}

CollisionHandler::~CollisionHandler()
{
}

bool CollisionHandler::AreBoxesIntersecting(const sf::FloatRect& a, const sf::FloatRect& b)
{
	return a.intersects(b);
}

sf::Vector2f CollisionHandler::GetIntersectionVector(const sf::FloatRect& a, const sf::FloatRect& b)
{
	//Check intersect
	if (AreBoxesIntersecting(a, b))
	{
		sf::Vector2f corVec;
		//Get intersect box
		sf::FloatRect intersectBox = GetIntersectingBox(a, b);
		//get vector playerbox -> colbox/intersectbox
		sf::Vector2f rectOrigin(sf::Vector2f(a.left, a.top) + sf::Vector2f(a.width, a.height) / 2.f);
		sf::Vector2f colOrigin(sf::Vector2f(b.left, b.top) + sf::Vector2f(b.width, b.height) / 2.f);
		sf::Vector2f colVec = colOrigin - rectOrigin;

		//Check smallest side
		if (intersectBox.width < intersectBox.height)
		{
			if (colVec.x < 0) // Col on left side
				corVec.x = intersectBox.width; // Move to the right

			else if (colVec.x > 0)// Col on right side
				corVec.x = -intersectBox.width;// Move to the left
		}
		else if (intersectBox.width > intersectBox.height)
		{
			if (colVec.y < 0)// Col on top side
				corVec.y = intersectBox.height;// Move to the right

			else if (colVec.y > 0)// Col on bottom side
				corVec.y = -intersectBox.height;// Move to the left
		}
		else
		{
			if (colVec.x < 0)
				corVec.x = intersectBox.width;
			else if (colVec.x > 0)
				corVec.x = -intersectBox.width;

			if (colVec.y < 0)
				corVec.y = intersectBox.height;
			else if (colVec.y > 0)
				corVec.y = -intersectBox.height;
		}
		return corVec;
	}
	else
	{
		return sf::Vector2f(0.f, 0.f);
	}
}

sf::FloatRect CollisionHandler::GetIntersectingBox(const sf::FloatRect& a, const sf::FloatRect& b)
{
	sf::FloatRect intRect;
	a.intersects(b, intRect);
	return intRect;
}