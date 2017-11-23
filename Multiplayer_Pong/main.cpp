#include <SFML/Graphics.hpp>
#include <iostream>
#include "GUI.h"
#include <tuple>
//Synced with Eric Claus
//Synced with Michelle Amos
//Dillon showing Eric and Michelle how git works. basics
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

// Set initial scores at 0
int Score1_num = 0, Score2_num = 0;
// Initialize the score sf::Text objects and the font object for them to use (to be modified by initialize_scores())
sf::Text Score1;
sf::Text Score2;
sf::Font font;


//Call GUI Function to display ball and paddles
int main()
{
	int player_number;
	std::string this_machine_IP_address;
	std::cout << "Pick player 1 or 2. 1 is on the left and 2 is on the right : ";
	std::cin >> player_number;

	std::cout << "Please enter your IP address : ";
	std::cin >> this_machine_IP_address;


	GUI_Display(player_number);
	return 0;
}

void GUI_Display(int player_number)
{
	sf::RenderWindow window(sf::VideoMode(1000, 600), "Enhanced Multiplayer Pong");
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

	// Configure and initialize the scores
	gui.initialize_scores(Score1, Score2, font);

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
			}						//This allows the local paddle to move
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Call update_scores function, which updates the score sf::Text objects, along with their corresponding integers
		gui.update_scores(ball, Score1, Score2, Score1_num, Score2_num);

		// Draw all of the items in the window
		window.clear();
		window.draw(ball);
		window.draw(local_paddle);
		window.draw(foreign_paddle);
		window.draw(Score1);
		window.draw(Score2);
		window.display();
	}
}