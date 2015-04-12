#include <Scene/Impl/CharacterSelectScene.hpp>
#include <PlayerContext.hpp>
#include <Player.hpp>
#include <System/Text.hpp>
#include <XboxController.hpp>
#include <iostream>
#include <Audio/MusicManager.hpp>
#include <Audio/SoundManager.hpp>

CharacterSelectScene::CharacterSelectScene(AbstractSceneManager* sceneManager)
: BaseScene(SceneType::CHARSELECT, sceneManager)
{
	m_totalCharacters = 5; //Including Character NONE
	m_totalColors = 4;
	InitSelectableCharacters();

	for (size_t i = 0; i < 4; i++)
	{
		PlayerContext::GetPlayerContext()->GetPlayer(i);
		m_players[i].isActive = false;
		m_players[i].isLocked = false;
	}
	m_backgroundTexture.loadFromFile("FlamePainter_Background1.jpg");
	m_backGroundRectangle = sf::RectangleShape(sf::Vector2f(1280, 720));
	m_backGroundRectangle.setTexture(&m_backgroundTexture);
	MusicManager::GetMusicManagerContext()->PlaySong("Audio/PATGOIN_-_SPANISH_GUITAR.flac");
}

CharacterSelectScene::~CharacterSelectScene()
{
}

void CharacterSelectScene::InitSelectableCharacters()
{
	int size = 150;
	std::string name = "avatar_spritesheet_4.png";
	sf::Texture largeTex;
	largeTex.loadFromFile(name);
	for (size_t x = 0; x < m_totalCharacters; x++)
	{
		for (size_t y = 0; y < m_totalColors; y++)
		{
			if (x == 0)
			{
				//Set all these portaits to NONE/inactive/not in game/whatever
				m_allSelectableCharacters[x][y].portrait.loadFromFile("no_character.png");
			}
			else
			{
				//Set portrait to portrait_x_y.png
				m_allSelectableCharacters[x][y].portrait.loadFromFile(name, sf::IntRect(y*size, (x - 1)*size, size, size));
			}
			m_allSelectableCharacters[x][y].charClass = (CharacterClass)x;
			m_allSelectableCharacters[x][y].charColor = (CharacterColor)y;
		}
	}
}


void CharacterSelectScene::Update(sf::Time deltaT)
{
	//get input from all controllers
	for (size_t i = 0; i < 4; i++)
	{
		Player* curPlayer = PlayerContext::GetPlayerContext()->GetPlayer(i);
		XboxController* controller = curPlayer->GetController();
		controller->Update();
		
		if (controller->GetAButtonState().current && !controller->GetAButtonState().last)
		{
			//if A: add to active players
			if (!m_players[i].isActive)
			{
				m_players[i].isActive = true;
				m_players[i].chosenChar.x = 1;
				m_players[i].chosenChar.y = 3;
				SelectNextCharacter(i);
				GetNextAvailableColor(m_players[i].chosenChar.x, m_players[i].chosenChar.y);
			}
			//if A and is active: lock character
			else if (m_players[i].isActive)
			{			
				SoundManager::GetSoundManagerContext()->PlaySound("Audio/LockIn.flac");

				m_players[i].isLocked = true;
			}
			//if A and all active players characters are locked: start game
			if (m_players[i].isLocked)
			{
				bool allLocked = true;
				for (size_t j = 0; j < 4; j++)
				{
					if (!m_players[j].isActive)
						continue;
					allLocked = m_players[j].isLocked;
					if (!allLocked)
						break;
				}
				if (allLocked)
				{
					SetCharacterNamesToPlayer();
					m_sceneManager->ChangeScene(SceneType::GAME);
				}
			}
		}

		else if (controller->GetBButtonState().current && !controller->GetBButtonState().last)
		{
			//if B and is active: remove from active characters
			if (!m_players[i].isActive)
			{
				m_players[i].isActive = false;
			}
			//if B and has locked character: unlock
			else if (m_players[i].isActive)
			{
				m_players[i].isLocked = false;
			}
			//if B and no locked characters: back to prev scene (rule select?)
			if (!m_players[i].isLocked)
			{
				//Exit
			}
		}

		if (controller->GetLStickXState().current > 0.f && controller->GetLStickXState().last <= 0.f) // maybe?
		{
			//if right (and active and not locked): select next character
			if (m_players[i].isActive && !m_players[i].isLocked)
			{
				SelectNextCharacter(i);
			}
		}
		else if (controller->GetLStickXState().current < 0.f && controller->GetLStickXState().last >= 0.f) // maybe?
		{
			//if left (and active and not locked): select prev character
			if (m_players[i].isActive && !m_players[i].isLocked)
			{
				SelectPrevCharacter(i);
			}
		}

		if (controller->GetRBButtonState().current && !controller->GetRBButtonState().last)
		{
			//if rButton (and active and not locked): select next color
			if (m_players[i].isActive && !m_players[i].isLocked)
			{
				SelectNextColor(i);
			}

		}
		else if (controller->GetLBButtonState().current && !controller->GetLBButtonState().last)
		{
			//if lButton (and active and not locked): select prev color
			if (m_players[i].isActive && !m_players[i].isLocked)
			{
				SelectPrevColor(i);
			}
		}
	}
}

