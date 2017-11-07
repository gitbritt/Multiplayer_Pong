#ifndef SOME_CLASS_H
#define SOME_CLASS_H 
#include <SFML/Graphics.hpp>


class GUI
{
	public:
		
		sf::CircleShape ball();
		sf::RectangleShape paddle1();
		sf::RectangleShape paddle2();
		sf::Text Score();

		GUI();
};

#endif