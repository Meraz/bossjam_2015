#include <Scene/Impl/CharacterSelectScene.hpp>
#include <PlayerContext.hpp>
#include <Player.hpp>

CharacterSelectScene::CharacterSelectScene()
: BaseScene(SceneType::CHARSELECT)
{
	m_totalCharacters = 5; //Including Character NONE
	m_totalColors = 4;
	InitSelectableCharacters();
}

CharacterSelectScene::~CharacterSelectScene()
{
}

void CharacterSelectScene::InitSelectableCharacters()
{
	for (size_t x = 0; x < m_totalCharacters; x++)
	{
		for (size_t y = 0; y < m_totalColors; y++)
		{
			std::string name = "portrait_" + std::to_string(x);
			if (x == 0)
			{
				//Set all these portaits to NONE/inactive/not in game/whatever
			}
			else
			{
				//Set portrait to portrait_x_y.png
				name.append(std::to_string(y) + ".png");
			}
		}
	}
}


void CharacterSelectScene::Update(float deltaTime)
{
	//get input from all controllers
	for (size_t i = 0; i < 4; i++)
	{
		Player* curPlayer = PlayerContext::GetPlayerContext()->GetPlayer(i);
		
	}
	//if A: add to active players
	//if A and is active: lock character
	//if A and all active players characters are locked: start game

	//if B and is active: remove from active characters
	//if B and has locked character: unlock
	//if B and no locked characters: back to prev scene (rule select?)

	//if right (and active and not locked): select next character
	//if left (and active and not locked): select prev character

	//if rButton (and active and not locked): select next color
	//if lButton (and active and not locked): select prev color
}

void CharacterSelectScene::Render(sf::RenderWindow* window)
{

}

void CharacterSelectScene::SelectNextCharacter(int playerID)
{
	m_players[playerID].chosenChar.x++;
	if (m_players[playerID].chosenChar.x == m_totalCharacters)
		m_players[playerID].chosenChar.x = 1; // 0 is the none character
}

void CharacterSelectScene::SelectPrevCharacter(int playerID)
{
	m_players[playerID].chosenChar.x--;
	if (m_players[playerID].chosenChar.x == 0) // 0 is the none character
		m_players[playerID].chosenChar.x = m_totalCharacters - 1;
}

void CharacterSelectScene::SelectNextColor(int playerID)
{
	m_players[playerID].chosenChar.y = GetNextAvailableColor(m_players[playerID].chosenChar.x, m_players[playerID].chosenChar.y);
}

void CharacterSelectScene::SelectPrevColor(int playerID)
{
	m_players[playerID].chosenChar.y = GetPrevAvailableColor(m_players[playerID].chosenChar.x, m_players[playerID].chosenChar.y);
}

int CharacterSelectScene::GetNextAvailableColor(int character, int currentColor)
{
	int wantColor = currentColor + 1;
	if (wantColor == m_totalColors)
		wantColor = 0;
	while (wantColor != currentColor)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (m_players[i].chosenChar.x != character)
				continue;
			if (m_players[i].chosenChar.y == wantColor)
				break;
		}
		wantColor++;
		if (wantColor == m_totalColors)
			wantColor = 0;
	}
	return currentColor;
}

int CharacterSelectScene::GetPrevAvailableColor(int character, int currentColor)
{
	int wantColor = currentColor - 1;
	if (wantColor == 0)
		wantColor = m_totalColors;
	while (wantColor != currentColor)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (m_players[i].chosenChar.x != character)
				continue;
			if (m_players[i].chosenChar.y == wantColor)
				break;
		}
		wantColor--;
		if (wantColor == 0)
			wantColor = m_totalColors;
	}
	return currentColor;
}