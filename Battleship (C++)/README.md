# Welcome to My Battleship Code!

This code at is core is just me practicing how to use Object Oriented Programming in C++. The structure of the program is as such.

Main - the file used to test classes and start the game.
Battleship - the class responsible for Top-level game management. Mainly a space where players can communicate with each other.
Player - the class that holds all the functionality to allow the player to place ships.
Computer - the class that builds on top of the Player class to add decision making for CPUs to play relatively alright against someone.
Ship - the class that is responsible for representing a ship's existence on the battlefield, including if its dead or not.
Location - the class that acts as the API between the player and the battlefield, responsible for manging views of battlefields.
Grid - the class responsible for storing and showing the state of a given battlefield. 
