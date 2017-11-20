#include <SFML/Graphics.hpp>
#include <iostream>
#include "GUI.h"
#include "Networking.h"
#include <tuple>
#include <SFML/Network.hpp>

//This file manages the connection between the Client and the Server
void Networking::Connection_Server()	//For now this is for pratice for just trying to understand things.
{
	//I got these pieces of code from a youtube video series from  https://www.youtube.com/user/CodingMadeEasy
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	sf::TcpSocket socket;
	char connectionType, mode;
	char buffer[2000];
	std::size_t recieved;
	std::string text = "connected to ";

	std::cout << "Enter S for server. Enter C " << "\n";
	std::cin >> connectionType;
	if (connectionType == 's')
	{
		sf::TcpListener listener;
		listener.listen(2000);
		listener.accept(socket);
		text += " : Server ";
		mode = 's';
	}
	else if (connectionType == 'c')
	{
		socket.connect(ip, 2000);
		text += " Client";
		mode = 'r';
	}
	socket.send(text.c_str(), text.length() + 1);
	socket.receive(buffer, sizeof(buffer), recieved);
	std::cout << buffer << "\n";

	bool done = false;

	while (!done)
	{
		if (mode == 's')
		{
			std::getline(std::cin, text);
			socket.send(text.c_str(), text.length() + 1);
			mode = 'r';
		}
		else if (mode == 'r')
		{
			socket.receive(buffer, sizeof(buffer), recieved);
			if (recieved > 0)
			{
				std::cout << "Recieved: " << buffer << "\n";
				mode = 's';
			}
		}
	}
}

