#pragma once
#include <string>
#include <Level/Grid.hpp>

class Level
{
public:
	Level();
	virtual ~Level();
	void Initialize(const std::string& filePath);

private:
	Grid* m_grid;

	void LoadFile(const std::string& filePath);
	void SaveFile(const std::string& filePath);
};