void CharacterSelectScene::Render(sf::RenderWindow* window)
{
	window->draw(m_backGroundRectangle);
	
	Text sceneTitle;
	sceneTitle.Init("Select Character", sf::Color::Yellow, sf::Vector2f(window->getSize().x / 2.f, 0.f));
	sceneTitle.SetPositionCenter(sf::Vector2f(window->getSize().x / 2.f, 20.f));
	sceneTitle.SetSize(50);
	window->draw(sceneTitle.GetText());

	float spacing = window->getSize().x / 8.f;
	for (size_t i = 0; i < 4; i++)
	{
		float curMiddle = spacing + i * spacing * 2.f;
		//PX
		Text playerText;
		playerText.Init("P" + std::to_string(i + 1), sf::Color::Blue, sf::Vector2f(curMiddle - spacing / 2.f, 150.f));
		//playerText.SetPositionCenter(sf::Vector2f(curMiddle, 150.f));
		//Portrait
		sf::Sprite sprite;
		sprite.setTexture(m_allSelectableCharacters[m_players[i].chosenChar.x][m_players[i].chosenChar.y].portrait);
		sprite.setPosition(curMiddle-spacing/2.f, 200.f);
		
		sf::RectangleShape border;
		border.setPosition(curMiddle - spacing / 2.f, 200.f);
		border.setSize(sf::Vector2f(150.f, 150.f));
		border.setFillColor(sf::Color::Transparent);
		border.setOutlineThickness(5.f);
		if (m_players[i].isLocked)
		{
			border.setOutlineColor(sf::Color::Blue);
		}
		else
		{
			border.setOutlineColor(sf::Color::Yellow);
		}

		//Character name
		float posY = 365.f;
		Text charName;
		if (!m_players[i].isActive)
		{
			charName.Init("Press A to join", sf::Color::Yellow, sf::Vector2f(curMiddle - spacing * 0.4f, posY));
			charName.SetSize(14);
		}
		else
		{
			switch (m_players[i].chosenChar.x)
			{
			case(1) :
				charName.Init("Göran", sf::Color::Yellow, sf::Vector2f(curMiddle - spacing * 0.4f, posY));
				break;
			case(2) :
				charName.Init("Sven", sf::Color::Yellow, sf::Vector2f(curMiddle - spacing * 0.4f, posY));
				break;
			case(3) :
				charName.Init("Roger", sf::Color::Yellow, sf::Vector2f(curMiddle - spacing * 0.4f, posY));
				break;
			case(4) :
				charName.Init("Peter", sf::Color::Yellow, sf::Vector2f(curMiddle - spacing * 0.4f, posY));
				break;
			default:
				break;
			}
		}
		
		//Render
		window->draw(playerText.GetText());
		window->draw(sprite);
		window->draw(border);
		window->draw(charName.GetText());
	}
}

