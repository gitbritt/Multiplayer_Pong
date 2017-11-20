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

sf::RectangleShape GUI::paddle_moving_local(sf::RectangleShape local_paddle, sf::Event event)
{
	int y = event.mouseMove.y;
	if (y <= 100)
		y = 100;
	else if (y >= 500)
		y = 500;
	local_paddle.setPosition(local_paddle.getPosition().x, y - 100);
	return local_paddle;
}

sf::RectangleShape GUI::paddle_moving_forign(float y, sf::RectangleShape forign_paddle)
{
	
	forign_paddle.setPosition(forign_paddle.getPosition().x, y);
	return forign_paddle;
}
