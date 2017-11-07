#include "GUI.h"
#include <SFML/Graphics.hpp>
#include <iostream>

sf::RectangleShape GUI::paddle1()
{

	sf::RectangleShape paddle1(sf::Vector2f(10, 200));
	paddle1.setFillColor(sf::Color::White);
	paddle1.setPosition(10, 200);

	return paddle1;
}

sf::RectangleShape GUI::paddle2()
{

	sf::RectangleShape paddle2(sf::Vector2f(10, 200));
	paddle2.setFillColor(sf::Color::White);
	paddle2.setPosition(980, 200);
	
	return paddle2;	
}