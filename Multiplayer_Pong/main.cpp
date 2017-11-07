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
	int Score1_num = 0, Score2_num = 0;
	GUI gui;
	sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!");
	sf::CircleShape ball = gui.ball();
	sf::RectangleShape paddle1 = gui.paddle1();
	sf::RectangleShape paddle2 = gui.paddle2();
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
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(ball);
		window.draw(paddle1);
		window.draw(paddle2);

		window.draw(Score1);
		window.draw(Score2);
		window.display();
	}

}