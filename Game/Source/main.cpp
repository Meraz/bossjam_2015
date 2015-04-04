#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "XboxInput.hpp"
#include "MusicManager.hpp"
#include "Textmanager.hpp"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "BossJam!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::CircleShape shape2(100.f);
	shape2.setFillColor(sf::Color::Blue);

	sf::CircleShape shape3(100.f);
	shape3.setFillColor(sf::Color::Cyan);

	sf::CircleShape shape4(100.f);
	shape4.setFillColor(sf::Color::Magenta);
	shape4.move(600, 400);

	XboxInput* Player1 = new XboxInput(0);

	MusicManager* music = new MusicManager();

	music->loadSong("Hero.flac");

	TextManager* textBox = new TextManager();
	textBox->init();

	textBox->loadTextFromFile("example.txt");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();



		shape.move(Player1->getLThumbStickX() / 1000, Player1->getLThumbStickY() / 1000);

		shape2.move(Player1->getRThumbStickX() / 1000, Player1->getRThumbStickY() / 1000);

		shape3.move(Player1->getDPadX() / 1000, Player1->getDPadY() / 1000);

		shape4.move(Player1->getLTrigger() / 1000, Player1->getRTrigger() / 1000);

		if (Player1->isAbuttonPressed())
		{
			shape4.setPosition(600, 400);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			music->stopSong("Hero.flac");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			music->playSong("Hero.flac");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			music->playSongFromStart("Hero.flac");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			music->PlaySongFromTime("Hero.flac", sf::seconds(30));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			textBox->loadTextFromFile("example2.txt");
		}

		window.draw(shape);
		window.draw(shape2);
		window.draw(shape3);
		window.draw(shape4);

		window.draw(textBox->getText());

		window.display();
	}

	return 0;
}