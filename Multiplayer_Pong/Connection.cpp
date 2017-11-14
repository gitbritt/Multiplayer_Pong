#include <SFML/Graphics.hpp>
#include <iostream>
#include "GUI.h"
#include "Networking.h"
#include <tuple>
#include <SFML/Network.hpp>

//This file manages the connection between the Client and the Server
void Networking::Connection_Server(std::string IP_address)
{
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	sf::TcpSocket socket;
	char connectiontype, mode;
	char buffer[2000];
	size_t received;
	std::cout << "s for server, c for client" << "\n";
	std::cin >> connectiontype;
	std::string text = "connected to ";
	if (connectiontype == 's') {
		sf::TcpListener listener;
		listener.listen(3000);
		listener.accept(socket);
		text += "server";
		mode = 's';
	}
	else if (connectiontype == 'c') {
		socket.connect(ip, 3000);
		text += "client";
		mode = 'r';
	}
	socket.send(text.c_str(), text.length() + 1);
	socket.receive(buffer, sizeof(buffer), received);
	std::cout << buffer << "\n";

	bool done = false;

	while (!done) {
		if (mode == 's') {
			std::getline(std::cin, text);
			socket.send(text.c_str(), text.length() + 1);
			mode = 'r';
		}
		else if (mode == 'r') {
			socket.receive(buffer, sizeof(buffer), received);
			if (received>0) {
				std::cout << "received: " << buffer << "\n";
				mode = 's';
			}
		}
	}
}

void Networking::Connection_Client(std::string IP_address)
{
	sf::UdpSocket socket;

	// bind the socket to a port
	if (socket.bind(54000) != sf::Socket::Done)
	{
		// error...
	}
}