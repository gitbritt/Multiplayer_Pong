#include <SFML/Graphics.hpp>
#include <iostream>
#include "GUI.h"
#include <tuple>
#include <SFML/Network.hpp>
#include "Networking.h"

//#include "stdafx.h"

GUI::GUI(){}				//Init GUI class
GUI gui;
Networking::Networking(){}									//Init Networking Class, but this is only used for testing purposes
Networking Net;
sf::CircleShape ball = gui.ball();							//Defines the ball object
sf::RectangleShape paddle1 = gui.paddle1();					//Defines the paddle 1
sf::RectangleShape paddle2 = gui.paddle2();					//Defines the paddle 2
sf::RectangleShape local_paddle;							//The local paddle that is on the local machine
sf::RectangleShape foreign_paddle;							//The other paddle that the other user is using
float change_direction_x = 0.5, change_direction_y = 0.5;	//This is the speed at which the ball moves
void GUI_Display(int player_number);						//Declares function
char join_start;

//THese next few are for sending Data over a network
sf::Packet paddle_coordinates;								//Packet will send x,y coordines for the paddle
sf::Packet player_number_packet;							//Packet to see which person is p1 and p2
sf::Packet ball_coordinates;
sf::TcpSocket socket, socket2;										//Defiens the socket
sf::TcpListener listen, listen2;										//Defines the listener
char buffer[128];


int main()
{
	//
	int player_number;
	sf::IpAddress ip;

	std::cout << "Server or Client. put c or s : ";
	std::cin >> join_start;
	if (join_start == 's')
	{
		ip = sf::IpAddress::getLocalAddress();
		std::cout << "Waiting . . . . ";
		listen.listen(2000);							//The port we are using is port 2000. This listens for client connections trying to use that port
		listen.accept(socket);
		listen2.listen(2001);
		listen2.accept(socket2);
	}
	else if (join_start == 'c')
	{
		std::cout << "IP you want to connect to : ";
		std::cin >> ip;
		socket.connect(ip, 2000);
		socket2.connect(ip, 2001);

	}
	else
	{
		std::cout << "Not valid\n";
		main();
	}
	std::string testing;
	
	std::cout << "\n\nPick plyaer 1 or 2. 1 is on the left and 2 is on the right : ";
		std::cin >> player_number;
		player_number_packet << player_number;
		socket.send(player_number_packet);
		
		socket.receive(player_number_packet);
		player_number_packet >> player_number;
		
		std::cout << "The other player is : " << player_number << "\n";
	GUI_Display(player_number);
	system("pause");
	return 0;
}

void GUI_Display(int player_number)
{
	int Score1_num = 0, Score2_num = 0;
	sf::RenderWindow window(sf::VideoMode(1000, 600), "Multiplayer Pong : " + join_start);		//Sets the window size
	sf::RectangleShape local_paddle;											//
	sf::RectangleShape foreign_paddle;											//
	sf::Vector2f prevPosition_paddle, p2Position_paddle;
	sf::Vector2f prevPosition_ball, p2Position_ball;
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
	bool update = false;
	socket.setBlocking(false);
	while (window.isOpen())
	{
		int i = 0;
		i++;
		std::tie(change_direction_x, change_direction_y) = gui.ball_direction(ball, local_paddle, foreign_paddle,  change_direction_x, change_direction_y, join_start);
		ball = gui.ball_moving(ball, local_paddle, foreign_paddle, change_direction_x, change_direction_y);				//This function lets the ball move around
		
		sf::Event event;
		while (window.pollEvent(event))
		{	
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::GainedFocus)
				update = true;
			else if (event.type == sf::Event::LostFocus)
				update = false;
		}
		prevPosition_paddle = local_paddle.getPosition();
		//if (update)
		//{
		if (event.type == sf::Event::MouseMoved)								//This gets the x and y cordinates of the mouse to move the paddle
		{
			local_paddle = gui.paddle_moving_local(local_paddle, event);		//This allows the local paddl to move
		}
		if (prevPosition_paddle != local_paddle.getPosition())
		{
			paddle_coordinates << local_paddle.getPosition().x << local_paddle.getPosition().y;
			socket.send(paddle_coordinates);
		}
		socket.receive(paddle_coordinates);

		if (paddle_coordinates >> p2Position_paddle.x >> p2Position_paddle.y)
		{
			foreign_paddle.setPosition(p2Position_paddle);
		}
		paddle_coordinates.endOfPacket();
		//}
		//std::cout << p2Position_paddle.y << "\n";

		if (join_start == 's')
		{
			ball_coordinates << ball.getPosition().x << ball.getPosition().y;
			socket2.send(ball_coordinates);
		}
		else
		{
			socket2.receive(ball_coordinates);
			ball_coordinates >> p2Position_ball.x >> p2Position_ball.y;
			std::cout << "Recieved x coordinates from server : " << p2Position_ball.x << "\n";
		}
		ball_coordinates.endOfPacket();

		window.clear();
		window.draw(ball);
		window.draw(local_paddle);
		window.draw(foreign_paddle);
		window.draw(Score1);
		window.draw(Score2);
		window.display();
	}

}