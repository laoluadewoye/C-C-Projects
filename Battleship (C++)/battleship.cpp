# include "battleship.h"

// Constructor Class for  the Battleship game
Battleship::Battleship() {
    turnNum = 0;
}

// Starting off the battleship game
void Battleship::startBattleship() {
    int choice = 0;

    // Beginning script
    cout << "Start!" << endl;
    cout << "Are you playing against another play or CPU? Enter answer below." << endl;
    cout << "Type 1 for two player game." << endl;
    cout << "Type 2 for player vs CPU." << endl;
    cout << "Type 3 for to watch two CPUs go at it." << endl;

    // Decision tree
    for (int i = 0; i < 3; i++) {
        cout << "Enter here (this prompt will show again if you choose wrong): ";
        cin >> choice;

        if (choice == 1 || choice == 2 || choice == 3) {
            break;
        }
    }

    if (choice == 1) {
        PVPSetup();
    }
    else if (choice == 2) {
        PVCSetup();
    }
    else if (choice == 3) {
        CVCSetup();
    }
    else {
        cout << "Wrong selections. Defaulting to Computer vs Computer." << endl;
        CVCSetup();
    }
}

// Player vs Player setup
void Battleship::PVPSetup() {
    //Creating players
    Player playerOne(1);
    Player playerTwo(2);
    
    playerOne.showOnlyPlayer();
    cout << endl << "Player 1 will now choose the locations of the ships!" << endl;
    manualOrAuto(playerOne);

    playerTwo.showOnlyPlayer();
    cout << endl << "Player 2 will now choose the locations of the ships!" << endl;
    manualOrAuto(playerTwo);

    gameplay(playerOne, playerTwo);
}

// Player vs Computer setup
void Battleship::PVCSetup() {
    //Creating players
    Player playerOne(1);
    Computer computerTwo(2);

    playerOne.showOnlyPlayer();
    cout << endl << "Player 1 will now choose the locations of the ships!" << endl;
    manualOrAuto(playerOne);

    computerTwo.showOnlyPlayer();
    cout << endl << "Computer 2 will now choose the locations of the ships!" << endl;
    computerTwo.placeShipsAuto();

    gameplay(playerOne, computerTwo);
}

// Computer vs Computer setup
void Battleship::CVCSetup() {
    //Creating players
    Computer computerOne(1);
    Computer computerTwo(2);

    computerOne.showOnlyPlayer();
    cout << endl << "Computer 1 will now choose the locations of the ships!" << endl;
    computerOne.placeShipsAuto();

    computerTwo.showOnlyPlayer();
    cout << endl << "Computer 2 will now choose the locations of the ships!" << endl;
    computerTwo.placeShipsAuto();

    gameplay(computerOne, computerTwo);
}

// Deciding whether the player will manually place ships or let the autoplacement do it
void Battleship::manualOrAuto(Player& player) {
    int choice = 0;
    cout << endl << "Type 1 to generate a board for you." << endl;
    cout << "Type 2 to make the board yourself." << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Type here: ";
        cin >> choice;
        if (choice == 1 || choice == 2) {
            break;
        }
    }

    if (choice == 1) {
        player.placeShipsAuto();
    }
    else if (choice == 2) {
        player.placeShips();
    }
    else {
        cout << "Reached Limit of input. Start over." << endl;
    }
}

// Player vs Player Turn Management
void Battleship::gameplay(Player& playerOne, Player& playerTwo) {
    bool gameEnded = false;
    int loser = 0;

    // Show boards at start
    cout << endl << endl << "Game Start!" << endl;
    playerOne.showOnlyPlayer();
    playerTwo.showOnlyPlayer();

    // Loop for entire game
    while (gameEnded == false) {
        cout << endl << "Turn " << turnNum + 1 << endl;
        //Player 1 attacks, Player 2 checks
        if (playerOne.checkShipHealth() == true) {
            int att = playerOne.sendAttack();
            bool result = playerTwo.checkAttack(att);
            if (result == true) {
                cout << "Player 1 has successfully hit square " << result << "!" << endl;
            }
            else if (att == -2) { //Ran out of guesses
                cout << "Player 1 is out of guesses." << endl;
                cout << "Player 1 has lost the game." << endl;
                gameEnded = true;
                loser = 2;
            }
            else {
                cout <<  "Player 1 has missed." << endl;
            }
            playerOne.modifyEnemyGrid(playerTwo.passOwnGrid());
        }
        else {
            cout << "Player 1 has lost the game." << endl;
            loser = 1;
            break;
        }
        playerOne.showOnlyPlayer();

        //Player 2 attacks, Player 1 checks
        if (playerTwo.checkShipHealth() == true) {
            int att = playerTwo.sendAttack();
            bool result = playerOne.checkAttack(att);
            if (result == true) {
                cout << "Player 2 has successfully hit square " << result << "!" << endl;
            }
            else if (att == -2) { //Ran out of guesses
                cout << "Player 2 is out of guesses." << endl;
                cout << "Player 2 has lost the game." << endl;
                gameEnded = true;
                loser = 2;
            }
            else {
                cout << "Player 2 has missed." << endl;
            }
            playerTwo.modifyEnemyGrid(playerOne.passOwnGrid());
        }
        else {
            cout << "Player 2 has lost the game." << endl;
            loser = 2;
            break;
        }
        playerTwo.showOnlyPlayer();
        
        turnNum++;
        sleep(1);
    }

    endgame(loser, turnNum);
}

