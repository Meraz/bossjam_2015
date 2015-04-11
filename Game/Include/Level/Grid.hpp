#pragma once
#include <string>

class AbstractEntity;

class Grid
{
public:
	Grid();
	virtual ~Grid();
	void Initialize(const std::string& filePath);

	bool SaveGrid(const std::string& filePath);
	bool SaveGrid();

private:
	bool LoadGrid(const std::string& filePath);
	
	std::string m_filePath;
	
	AbstractEntity* m_grid;
	size_t m_countWidth;
	size_t m_countHeight;
};