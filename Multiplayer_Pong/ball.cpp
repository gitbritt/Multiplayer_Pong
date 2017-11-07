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