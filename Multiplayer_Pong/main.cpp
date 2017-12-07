#include <SFML/Graphics.hpp>
#include <iostream>
#include "GUI.h"
#include <tuple>
#include <SFML/Network.hpp>
#include "Networking.h"
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <thread>         // std::this_thread::sleep_for
#include <chrono> 
//#include "stdafx.h"

GUI::GUI(){}				//Init GUI class
GUI gui;
Networking::Networking(){}									//Init Networking Class, but this is only used for testing purposes
Networking Net;												//
sf::CircleShape ball = gui.ball();							//Defines the ball object
sf::RectangleShape paddle1 = gui.paddle1();					//Defines the paddle 1
sf::RectangleShape paddle2 = gui.paddle2();					//Defines the paddle 2
sf::RectangleShape local_paddle;							//The local paddle that is on the local machine
sf::RectangleShape foreign_paddle;							//The other paddle that the other user is using
float change_direction_x = -4.0, change_direction_y = -4.0;	//This is the speed at which the ball moves
void GUI_Display(int player_number);						//Declares function
char join_start;

//THese next few are for sending Data over a network
sf::Packet paddle_coordinates;								//Packet will send x,y coordines for the paddle
sf::Packet player_number_packet;							//Packet to see which person is p1 and p2
sf::Packet ball_coordinates;
sf::TcpSocket socket , socket2;										//Defiens the socket
sf::TcpListener listen, listen2;										//Defines the listener
char buffer[128];
sf::SocketSelector selector;


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
	
	std::cout << "\n\nPick plyaer 1 or 2. 1 is on the left and 2 is on the right : ";
		std::cin >> player_number;
		int number_sent = player_number;
		player_number_packet << number_sent;
		socket.send(player_number_packet);
		
		socket.receive(player_number_packet);
		player_number_packet >> number_sent;
		
		std::cout << "The other player is : " << number_sent << "\n";
	GUI_Display(player_number);
	system("pause");
	return 0;
}

void GUI_Display(int player_number)
{
	int Score1_num = 0, Score2_num = 0;
	std::string title = "Multiplayer Pong : ";
	title = title += join_start;
	title = title += " Planer num : ";
	title = title += std::to_string(player_number);
	sf::RenderWindow window(sf::VideoMode(1000, 600), title);		//Sets the window size
	window.setFramerateLimit(60);									//Sets Frame Rate to 60
	sf::RectangleShape local_paddle;											//
	sf::RectangleShape foreign_paddle;											//
	sf::Vector2f prevPosition_paddle, p2Position_paddle;
	sf::Vector2f prevPosition_ball, p2Position_ball;
	sf::Text Score1, Score2;
	sf::Font font;
	//Init score
	gui.initialize_scores(Score1, Score2, font, player_number);
	
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

	
	bool update = false;
	socket.setBlocking(false);
	//socket2.setBlocking(true);
	int i = 0;
	while (window.isOpen())
	{
		std::tie(change_direction_x, change_direction_y) = gui.ball_direction(ball, local_paddle, foreign_paddle, change_direction_x, change_direction_y, join_start);
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
		paddle_coordinates.clear();

		selector.add(socket2);

		if (join_start == 'c')
		{
			if (socket2.receive(ball_coordinates) != sf::Socket::Done)
				std::cout << "Error Recieving\n";
			ball_coordinates >> p2Position_ball.x >> p2Position_ball.y;
			{
				ball.setPosition(p2Position_ball);
			}
		}

		if (join_start == 's')
		{
				ball_coordinates << ball.getPosition().x << ball.getPosition().y;
				if (socket2.send(ball_coordinates) != sf::Socket::Done)
					std::cout << "Error sending\n";
				
		}
		

		sf::Vertex line[] =
		{
			sf::Vertex(sf::Vector2f(500, 0)),
			sf::Vertex(sf::Vector2f(500, 600))
		};

		gui.update_scores(ball, Score1, Score2, Score1_num, Score2_num, player_number);

		ball_coordinates.clear();
		window.clear();
		window.draw(line, 2, sf::Lines);
		window.draw(Score1);
		window.draw(Score2);
		window.draw(ball);
		window.draw(local_paddle);
		window.draw(foreign_paddle);
		window.display();
	}
}