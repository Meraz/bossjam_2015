#include <Level/Level.hpp>

#include <Entity/AbstractEntity.hpp>

#include <iostream>
#include <fstream>

Grid::Grid()
:
m_grid(nullptr),
m_countWidth(0),
m_countHeight(0)
{

}

Grid::~Grid()
{

}

void Grid::Initialize(const std::string& filePath)
{
	LoadGrid(filePath);
}


bool Grid::LoadGrid(const std::string& filePath)
{



	return false;
}

bool Grid::SaveGrid()
{
	return SaveGrid(m_filePath);
}

bool Grid::SaveGrid(const std::string& filePath)
{
	using namespace std; 
	ofstream file;
	file.open(filePath);
	file << "P3";
	file << m_countWidth << " " << m_countHeight << endl;
	file << "255" << endl;
	for (size_t i = 0; i < m_countHeight; ++i)
	{
		for (size_t j = 0; j < m_countWidth; ++j)
		{
			file << m_grid[m_countHeight*i + j].color;
		}
	}
	return false;
}
