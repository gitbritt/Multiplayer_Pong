#include <SFML/Graphics.hpp>
#include <iostream>
#include "GUI.h"

//#include "stdafx.h"

GUI::GUI()
{

}

void GUI_Display(int player_number);

//Call GUI Function to display ball and paddles
int main()
{
	int player_number;
	std::cout << "Pick plyaer 1 or 2. 1 is on the left and 2 is on the right : ";
	std::cin >> player_number;

	GUI_Display(player_number);
	return 0;
}

void GUI_Display(int player_number)
{
	int Score1_num = 0, Score2_num = 0;
	GUI gui;
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
	else
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
	Score1.setPosition(800, 550);
	Score2.setPosition(200, 550);
	Score1.setString(std::to_string(Score1_num));
	Score2.setString(std::to_string(Score2_num));
	while (window.isOpen())
	{
		

		sf::Event event;
		while (window.pollEvent(event))
		{	
			if (event.type == sf::Event::MouseMoved)//This gets the x and y cordinates of the mouse to move the paddle
			{
				std::cout << "Local paddle/mouse position y: " << event.mouseMove.y << std::endl;
				int y = event.mouseMove.y;
				if (y <= 100)
					y = 100;
				else if (y >= 500)
					y = 500;
				local_paddle.setPosition(local_paddle.getPosition().x, y - 100);
				//paddle1.setPosition(paddle1.getPosition().x, y);
			}

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
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