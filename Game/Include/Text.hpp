#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.hpp>
#include <fstream>

class Text
{
private:
	sf::Font m_font;
	sf::Text m_text;

public:
	Text();
	virtual ~Text();

	bool Init(sf::Color color);

	void SetString(std::string string);

	sf::Text GetText();

	void LoadTextFromFile(std::string filename);
};

#endif