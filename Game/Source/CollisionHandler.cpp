#include "CollisionHandler.hpp"


CollisionHandler::CollisionHandler()
{
}

CollisionHandler::~CollisionHandler()
{
}

bool CollisionHandler::IsIntersecting(sf::RectangleShape a, sf::RectangleShape b)
{
	float aMidx = a.getPosition().x + a.getSize().x / 2.f;
	float aMidy = a.getPosition().y + a.getSize().y / 2.f;
	float bMidx = b.getPosition().x + b.getSize().x / 2.f;
	float bMidy = b.getPosition().y + b.getSize().y / 2.f;

	return (abs(aMidx - bMidx) * 2 < (a.getSize().x + b.getSize().x)) &&
		(abs(aMidy - bMidy) * 2 < (a.getSize().y + b.getSize().y));
}

sf::Vector2f CollisionHandler::GetIntersectionVector(sf::RectangleShape a, sf::RectangleShape b)
{
	//Check intersect
	if (IsIntersecting(a, b))
	{
		sf::Vector2f corVec;
		//Get intersect box
		sf::RectangleShape intersectBox = GetIntersectingBox(a, b);
		//get vector playerbox -> colbox/intersectbox
		sf::Vector2f rectOrigin(a.getPosition() + a.getSize() / 2.f);
		sf::Vector2f colOrigin(b.getPosition() + b.getSize() / 2.f);
		sf::Vector2f colVec = colOrigin - rectOrigin;

		//Check smallest side
		if (intersectBox.getSize().x < intersectBox.getSize().y)
		{
			if (colVec.x < 0)
			{
				//col on left side
				//Move to the right
				corVec.x = intersectBox.getSize().x;
			}
			else if (colVec.x > 0)
			{
				//col on right side
				//Move to the left
				corVec.x = -intersectBox.getSize().x;
			}
		}
		else if (intersectBox.getSize().x > intersectBox.getSize().y)
		{
			if (colVec.y < 0)
			{
				//col on top side
				//Move to the right
				corVec.y = intersectBox.getSize().y;
			}
			else if (colVec.y > 0)
			{
				//col on bottom side
				//Move to the left
				corVec.y = -intersectBox.getSize().y;
			}

		}
		return corVec;
	}
	else
	{
		return sf::Vector2f(0.f, 0.f);
	}
}

sf::RectangleShape CollisionHandler::GetIntersectingBox(sf::RectangleShape a, sf::RectangleShape b)
{
	sf::RectangleShape intRect;
	float ax = a.getPosition().x;
	float ay = a.getPosition().y;
	float axw = a.getPosition().x + a.getSize().x;
	float ayh = a.getPosition().y + a.getSize().y;

	float bx = b.getPosition().x;
	float by = b.getPosition().y;
	float bxw = b.getPosition().x + b.getSize().x;
	float byh = b.getPosition().y + b.getSize().y;

	float intX = std::max(0.f, std::min(axw, bxw) - std::max(ax, bx));
	float intY = std::max(0.f, std::min(ayh, byh) - std::max(ay, by));

	intRect.setSize(sf::Vector2f(intX, intY));
	intRect.setPosition(sf::Vector2f(std::max(ax, bx), std::max(ay, by)));

	return intRect;
}