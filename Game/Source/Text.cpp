#include <System/Text.hpp>


Text::Text()
{
}

Text::~Text()
{
}

bool Text::Init(std::string text, sf::Color color, sf::Vector2f position)
{
	if (!m_font.loadFromFile("OpenSans.ttf"))
	{
		return false;
	}

	m_text.setFont(m_font);

	SetText(text);
	SetSize(24);
	SetColor(color);
	m_text.setStyle(sf::Text::Bold);
	SetPositionTopLeft(position);

	return true;
}


void Text::SetText(std::string string)
{
	m_text.setString(string);
}

void Text::SetPositionTopLeft(sf::Vector2f position)
{
	m_text.setPosition(position.x, position.y);
}

void Text::SetPositionCenter(sf::Vector2f position)
{
	m_text.setPosition(position.x - m_text.getLocalBounds().width, position.y - m_text.getLocalBounds().height);
}

void Text::SetColor(sf::Color color)
{
	m_text.setColor(color);
}

void Text::SetSize(int size)
{
	m_text.setCharacterSize(size);
}

sf::Text Text::GetText()
{
	return m_text;
}


void Text::LoadTextFromFile(std::string filename)
{
	std::string tempText;
	std::ifstream textFile;
	textFile.open(filename);
	getline(textFile, tempText);

	SetText(tempText);

	textFile.close();
}