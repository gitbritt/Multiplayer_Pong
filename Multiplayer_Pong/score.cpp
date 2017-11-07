#include "GUI.h"
#include <SFML/Graphics.hpp>
#include <iostream>

sf::Text GUI::Score()
{
	//int score1_num = 1, score2_num = 1341234123412;
	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

	sf::Text text;
	text.setFont(font);
	text.setPosition(200, 200);
	text.setString("Hello SFML");
	return text;
	
}