void CharacterSelectScene::SetCharacterNamesToPlayer()
{
	for (size_t i = 0; i < 4; i++)
	{
		switch (m_players[i].chosenChar.x)
		{
		case(1) :
			PlayerContext::GetPlayerContext()->GetPlayer(i)->SetTextureName("spritesheet_moose_5.png");
			PlayerContext::GetPlayerContext()->GetPlayer(i)->SetScriptName("CharacterScripts/moose.lua");
			PlayerContext::GetPlayerContext()->GetPlayer(i)->SetColor(3 - m_players[i].chosenChar.y);
			PlayerContext::GetPlayerContext()->GetPlayer(i)->SetAnimal(m_players[i].chosenChar.x - 1);
			PlayerContext::GetPlayerContext()->GetPlayer(i)->SetFlag(3 - m_players[i].chosenChar.y - 1);
			break;
		case(2) :
			PlayerContext::GetPlayerContext()->GetPlayer(i)->SetTextureName("spritesheet_tiger_5.png");
			PlayerContext::GetPlayerContext()->GetPlayer(i)->SetScriptName("CharacterScripts/tiger.lua");
			PlayerContext::GetPlayerContext()->GetPlayer(i)->SetColor(3 - m_players[i].chosenChar.y);
			PlayerContext::GetPlayerContext()->GetPlayer(i)->SetAnimal(m_players[i].chosenChar.x - 1);
			PlayerContext::GetPlayerContext()->GetPlayer(i)->SetFlag(3 - m_players[i].chosenChar.y - 1);
			break;
		case(3) :
			PlayerContext::GetPlayerContext()->GetPlayer(i)->SetTextureName("spritesheet_horse_5.png");
			PlayerContext::GetPlayerContext()->GetPlayer(i)->SetScriptName("CharacterScripts/horse.lua");
			PlayerContext::GetPlayerContext()->GetPlayer(i)->SetColor(3 - m_players[i].chosenChar.y);
			PlayerContext::GetPlayerContext()->GetPlayer(i)->SetAnimal(m_players[i].chosenChar.x - 1);
			PlayerContext::GetPlayerContext()->GetPlayer(i)->SetFlag(3 - m_players[i].chosenChar.y - 1);
			break;
		case(4) :
			PlayerContext::GetPlayerContext()->GetPlayer(i)->SetTextureName("spritesheet_rabbit_5.png");
			PlayerContext::GetPlayerContext()->GetPlayer(i)->SetScriptName("CharacterScripts/rabbit.lua");
			PlayerContext::GetPlayerContext()->GetPlayer(i)->SetColor(3 - m_players[i].chosenChar.y);
			PlayerContext::GetPlayerContext()->GetPlayer(i)->SetAnimal(m_players[i].chosenChar.x - 1);
			PlayerContext::GetPlayerContext()->GetPlayer(i)->SetFlag(3 - m_players[i].chosenChar.y - 1);
			break;
		}
		if (m_players[i].chosenChar.x != 0)
		{
			PlayerContext::GetPlayerContext()->NrOfActivePlayers++;
			PlayerContext::GetPlayerContext()->GetPlayer(i)->InitAnimation(PlayerContext::GetPlayerContext()->GetPlayer(i)->GetTextureName());
			PlayerContext::GetPlayerContext()->GetPlayer(i)->LoadInitStats(PlayerContext::GetPlayerContext()->GetPlayer(i)->GetScriptName());
		}
	}
}

void CharacterSelectScene::SelectNextCharacter(int playerID)
{
	m_players[playerID].chosenChar.x++;
	if (m_players[playerID].chosenChar.x == m_totalCharacters)
		m_players[playerID].chosenChar.x = 1; // 0 is the none character
	m_players[playerID].chosenChar.y--;
	if (m_players[playerID].chosenChar.y < 0)
		m_players[playerID].chosenChar.y = m_totalColors - 1;
	m_players[playerID].chosenChar.y = GetNextAvailableColor(m_players[playerID].chosenChar.x, m_players[playerID].chosenChar.y);
}

void CharacterSelectScene::SelectPrevCharacter(int playerID)
{
	m_players[playerID].chosenChar.x--;
	if (m_players[playerID].chosenChar.x == 0) // 0 is the none character
		m_players[playerID].chosenChar.x = m_totalCharacters - 1;
	m_players[playerID].chosenChar.y--;
	if (m_players[playerID].chosenChar.y < 0)
		m_players[playerID].chosenChar.y = m_totalColors - 1;
	m_players[playerID].chosenChar.y = GetNextAvailableColor(m_players[playerID].chosenChar.x, m_players[playerID].chosenChar.y);
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
		bool okColor = false;
		for (size_t i = 0; i < 4; i++)
		{
			if (m_players[i].chosenChar.x != character)
				continue;
			if (m_players[i].chosenChar.y == wantColor)
			{
				okColor = false;
				break;
			}
			okColor = true;
		}
		if (okColor)
			return wantColor;
		wantColor++;
		if (wantColor == m_totalColors)
			wantColor = 0;
	}
	return currentColor;
}

int CharacterSelectScene::GetPrevAvailableColor(int character, int currentColor)
{
	int wantColor = currentColor - 1;
	if (wantColor < 0)
		wantColor = m_totalColors-1;
	while (wantColor != currentColor)
	{
		bool okColor = false;
		for (size_t i = 0; i < 4; i++)
		{
			if (m_players[i].chosenChar.x != character)
				continue;
			if (m_players[i].chosenChar.y == wantColor)
			{
				okColor = false;
				break;
			}
			okColor = true;
		}
		if (okColor)
			return wantColor;
		wantColor--;
		if (wantColor < 0)
			wantColor = m_totalColors-1;
	}
	return currentColor;
}