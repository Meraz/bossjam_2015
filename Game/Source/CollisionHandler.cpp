#include "CollisionHandler.hpp"


CollisionHandler::CollisionHandler()
{
}

CollisionHandler::~CollisionHandler()
{
}

bool CollisionHandler::IsIntersecting(const sf::FloatRect& a, const sf::FloatRect& b)
{
	return a.intersects(b);
	/*
	float aMidx = a.left + a.width / 2.f;
	float aMidy = a.top + a.height / 2.f;
	float bMidx = b.left + b.height / 2.f;
	float bMidy = b.top + b.width / 2.f;
	
	return (abs(aMidx - bMidx) * 2 < (a.getSize().x + b.getSize().x)) &&
		(abs(aMidy - bMidy) * 2 < (a.getSize().y + b.getSize().y));
		*/
}

sf::Vector2f CollisionHandler::GetIntersectionVector(const sf::FloatRect& a, const sf::FloatRect& b)
{
	//Check intersect
	if (IsIntersecting(a, b))
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
	/*
	float ax = a.left;
	float ay = a.top;
	float axw = a.left + a.getSize().x;
	float ayh = a.top + a.getSize().y;

	float bx = b.left;
	float by = b.top;
	float bxw = b.left + b.getSize().x;
	float byh = b.top + b.getSize().y;

	float intX = std::max(0.f, std::min(axw, bxw) - std::max(ax, bx));
	float intY = std::max(0.f, std::min(ayh, byh) - std::max(ay, by));

	intRect.setSize(sf::Vector2f(intX, intY));
	intRect.setPosition(sf::Vector2f(std::max(ax, bx), std::max(ay, by)));

	return intRect;

	*/
}