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

	bool init();

	void setString(std::string string);

	sf::Text getText();

	void loadTextFromFile(std::string filename);
};

#endif