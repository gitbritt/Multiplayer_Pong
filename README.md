# Multiplayer_Pong
This project is a re-make of the original Pong game that was developed by Atari in 1972.

# Intro and how it works
This project was origianlly a project proposed for a school project for a computer networking course at Southern Adventist University.
The purpose of the project was to develop something using TCP or UDP protocol(Ours uses TCP).


Our idea was to re-creat pong but make it multiplayer between two computers.
How it works is that there is a Server and a client computer. Bothe computers brodcast their paddle location,
but only the server broadcasts the Ball.

Game Play Questions
-------------------
-	It's pretty simple. Pick server or client and pick player 1 or 2. 

-	Who ever gets 7 points wins the game.

-	Currently it only works for computers on the same local network.

Required tools
--------------
-	Windows Machine
-	Visual Studio (Language is in C++)

	-	Screenshots for what Visual Studio needs for modifications. https://goo.gl/vDj8Qm
-	SFML C++ Library. 
	-	https://github.com/SFML/SFML and https://www.sfml-dev.org/
	
	-	This is the GUI library used for C++.
	
	-	A modified version for this project is here : https://github.com/gitbritt/SFML

Setup
-----
-	Make sure Visual Studio is setup. Requirements for VS : https://goo.gl/vDj8Qm

-	Clone This project and the Forked modified SFML into the same directory. 
	
		git clone https://github.com/gitbritt/Multiplayer_Pong

		git clone https://github.com/gitbritt/SFML

-	Switch VS to 32 bit (x86). All the config is set for the 32 bit(x86)
	
	
Support and Contact
-------
-	If there is bugs that you come across, please tell me about it in the issues page

	https://github.com/gitbritt/Multiplayer_Pong/issues
	
-	If for some reason the Forked SFML version is not working, visit https://www.sfml-dev.org/ and download it
	
	-	Here's a link to the tutorial + info page : https://www.sfml-dev.org/learn.php
	
