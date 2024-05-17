# include "battleship.h"

Battleship::Battleship() {
    turnNum = 0;
    tempOppHold = new int[1];
    tempOppHold[0] = 0;
    lastTurnSucc = false;
    lastCoordinate = 0;
}

void Battleship::startBattleship() {
    int choice = 0;

    cout << "Start!" << endl;
    cout << "Are you playing against another play or CPU? Enter answer below." << endl;
    cout << "Type 1 for two player game." << endl;
    cout << "Type 2 for player vs CPU." << endl;
    cout << "Type 3 for to watch two CPUs go at it." << endl;

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
        cout << "Wrong selections. Try again." << endl;
    }
}

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

    //Exchange grids - work on this later
    playerTwo.acceptEnemyGrid(playerOne.sendOwnGrid()); //P1 sends their grid to P2
    playerOne.acceptEnemyGrid(playerTwo.sendOwnGrid()); //P2 sends their grid to P1

    gameplay(playerOne, playerTwo);
}

void Battleship::PVCSetup() {
    Player playerOne(1);
    Computer computerTwo(2);

    playerOne.showOnlyPlayer();
    cout << endl << "Player 1 will now choose the locations of the ships!" << endl;
    manualOrAuto(playerOne);

    computerTwo.showOnlyPlayer();
    cout << endl << "Computer 2 will now choose the locations of the ships!" << endl;
    computerTwo.placeShipsAuto();

    //Exchange grids - work on this later
    computerTwo.acceptEnemyGrid(playerOne.sendOwnGrid()); //P1 sends their grid to P2
    playerOne.acceptEnemyGrid(computerTwo.sendOwnGrid()); //P2 sends their grid to P1

    gameplay(playerOne, computerTwo);
}

void Battleship::CVCSetup() {
    Computer computerOne(1);
    Computer computerTwo(2);

    computerOne.showOnlyPlayer();
    cout << endl << "Computer 1 will now choose the locations of the ships!" << endl;
    computerOne.placeShipsAuto();

    computerTwo.showOnlyPlayer();
    cout << endl << "Computer 2 will now choose the locations of the ships!" << endl;
    computerTwo.placeShipsAuto();

    //Exchange grids - work on this later
    computerTwo.acceptEnemyGrid(computerOne.sendOwnGrid()); //P1 sends their grid to P2
    computerOne.acceptEnemyGrid(computerTwo.sendOwnGrid()); //P2 sends their grid to P1

    gameplay(computerOne, computerTwo);
}

void Battleship::manualOrAuto(Player player) {
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

void Battleship::gameplay(Player playerOne, Player playerTwo) {
    Player playerCycle[2] = {playerOne, playerTwo};

    bool playerDone = false;
    while (playerDone == false) {
        turnNum++;
        for (int i = 0; i < 2; i++) {
            playerDone = playerAction(playerCycle[i]);
            if (playerDone) {
                break;
            }
        }
    }

    endGame(playerOne, playerTwo);
}

void Battleship::gameplay(Player playerOne, Computer computerTwo) {
    bool playerNotDone = true;
    bool computerNotDone = true;
    while (playerNotDone && computerNotDone) {
        turnNum++;
        playerNotDone = !(playerAction(playerOne));
        computerNotDone = !(computerAction(computerTwo));
    }

    endGame(playerOne, computerTwo);
}

void Battleship::gameplay(Computer computerOne, Computer computerTwo) {
    Computer computerCycle[2] = {computerOne, computerTwo};
    bool computerDone = false;
    while (computerDone == false) {
        turnNum++;
        for (int i = 0; i < 2; i++) {
            computerDone = computerAction(computerCycle[i]);
            if (computerDone) {
                break;
            }
        }
    }

    endGame(computerOne, computerTwo);
}

bool Battleship::playerAction(Player player) {
    bool playerDone = false;
    bool attackSuccess = false;
    bool horiCheck, vertCheck;
    int hori, vert, coor;

    //Pre-turn tasks
    player.setLastIndex(lastCoordinate);
    player.setOppSucc(lastTurnSucc);
    player.setNewSink(tempOppHold); //Get opp hold from last person
    playerDone = player.preTurnTasks();

    //Selection
    cout << "Turn number: " << turnNum << endl;
    player.displayTurn();

    if (playerDone) {
        return playerDone;
    }

    cout << "Which square do you want to strike? Enter in coordinates one at a time." << endl;
    cout << "Select a horizontal coordinate (this will be your x): ";
    cin >> hori;
    cout << "Select a vertical coordinate (this will be your y): ";
    cin >> vert;

    if (vert >= 0 && vert < 10) {
        vertCheck = true;
    }
    if (hori >= 0 && hori < 10) {
        horiCheck = true;
    }

    //Checks and Confirmation
    if (vertCheck && horiCheck) {
        coor = vert * 10 + hori;
        attackSuccess = player.attackShips(coor); //the player must adjust their opp hold during here
    }
    else {
        cout << "Coordinates were found incorrect. Turn must be skipped." << endl;
    }

    //Preparing information to give to player next turn
    tempOppHold = player.getNewSink(); //Set temp hold for next person
    lastTurnSucc = player.sendSuccess();
    lastCoordinate = player.sendLastIndex();

    //Final Verdict
    if (attackSuccess) {
        cout << "The attack was successful! You're on the trail." << endl;
    }
    else {
        cout << "The attack was a failure. Try again." << endl;
    }

    return playerDone;
}

bool Battleship::computerAction(Computer computer) {
    bool computerDone = false;
    bool attackSuccess = false;
    int coor;

    //Pre-turn tasks
    computer.setLastIndex(lastCoordinate);
    computer.setOppSucc(lastTurnSucc);
    computer.setNewSink(tempOppHold);
    computerDone = computer.preTurnTasks();

    cout << "Turn number: " << turnNum << endl;
    computer.displayTurn();

    if (computerDone) {
        return computerDone;
    }

    cout << "The Computer will select now." << endl;
    //Sleep timer here if you want

    coor = computer.chooseCoordinate();

    attackSuccess = computer.attackShips(coor);

    //Preparing information to give to player next turn
    tempOppHold = computer.getNewSink();
    lastTurnSucc = computer.sendSuccess();
    lastCoordinate = computer.sendLastIndex();

    if (attackSuccess) {
        cout << "The attack was successful! You're on the trail." << endl;
        //Generate a new potential list of specific targets
        computer.generateAround(coor);
    }
    else {
        cout << "The attack was a failure. Try again." << endl;
    }

    return computerDone;
}

void Battleship::endGame(Player playerOne, Player playerTwo) {

}

void Battleship::endGame(Player playerOne, Computer computerTwo) {

}

void Battleship::endGame(Computer computerOne, Computer computerTwo) {

}
