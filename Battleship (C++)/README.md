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

<p><br />&nbsp; U&nbsp; &nbsp;D&nbsp; &nbsp; L&nbsp; &nbsp; R<br />----------------<br />|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;| Row 6<br />----------------<br />|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp;Row 5<br />----------------<br />|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp;Row 4<br />----------------<br />|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp;Row 3<br />----------------<br />|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp;Row 2<br />----------------<br />|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp;Row 1<br />----------------<br />|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp;Row 0<br />----------------</p>

Much like a stack in assembly, this stack uses a Last In First Out (LIFO) methodology, as the last row put in is the one to get removed first. Only rather than store pure data, this stack stores a row of numbers. Each row corresponds to-

1) The number above the last coordinate attempt
2) The number below the last coordinate attempt
3) The number to the left of the last coordinate attempt
4) The number to the right of the last coordinate attempt

-In that order. These locations are found through arithmetic operations to move on a 10x10 board. Yes, this does mean that edge and corner guesses can create some pretty weird stuff, but we leave the checking of those guesses up to other logic in the object. For almost everywhere else, this works perfectly. Yes, this also does mean you can probably expose the flaws of the logic through some clever ship placement, but if you do that...well...I can't stop you, but I can say it will be boring once you finish exposing my AI. 

The CPU will take one of those numbers, or take a random coordinate to attack. If it works, it will use the direction and number it chooses to generate a new row of coordinates around the last successful attempt, and "push" that row onto the stack. Eventually, once that row stops working, it will "pop" the row off and go back down to the previous row to see if the coordinates there work. That way, the CPU is also able to "backtrack" on its guesses much like how I sometimes try older spots to see if it could be nearby, just not in the way I thought. However, if the next guess DOES work, it makes a new row and pushes further up the stack to keep trying the same direction. 

If the stack is full (since it's C++), it doesn't add any more. If the stack is empty, it just randomly guesses and if that random guess works, it adds a set of surrounding coordinates to the stack, chooses a random direction, and goes through the process. Thus, with just two arrays, an end pointer for each array, and some other variables to remember prior information, I have created an elegant system that is about as streaky as any real human. Sometimes it takes 97 turns for it to finally hit all your ships, and sometimes it will cook you in under 30 moves. Basically, it's perfect.
