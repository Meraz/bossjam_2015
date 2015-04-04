#ifndef TEXTMANAGER_H
#define TEXTMANAGER_H

#include <SFML/Graphics.hpp>
#include <fstream>

class TextManager
{
private:
	sf::Font m_font;
	sf::Text m_text;

public:
	TextManager();
	virtual ~TextManager();

	bool init();

	void setString(std::string string);

	sf::Text getText();

	void loadTextFromFile(std::string filename);
};

#endif