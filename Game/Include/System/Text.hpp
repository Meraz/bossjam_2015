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

	bool Init(std::string text, sf::Color color, sf::Vector2f position);

	void SetText(std::string string);
	void SetPositionTopLeft(sf::Vector2f position);
	void SetPositionCenter(sf::Vector2f position);
	void SetColor(sf::Color color);
	void SetSize(int size);

	sf::Text GetText();

	void LoadTextFromFile(std::string filename);
};

#endif