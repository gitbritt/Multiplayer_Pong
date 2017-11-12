#include <SFML/Graphics.hpp>
#include <iostream>
#include "GUI.h"
#include "Networking.h"
#include <tuple>
#include <SFML/Network.hpp>


void Networking::Connection_Server(std::string IP_address)
{
	sf::UdpSocket socket;

	// bind the socket to a port
	//sf::IpAddress test;
	if (socket.bind(54000) != sf::Socket::Done)
	{
		// error...
	}
	
}

void Networking::Connection_Client(std::string IP_address)
{

}