#pragma once
#ifndef Networking_Class
#define Networking_Class
#include <SFML/Network.hpp>

class Networking
{
public:
	void Connection_Server(std::string);
	void Connection_Client(std::string);
	Networking();
};

#endif