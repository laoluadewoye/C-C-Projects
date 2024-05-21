# Welcome to My Battleship Game!

This code at is core is just me practicing how to use Object Oriented Programming, how to code in C/C++, and how to create public docker containers since I wanted to share it but my friends don't have all the coder software installed. It took two years, lots of struggling, three different IDEs, and a whole lot of Chat-GPT to help me set up VS Code's debugger but I finally got something together!

The structure of the program is as such-

* Main - the file used to test classes and start the game.
* Battleship - the class responsible for Top-level game management. Mainly a space where players can communicate with each other.
* Player - the class that holds all the functionality to allow the player to place ships.
* Computer - the class that builds on top of the Player class to add decision-making for CPUs to play relatively alright against someone.
* Ship - the class that is responsible for representing a ship's existence on the battlefield, including whether if its dead or not.
* Location - the class that acts as the API between the player and the battlefield, responsible for managing views of battlefields.
* Grid - the class responsible for storing and showing the state of a given battlefield. 

How this program works is that the main program will create a battleship object and start the game. The battleship object, in turn, manages two player objects. They place their ships then spend an undetermined amount of turns racing to destroy each other's battleships. To tell if there were hits or not are on the receiver's end of each attack, and they check with the ship objects to do this. Afterward, they then ask the location objects to modify the grids to reflect misses, hits, and all other changes.

# My proud AI

The AI was, for two years, the bane of my existence. It would be so simply if I was in Python and I can create all the data structures I want with ease, but C forced me to come up with something creative. A huge goal for this project was to use only basic arrays and data structures, and having a 2D structure felt weird, so instead, I created a stack!

The way the AI works is that there are two static arrays in memory. The first is an array of 100 coordinates (as integers) that records each untried spot on the board. The second is an array of 28 empty spots, to which I call the smark stack. The first array is easy - we pull a random guess from the guesses we still have, "delete it" from the array (delete in quotes since its C), and see if it works. But what if we land on something?

## The 4 x 7 Smart Stack

If we land on something, we need a way for the AI to check if it should keep searching around the immediate area. This is where the smart stack comes in. To the computer, this stack is just a row of 28 integers. However, I imagine it as a 4 by 7 stack of numbers, where each spot in a row represents Up, Down, Left, and Right respectively see the ASCII graphic below:

<p><br /> U D L R<br />-------------<br />| | | | | Row 6<br />-------------<br />| | | | | Row 5<br />-------------<br />| | | | | Row 4<br />-------------<br />| | | | | Row 3<br />-------------<br />| | | | | Row 2<br />-------------<br />| | | | | Row 1<br />-------------<br />| | | | | Row 0<br />-------------</p>
<p>&nbsp;</p>



