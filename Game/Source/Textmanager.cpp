#include "Textmanager.hpp"


TextManager::TextManager()
{
}

TextManager::~TextManager()
{
}

bool TextManager::init()
{
	if (!m_font.loadFromFile("mytype.ttf"))
	{
		return false;
	}

	m_text.setFont(m_font);

	setString("");
	m_text.setCharacterSize(24);
	m_text.setColor(sf::Color::Red);
	m_text.setStyle(sf::Text::Bold);
	m_text.setPosition(200, 200);

	return true;
}


void TextManager::setString(std::string string)
{
	m_text.setString(string);
}

sf::Text TextManager::getText()
{
	return m_text;
}


void TextManager::loadTextFromFile(std::string filename)
{
	std::string tempText;
	std::ifstream textFile;
	textFile.open(filename);
	getline(textFile, tempText);

	setString(tempText);

	textFile.close();
}