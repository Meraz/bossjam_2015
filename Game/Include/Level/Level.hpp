#pragma once
#include <string>
#include <vector>
#include <Level/Node.hpp>

#include <SFML/Graphics.hpp>
class AbstractEntity;

class Level
{
public:
	Level();
	virtual ~Level();
	void Initialize(const std::string& filePath);
	void Render(sf::RenderWindow* window);
	std::vector<BaseEntity*>* FindNearObjects(sf::FloatRect rectangle, std::vector<BaseEntity*>* destination);

private:
	Node* m_quadTree;
	std::vector<sf::Vector2i> m_spawnPositions;
	std::vector<sf::Vector2i> m_telePorterPositions;

	std::vector<BaseEntity*> m_all;

	void LoadFile(const std::string& filePath);
	void SaveFile(const std::string& filePath);
	BaseEntity* EvaluateTileDataFromFile(size_t r, size_t g, size_t b, size_t x, size_t y);
	bool PlayerSpawnCondition(size_t r, size_t g, size_t b);
	bool SimleWallCondition(size_t r, size_t g, size_t b);
	bool TeleporterCondition(size_t r, size_t g, size_t b);
	bool EmptyCondition(size_t r, size_t g, size_t b);
	std::string GetTextureFromColorCoding(size_t g);
};