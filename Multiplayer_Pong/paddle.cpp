#include "GUI.h"
#include <SFML/Graphics.hpp>
#include <iostream>

sf::RectangleShape GUI::paddle1()
{

	sf::RectangleShape paddle1(sf::Vector2f(10, 200));		//This sets the size of the paddle
	paddle1.setFillColor(sf::Color::White);					//Sets the color
	paddle1.setPosition(10, 200);							//Sets the x and y coordinates of locaiton of the paddle on the screen for paddle 1
	return paddle1;
}

sf::RectangleShape GUI::paddle2()
{

	sf::RectangleShape paddle2(sf::Vector2f(10, 200));		//This sets the size of the paddle
	paddle2.setFillColor(sf::Color::White);					//Sets the color
	paddle2.setPosition(980, 200);							//Sets the x and y coordinates of locaiton of the paddle on the screen for paddle 1
	return paddle2;	
}

