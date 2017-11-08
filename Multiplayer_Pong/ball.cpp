#include "GUI.h"
#include <SFML/Graphics.hpp>
#include <iostream>

sf::CircleShape GUI::ball()
{
	
	sf::CircleShape ball(15.f);
	ball.setFillColor(sf::Color::White);
	ball.setPosition(500, 300);

	return ball;
}

void GUI::ball_moving(sf::CircleShape ball)
{
	std::cout << "Hello World";
	sf::Event Event;

}