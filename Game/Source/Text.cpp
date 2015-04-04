#include <System/Text.hpp>


Text::Text()
{
}

Text::~Text()
{
}

bool Text::Init(sf::Color color)
{
	if (!m_font.loadFromFile("mytype.ttf"))
	{
		return false;
	}

	m_text.setFont(m_font);

	SetString("");
	m_text.setCharacterSize(24);
	m_text.setColor(color);
	m_text.setStyle(sf::Text::Bold);
	m_text.setPosition(200, 200);

	return true;
}


void Text::SetString(std::string string)
{
	m_text.setString(string);
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

	SetString(tempText);

	textFile.close();
}