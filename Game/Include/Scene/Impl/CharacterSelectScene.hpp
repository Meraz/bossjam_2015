#pragma once
#include <Scene/Impl/BaseScene.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics.hpp>

enum class CharacterClass
{
	NONE,
	TIGER,
	CHAR2,
	CHAR3,
	CHAR4
};

enum class CharacterColor
{
	COLOR1,
	COLOR2,
	COLOR3,
	COLOR4
};

struct SelectableCharacter
{
	CharacterClass charClass;
	CharacterColor charColor;
	sf::Texture portrait;
};

struct PlayerInfo
{
	sf::Vector2i chosenChar;
	bool isActive;
	bool isLocked;
};

class CharacterSelectScene : public BaseScene
{
public:
	CharacterSelectScene(AbstractSceneManager* sceneManager);
	~CharacterSelectScene();

	void Update(sf::Time deltaT) override;
	void Render(sf::RenderWindow* window) override;

private:
	int m_totalCharacters;
	int m_totalColors;
	SelectableCharacter m_allSelectableCharacters[5][4];
	PlayerInfo m_players[4];

	void InitSelectableCharacters();
	void SelectNextCharacter(int playerID);
	void SelectPrevCharacter(int playerID);
	void SelectNextColor(int playerID);
	void SelectPrevColor(int playerID);
	int GetNextAvailableColor(int character, int currentColor);
	int GetPrevAvailableColor(int character, int currentColor);

	void SetCharacterNamesToPlayer();

	sf::Texture m_backgroundTexture;
	sf::RectangleShape m_backGroundRectangle;
};