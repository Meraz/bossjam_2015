#include <Level/Level.hpp>

#include <Entity/Impl/BaseEntity.hpp>

#include <iostream>
#include <fstream>
#include <string>

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
	using namespace std;
	ifstream file(filePath);
	if(file.is_open())
	{
		string line;
		size_t width, height;
		width = height = 0;
		getline(file, line); // Magic number
		file >> width >> height; // width, height
		getline(file, line); // Max color size
		size_t r, g, b;
		r = g = b = 0;

		while (file >> r >> g >> b)
		{
			
			// process pair (a,b,c)
		}		
		file.close();
	}
	else
	{
		cout << "Error opening file" << endl;
	}

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
			file << m_grid[m_countHeight*i + j].GetColor();
		}
	}
	return false;
}

AbstractEntity* Grid::EvaluateRGB(size_t r, size_t g, size_t b)
{
	return new BaseEntity();
}

void Grid::Update(float deltaT)
{
	for (size_t y = 0; y < m_countHeight; ++y)
	{
		for (size_t x = 0; x < m_countWidth; ++x)
		{
			m_grid[y*m_countWidth + x].Update(deltaT);
		}
	}
}

void Grid::Render(sf::RenderWindow* window)
{
	for (size_t y = 0; y < m_countHeight; ++y)
	{
		for (size_t x = 0; x < m_countWidth; ++x)
		{
			m_grid[y*m_countWidth + x].Render(window);
		}
	}
}
