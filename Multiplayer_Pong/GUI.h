#ifndef SOME_CLASS_H
#define SOME_CLASS_H 
#include <SFML/Graphics.hpp>
#include <tuple>

class GUI
{
	public:
		
		sf::CircleShape ball();
		sf::RectangleShape paddle1();
		sf::RectangleShape paddle2();
		sf::Text Score();
		sf::RectangleShape paddle_moving_local(sf::RectangleShape local_paddle, sf::Event event);
		sf::RectangleShape paddle_moving_forign(float, sf::RectangleShape);
		sf::CircleShape ball_moving(sf::CircleShape ball, sf::RectangleShape local_paddle, sf::RectangleShape foreign_paddle, float, float );
		std::tuple<float, float> ball_direction(sf::CircleShape ball, sf::RectangleShape local_paddle, sf::RectangleShape foreign_paddle, float, float, char);
		GUI();
		
};

#endif