// Player vs Computer Turn Management
void Battleship::gameplay(Player& playerOne, Computer& computerTwo) {
    bool gameEnded = false;
    int loser = 0;

    // Show boards at start
    cout << endl << endl << "Game Start!" << endl;
    playerOne.showOnlyPlayer();
    computerTwo.showOnlyPlayer();
    
    // Loop for entire game
    while (gameEnded == false) {
        cout << endl << "Turn " << turnNum + 1 << endl;
        //Player 1 attacks, Player 2 checks
        if (playerOne.checkShipHealth() == true) {
            int att = playerOne.sendAttack();
            bool result = computerTwo.checkAttack(att);
            if (result == true) {
                cout << "Player 1 has successfully hit square " << result << "!" << endl;
            }
            else if (att == -2) { //Ran out of guesses
                cout << "Player 1 is out of guesses." << endl;
                cout << "Player 1 has lost the game." << endl;
                gameEnded = true;
                loser = 2;
            }
            else {
                cout <<  "Player 1 has missed." << endl;
            }
            playerOne.modifyEnemyGrid(computerTwo.passOwnGrid());
        }
        else {
            cout << "Player 1 has lost the game." << endl;
            loser = 1;
            break;
        }
        playerOne.showOnlyPlayer();

        //Computer 2 attacks, Player 1 checks
        if (computerTwo.checkShipHealth() == true) {
            int att = computerTwo.sendAttackAuto();
            bool result = playerOne.checkAttack(att);
            computerTwo.setSuccess(result);
            if (result == true) {
                cout << "Computer 2 has successfully hit square " << result << "!" << endl;
            }
            else if (att == -2) { //Ran out of guesses
                cout << "Computer 2 is out of guesses." << endl;
                cout << "Computer 2 has lost the game." << endl;
                gameEnded = true;
                loser = 2;
            }
            else {
                cout << "Computer 2 has missed." << endl;
            }
            computerTwo.modifyEnemyGrid(playerOne.passOwnGrid());
        }
        else {
            cout << "Computer 2 has lost the game." << endl;
            loser = 2;
            break;
        }
        computerTwo.showOnlyPlayer();
        
        turnNum++;
        sleep(1);
    }

    endgame(loser, turnNum);
}

// Computer vs Computer Turn Management
void Battleship::gameplay(Computer& computerOne, Computer& computerTwo) {
    bool gameEnded = false;
    int loser = 0;

    // Show boards at start
    cout << endl << endl << "Game Start!" << endl;
    computerOne.showOnlyPlayer();
    computerTwo.showOnlyPlayer();
    
    // Loop for entire game
    while (gameEnded == false) {
        cout << endl << "Turn " << turnNum + 1 << endl;
        //Computer 1 attacks, Computer 2 checks
        if (computerOne.checkShipHealth() == true) {
            int att = computerOne.sendAttackAuto();
            bool result = computerTwo.checkAttack(att);
            computerOne.setSuccess(result);
            if (result == true) {
                cout << "Computer 1 has successfully hit square " << result << "!" << endl;
            }
            else if (att == -2) { //Ran out of guesses
                cout << "Computer 1 is out of guesses." << endl;
                cout << "Computer 1 has lost the game." << endl;
                gameEnded = true;
                loser = 2;
            }
            else {
                cout <<  "Computer 1 has missed." << endl;
            }
            computerOne.modifyEnemyGrid(computerTwo.passOwnGrid());
        }
        else {
            cout << "Computer 1 has lost the game." << endl;
            loser = 1;
            break;
        }
        computerOne.showOnlyPlayer();

        //Computer 2 attacks, Computer 1 checks
        if (computerTwo.checkShipHealth() == true) {
            int att = computerTwo.sendAttackAuto();
            bool result = computerOne.checkAttack(att);
            computerTwo.setSuccess(result);
            if (result == true) {
                cout << "Computer 2 has successfully hit square " << result << "!" << endl;
            }
            else if (att == -2) { //Ran out of guesses
                cout << "Computer 2 is out of guesses." << endl;
                cout << "Computer 2 has lost the game." << endl;
                gameEnded = true;
                loser = 2;
            }
            else {
                cout << "Computer 2 has missed." << endl;
            }
            computerTwo.modifyEnemyGrid(computerOne.passOwnGrid());
        }
        else {
            cout << "Computer 2 has lost the game." << endl;
            loser = 2;
            break;
        }
        computerTwo.showOnlyPlayer();

        turnNum++;
        sleep(1);
    }

    endgame(loser, turnNum);
}

// Printing the endgame stats
void Battleship::endgame(int loser, int turnNum) {
    if (loser == 2) {
        cout << "The winner is Player one in " << turnNum << " turns!";
    }
    else if (loser == 1) {
        cout << "The winner is Player two in " << turnNum << " turns!";
    }
}
