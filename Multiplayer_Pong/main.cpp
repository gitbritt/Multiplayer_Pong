#include <SFML/Graphics.hpp>
#include <iostream>
#include "GUI.h"

//#include "stdafx.h"

GUI::GUI()
{

}

void GUI_Display();

//Call GUI Function to display ball and paddles
int main()
{
	GUI_Display();
	return 0;
}

void GUI_Display()
{
	GUI gui;
	sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!");
	sf::CircleShape ball = gui.ball();
	sf::RectangleShape paddle1 = gui.paddle1();
	sf::RectangleShape paddle2 = gui.paddle2();
	sf::Text Score = gui.Score();
	//GUI_Display();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(ball);
		window.draw(paddle1);
		window.draw(paddle2);
		//window.draw(Score);
		window.display();
	}

}