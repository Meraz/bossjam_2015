#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class AbstractEntity;

class Grid
{
public:
	Grid();
	virtual ~Grid();
	void Initialize(const std::string& filePath);

	bool SaveGrid(const std::string& filePath);
	bool SaveGrid();
	
	void Update(float deltaT);
	void Render(sf::RenderWindow* window);

private:
	bool LoadGrid(const std::string& filePath);

	AbstractEntity* EvaluateRGB(size_t r, size_t g, size_t b);
	
	std::string m_filePath;
	
	AbstractEntity* m_grid;
	size_t m_countWidth;
	size_t m_countHeight;
};