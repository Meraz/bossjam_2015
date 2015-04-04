#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "XboxInput.hpp"
#include "MusicManager.hpp"
#include "Text.hpp"


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

	music->LoadSong("Hero.flac");
	music->LoadSong("Ninja.flac");
	music->LoadSong("Winterstorm.flac");

	Text* textBox = new Text();
	textBox->Init(sf::Color::Red);

	textBox->LoadTextFromFile("example.txt");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();



		shape.move(Player1->GetLThumbStickX() / 1000, Player1->GetLThumbStickY() / 1000);

		shape2.move(Player1->GetRThumbStickX() / 1000, Player1->GetRThumbStickY() / 1000);

		shape3.move(Player1->GetDPadX() / 1000, Player1->GetDPadY() / 1000);

		shape4.move(Player1->GetLTrigger() / 1000, Player1->GetRTrigger() / 1000);

		if (Player1->IsAbuttonPressed())
		{
			shape4.setPosition(600, 400);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			music->StopSong("Hero.flac");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			music->PlaySong("Hero.flac");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			music->PlaySongFromStart("Hero.flac");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			music->PlaySongFromTime("Hero.flac", sf::seconds(30));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		{
			music->PlaySong("Winterstorm.flac");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
		{
			music->PlaySong("Ninja.flac");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
		{
			music->StopAllMusic();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
		{
			music->StopAllOtherSongs("Hero.flac");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			textBox->LoadTextFromFile("example2.txt");
		}

		window.draw(shape);
		window.draw(shape2);
		window.draw(shape3);
		window.draw(shape4);

		window.draw(textBox->GetText());

		window.display();
	}

	return 0;
}