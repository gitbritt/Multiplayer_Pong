#include <SFML/Graphics.hpp>
#include <iostream>
#include "GUI.h"
#include <tuple>


//#include "stdafx.h"

GUI::GUI()
{

}
GUI gui;
sf::CircleShape ball = gui.ball();
sf::RectangleShape paddle1 = gui.paddle1();
sf::RectangleShape paddle2 = gui.paddle2();
sf::RectangleShape local_paddle;
sf::RectangleShape foreign_paddle;
float change_direction_x = 0.25, change_direction_y = 0.25;
void GUI_Display(int player_number);

//Call GUI Function to display ball and paddles
int main()
{
	int player_number;
	std::string this_machine_IP_address;
	std::cout << "Pick plyaer 1 or 2. 1 is on the left and 2 is on the right : ";
	std::cin >> player_number;

	std::cout << "Please enter your IP address : ";
	std::cin >> this_machine_IP_address;


	GUI_Display(player_number);
	return 0;
}

void GUI_Display(int player_number)
{
	int Score1_num = 0, Score2_num = 0;
	sf::RenderWindow window(sf::VideoMode(1000, 600), "Multiplayer Pong");
	sf::CircleShape ball = gui.ball();
	sf::RectangleShape paddle1 = gui.paddle1();
	sf::RectangleShape paddle2 = gui.paddle2();
	sf::RectangleShape local_paddle;
	sf::RectangleShape foreign_paddle;
	if (player_number == 1)
	{
		local_paddle = paddle1;
		foreign_paddle = paddle2;
	}
	else if(player_number ==2 )
	{
		local_paddle = paddle2;
		foreign_paddle = paddle1;
	}
	sf::Text Score1;
	sf::Text Score2;
	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	Score1.setFont(font);
	Score2.setFont(font);
	Score1.setPosition(800, 550);													//Player 1 score on the left
	Score2.setPosition(200, 550);													//Player 2 score on the right
	Score1.setString(std::to_string(Score1_num));									//Displays Score for player 1
	Score2.setString(std::to_string(Score2_num));									//Displays Score for player 2
	while (window.isOpen())
	{
		std::tie(change_direction_x, change_direction_y) = gui.ball_direction(ball, local_paddle, change_direction_x, change_direction_y);
		ball = gui.ball_moving(ball, local_paddle, change_direction_x, change_direction_y);				//This function lets the ball move around
		sf::Event event;
		while (window.pollEvent(event))
		{	
			if (event.type == sf::Event::MouseMoved)								//This gets the x and y cordinates of the mouse to move the paddle
			{
				local_paddle = gui.paddle_moving_local(local_paddle, event);
			}						//This allows the local paddl to move
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(ball);
		window.draw(local_paddle);
		window.draw(foreign_paddle);
		window.draw(Score1);
		window.draw(Score2);
		window.display();
	}

}