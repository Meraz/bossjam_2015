#include <Level/Level.hpp>

#include <iostream>

Level::Level()
:
m_grid(nullptr)
{

}

Level::~Level()
{
	delete m_grid;
}

void Level::Initialize(const std::string& filePath)
{
	if (m_grid)
	{
		std::cout << "Error, level already created" << std::endl;
		return;
	}
	LoadFile(filePath);
}

void Level::LoadFile(const std::string& filePath)
{
	m_grid = new Grid();
	m_grid->Initialize(filePath);
}
