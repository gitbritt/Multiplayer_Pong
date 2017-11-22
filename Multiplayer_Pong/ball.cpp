#include "GUI.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <tuple>
#include <string>
#include <tuple>

sf::CircleShape GUI::ball()
{
	
	sf::CircleShape ball(15.f);
	ball.setFillColor(sf::Color::White);
	ball.setPosition(500, 300);

	return ball;
}
sf::CircleShape GUI::ball_moving(sf::CircleShape ball, sf::RectangleShape local_paddle, sf::RectangleShape foreign_paddle, float change_direction_x, float change_direction_y)
{
	float ball_x, ball_y;
	ball_x = ball.getPosition().x;
	ball_y = ball.getPosition().y;
	
	if (ball_x <= 0)
	{
		ball_x = 500;
		ball_y = 300;
	}
	if (ball_x >= 1000)
	{
		ball_x = 500;
		ball_y = 300;
	}
	//float local_paddle_x = local_paddle.getPosition().x;
	//float local_paddle_y = local_paddle.getPosition().y;
	ball.setPosition(ball_x - change_direction_x, ball_y - change_direction_y);	
	return ball;
}

std::tuple<float, float> GUI::ball_direction(sf::CircleShape ball, sf::RectangleShape local_paddle, sf::RectangleShape foreign_paddle, float change_direction_x, float change_direction_y, char join_start)//Change the direction of the ball when it hits the paddle or walls
{
	float local_paddle_x = local_paddle.getPosition().x;
	float local_paddle_y = local_paddle.getPosition().y;
	float foreign_paddle_y = foreign_paddle.getPosition().y;
	float foreign_paddle_x = foreign_paddle.getPosition().x;
	float ball_x = ball.getPosition().x;
	float ball_y = ball.getPosition().y;
	int set_x;
	if (join_start == 'c')
		set_x = 15;
	else
		set_x = -15;

	//std::cout << "Paddle Position " << local_paddle_y - 27.5 << ", " << local_paddle_y + 204.5 << " Ball location " << ball.getPosition().y << ", " << ball.getPosition().x << "\n";

	if ((local_paddle_y - 27.5 <= ball_y) && (local_paddle_y + 200 + 4.5 >= ball_y) && (local_paddle_x == ball_x + 0))
	{
		std::cout << "Hits local paddle. Changed Direction " << "\n";
		change_direction_x = change_direction_x * -1;
	}
	if ((foreign_paddle_y - 27.5 <= ball_y) && (foreign_paddle_y + 200 + 4.5 >= ball_y) && (foreign_paddle_x - 0 == ball_x - 0))
	{
		std::cout << "Hits local paddle. Changed Direction " << "\n";//
		std::cout << "Ball Location x : " << ball.getPosition().x << " , Paddle location : " << foreign_paddle.getPosition().x << "\n";
		change_direction_x = change_direction_x * -1;
	}
	if ((ball_y <= 0) || (ball_y >= 600 - 30))
	{
		std::cout << "Hit edge. Change direction" << "\n";
		change_direction_y = change_direction_y * -1;
	}
	return std::make_tuple(change_direction_x, change_direction_y);
}