#include <SFML/Graphics.hpp>
#include <iostream>
#include "GUI.h"
#include <tuple>

void GUI::initialize_scores(sf::Text &Score1, sf::Text &Score2, sf::Font &font, int player_number)
{
	// Set initial scores at 0
	int Score1_num = 0, Score2_num = 0;
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	Score1.setFont(font);
	Score2.setFont(font);
	Score1.setPosition(800, 550);													//Player 1 score on the left
	Score2.setPosition(200, 550);													//Player 2 score on the right
	Score1.setString(std::to_string(Score1_num));						//Displays Score for player 1
	Score2.setString(std::to_string(Score2_num));						//Displays Score for player 2

}

void GUI::update_scores(sf::CircleShape ball, sf::Text &Score1, sf::Text &Score2, int &Score1_num, int &Score2_num, int player_number)
{
	// If the ball hits the left side of the window (getting past player 1's paddle)
	if (ball.getPosition().x == 1000)
	{
		// Increment player 2's score and set the Score2 str variable to the updated score
		Score2_num++;
		Score2.setString(std::to_string(Score2_num));
		// Make the updated score display green
		Score2.setFillColor(sf::Color::Green);
		Score1.setFillColor(sf::Color::White);
	}

	// If the ball hits the right side of the window (getting past player 2's paddle)
	if (ball.getPosition().x <= -30)
	{
<<<<<<< HEAD
		std::string player_str = "Player : ";
		// Increment player 2's score and set the Score2 str variable to the updated score
		Score1_num++;
		Score1.setString(player_str += std::to_string(Score1_num));
=======
		// Increment player 1's score and set the Score1 str variable to the updated score
		Score1_num++;
		Score1.setString(std::to_string(Score1_num));

>>>>>>> 9fe466acc638dd68208cf9bf965508a04030f18d
		// Make the updated score display green
		Score2.setFillColor(sf::Color::Green);
		Score1.setFillColor(sf::Color::White);
	}
}

