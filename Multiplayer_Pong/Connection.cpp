#include <SFML/Graphics.hpp>
#include <iostream>
#include "GUI.h"
#include "Networking.h"
#include <tuple>
#include <SFML/Network.hpp>

void Networking::Connection_Server(std::string IP_address)
{
	sf::TcpListener listener;
	//if (listener.listen(85) != sf::Socket::Done)
	//	std::cout << "Failed!\n";
}

void Networking::Connection_Client(std::string IP_address)
{

}