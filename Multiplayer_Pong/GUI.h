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
		//sf::Text Score();
		sf::RectangleShape paddle_moving_local(sf::RectangleShape local_paddle, sf::Event event);
		sf::CircleShape ball_moving(sf::CircleShape ball, sf::RectangleShape local_paddle, float, float );
		std::tuple<float, float> ball_direction(sf::CircleShape ball, sf::RectangleShape local_paddle, float, float);
		//std::tuple<sf::Text, sf::Text, int, int> update_scores(sf::CircleShape ball, sf::Text, sf::Text, int, int);
		void update_scores(sf::CircleShape ball, sf::Text &, sf::Text &, int &, int &);
		void initialize_scores(sf::Text &, sf::Text &, sf::Font &);
		GUI();
		
};

#endif