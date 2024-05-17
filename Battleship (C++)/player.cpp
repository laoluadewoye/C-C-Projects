#include "player.h"

using namespace std;

Player::Player() {
    cout << "Default Player created";
    srand (time(NULL));
}

Player::Player(int playerNum) {
    cout << "Player " << playerNum << " created" << endl;
    srand (time(NULL));

    shipAliveCount = 5;
    scoreCount = 0;
    playerNumber = playerNum;
    opponentSucc = false;
    succesfulHit = false;
    lastUsedIndex = 0;

    newSinkSelf = new int[1];
    newSinkSelf[0] = 0;
    newSinkOpp = new int[1];
    newSinkOpp[0] = 0;

    //PlayerView is already technically initialized

    generateShips();
    createCatalog();
}

void Player::generateShips() {
    for (int i = 0; i < 5; i++) {
        shipTracker[i] = Ship(i+1);
    }
}

void Player::createCatalog() {
    //Variables
    int iter = -1;
    int shipIndex = 0;
    int slotCount = 0;
    int* shipSlots;

    for (int i = 0; i < 22; i++) {
        if (slotCount == 0) {
            iter++; //0, 1
            slotCount = shipTracker[iter].getShipLength(); //2, 3
            shipSlots = shipTracker[iter].getShipCoordinates(); //{XX, XX}
            shipIndex = 0;
        }
        if (i == 0 || i == 3 || i == 7 || i == 11 || i == 16) { //Markers to check ship positions
            coorCatalog[i] = -2;
        }
        else {
            coorCatalog[i] = shipSlots[shipIndex]; //In coor slot 1 and 2, the first and second values are put
            shipIndex++; //Goes up twice
            slotCount--; //Goes down twice
        }
    }
    cout << endl;
    for (int i = 0; i < 22; i++) {
        cout << coorCatalog[i] << " ";
    }
}

void Player::placeShips() {
    int successSet = 0;

    for (int i = 0; i < 5; i++) {
        //Variables
        char direction;
        int vert, hori;

        //Checks
        bool vertCheck = false;
        bool horiCheck = false;
        bool directionCheck = false;
        bool mainCheck = false;

        //Select position
        cout << "Choose the square to place your ship." << endl;
        cout << "When you choose a square, type in a letter, then number using the board above." << endl;
        cout << "Once you pick, it will generate the ship starting from the back to the front." << endl;
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

        //Select direction
        cout << "Which direction is your ship facing?" << endl;
        cout << "\nRight (R)\nLeft (L)\nUp (U)\nDown (D)\n" << endl; //R (right), L (left), U (up), D (down)
        for (int i = 0; i < 3; i++) {
            cout << "Enter number here: ";
            cin >> direction;
            if (direction == 'R' || direction == 'L' || direction == 'U' || direction == 'D') {
                directionCheck = true;
                break;
            }
        }

        if (vertCheck && horiCheck && directionCheck) {
            mainCheck = shipCheck(shipTracker[i], direction, vert, hori);

            if (mainCheck) {
                successSet++;
            }
            else {
                cout << "Check failed. Please try again" << endl;
                break;
            }
        }
        else {
            cout << "One of the responses was incorrect, please try again" << endl;
            break;
        }
    }

    if (successSet == 5) {
        cout << "All ships are set." << endl;
        Sleep(4000);
    }
}

void Player::placeShipsAuto() {
    for (int i = 0; i < 5; i++) {
        bool success = false;

        while (success == false) {
            //Variables
            char direction;
            int vert, hori, dirNum;
            bool mainCheck = false;

            //Select position
            hori = rand() % 10;
            vert = rand() % 10;

            //Select direction
            dirNum = (rand() % 4) + 1;
            switch (dirNum) {
            case 1:
                direction = 'R';
                break;
            case 2:
                direction = 'L';
                break;
            case 3:
                direction = 'U';
                break;
            case 4:
                direction = 'D';
                break;
            }

            mainCheck = shipCheck(shipTracker[i], direction, vert, hori);

            if (mainCheck) {
                success = true;
            }
        }
    }
    cout << endl << endl << "All ships are set." << endl;
    Sleep(4000);
}

bool Player::shipCheck(Ship ship, char direction, int vert, int hori) {
    //First, Create a player-hosted catalog of ship coordinates before doing anything here.
    //Ship coordinates will calculated BEFORE being stored
    bool mainCheck = false;
    bool occCheck = false;
    bool lenCheck;

    int* testCoor;

    //Get ship length
    int slotCount = ship.getShipLength();

    //Check the length against a given direction
    lenCheck = lengthCheck(slotCount, direction, vert, hori);
    if (lenCheck) {
        //Occupation Check
        testCoor = genTestCoordinates(slotCount, direction, vert, hori);
        occCheck = occupationCheck(testCoor, slotCount);
    }

    if (occCheck) {
        mainCheck = true; //Confirm truth

        addToCatalog(ship, testCoor, slotCount);
        updateShipCoor(ship, testCoor, slotCount);
        placeInGrid(testCoor, slotCount, direction);

        showOnlyPlayer();
    }

    return mainCheck;
}

bool Player::lengthCheck(int len, char dir, int vert, int hori) {
    bool lenCheck = true;

    switch (dir) {
    case 'R':
        if (hori + len - 1 > 9) {
            lenCheck = false;
        }
        break;
    case 'L':
        if (hori - len + 1 < 0) {
            lenCheck = false;
        }
        break;
    case 'U':
        if (vert - len + 1 < 0) {
            lenCheck = false;
        }
        break;
    case 'D':
        if (vert + len - 1 > 9) {
            lenCheck = false;
        }
        break;
    }

    return lenCheck;
}

int* Player::genTestCoordinates(int len, char dir, int vert, int hori) {
    int* testCoor = new int[len];

    //vert is 10s, hori is 1s
    testCoor[0] = vert * 10 + hori;

    switch (dir) {
    case 'R':
        for (int i = 1; i < len; i++) {
            testCoor[i] = vert * 10 + (hori + i);
        }
        break;
    case 'L':
        for (int i = 1; i < len; i++) {
            testCoor[i] = vert * 10 + (hori - i);
        }
        break;
    case 'U':
        for (int i = 1; i < len; i++) {
            testCoor[i] = (vert - i) * 10 + hori;
        }
        break;
    case 'D':
        for (int i = 1; i < len; i++) {
            testCoor[i] = (vert + i) * 10 + hori;
        }
        break;
    }

    return testCoor;
}

bool Player::occupationCheck(int* testCoor, int len) {
    bool allClear = true;

    //Check indexes on players own grid
    for (int i = 0; i < len; i++) {
        int tempIndex = testCoor[i];
        bool gridCheck = playerView.checkOwnIndex(tempIndex);
        if (gridCheck == false) {
            allClear = false;
        }
    }

    return allClear;
}

void Player::addToCatalog(Ship ship, int* testCoor, int len) {
    int shipNum = ship.getShipType();
    int catalogSpot = 0;
    int i = 0;
    while (catalogSpot < shipNum) {
        if (coorCatalog[i] == -2) {
            catalogSpot++;
        }
        i++;
    }

    for (int j = 0; j < len; j++) {
        coorCatalog[i] = testCoor[j];
        i++;
    }

    cout << endl;
    for (int j = 0; j < 22; j++) {
        cout << coorCatalog[j] << ", ";
    }
    cout << endl << endl;
}

void Player::updateShipCoor(Ship ship, int* testCoor, int len) {
    ship.setShipCoordinates(testCoor);

    int* tempCS = new int[len];
    for (int i = 0; i < len; i++) {
        tempCS[i] = 1; //1 means alive
    }
    ship.setShipCoorStatus(tempCS);
}
void Player::placeInGrid(int* testCoor, int len, char dir) {
    const int ALIVE = 1;
    playerView.setOwnIndex(testCoor[0], ALIVE);

    for (int i = 1; i < (len - 1); i++) {
        int tempIndex = testCoor[i];
        const int ALIVEMID = 2;
        playerView.setOwnIndex(tempIndex, ALIVEMID);
    }

    int tail;

    switch(dir) {
    case 'R':
        tail = 3;
        break;
    case 'L':
        tail = 4;
        break;
    case 'U':
        tail = 5;
        break;
    case 'D':
        tail = 6;
        break;
    }

    playerView.setOwnIndex(testCoor[len - 1], tail);
}

void Player::acceptEnemyGrid(int* enemyGrid) {
    playerView.setEnemyGrid(enemyGrid);
}

int* Player::sendOwnGrid() {
    return playerView.getEnemyGrid();
}

bool Player::preTurnTasks() {
    bool computerDone = false;
    bool shipAllHit;

    //Checking if a hit was successful
    if (opponentSucc) {
        int j = 0;
        //Use coor catalog to find the ship
        for (int i = 0; i < 22; i++) {
            if (coorCatalog[i] == -2) {
                j++;
            }
            else if (coorCatalog[i] == lastUsedIndex) {
                break;
            }
        }

        int* tempCoor = shipTracker[j-1].getShipCoordinates();
        int* tempStatus = shipTracker[j-1].getShipCoorStatus();
        int tempLen = shipTracker[j-1].getShipLength();

        int hitIndex;
        for (int i = 0; i < tempLen; i++) {
            if (tempCoor[i] == lastUsedIndex) {
                hitIndex = i;
                break;
            }
        }

        tempStatus[hitIndex] = 2;
        shipTracker[j-1].setShipCoorStatus(tempStatus);
    }

    //Checking ships status arrays. These will get sent later in the player action
    for (int i = 0; i < 5; i++) {
        shipAllHit = false;
        int* tempCoor = shipTracker[i].getShipCoordinates();
        int* tempStatus = shipTracker[i].getShipCoorStatus(); //Don't go down to grid, you have the statues right here
        int tempStatusLen = shipTracker[i].getShipLength();
        bool shipAD = shipTracker[i].getAlreadyDead();

        shipAllHit = hitCheck(tempStatus, tempStatusLen);

        if (shipAllHit == false || shipAD == true) {
            int* temp = new int[2];
            temp[0] = 0; //No new sinks
            temp[1] = 0;
            newSinkSelf = temp;
        }
        else {
            int* temp = new int[2 + tempStatusLen];
            temp[0] = 1; //New sinks
            temp[1] = tempStatusLen;
            for (int j = 2; j < (2 + tempStatusLen); j++) {
                temp[j] = tempCoor[j - 2];
            }
            newSinkSelf = temp;
            setDeadStatus(shipTracker[i]); //Work on this later
            break;
        }
    }

    //Check all ships separately
    int sunkCount = 0;
    for (int i = 0; i < 5; i++) {
        if (shipTracker[i].getIsSunk()) {
            sunkCount++;
        }
    }

    if (sunkCount == 5) {
        computerDone = true;
    }

    //Checking alive count
    if (shipAliveCount == 0) {
        computerDone = true;
    }
    else if (shipAliveCount < 0) {
        computerDone = true;
        cout << "Alive ships are below zero. Check code for any possible areas." << endl;
    }

    //Check an opponents status to update progress grid
    if (newSinkOpp[0] == 1) {
        int fullOppLength = 2 + newSinkOpp[1];
        for (int i = 2; i < fullOppLength; i++) {
            changeProgressGrid(newSinkOpp[i], 8);
        }
    }

    return computerDone;
}

bool Player::hitCheck(int* shipCoor, int len) {
    bool shipAllHit = false;
    int hitcounter = 0;

    for (int i = 0; i < len; i++) {
        if (shipCoor[i] == 2 || shipCoor[i] == 3) {
            hitcounter++;
        }
    }

    if (hitcounter == len) {
        shipAllHit = true;
    }

    return shipAllHit;
}

void Player::setDeadStatus(Ship ship) {
    ship.setIsSunk(true); //Set sunk to true
    ship.setAlreadyDead(true); //Set ship to already sunk

    //Set ship statuses
    int* tempStatus = ship.getShipCoorStatus();
    int tempStatusLen = ship.getShipLength();
    for (int i = 0; i < tempStatusLen; i++) {
        tempStatus[i] = 3;
    }
    ship.setShipCoorStatus(tempStatus);

    shipAliveCount--; //lower ship alive count

    //change the players own grid
    int* tempCoor = ship.getShipCoordinates();
    for (int i = 0; i < tempStatusLen; i++) {
        changeOwnGrid(tempCoor[i], 8);
    }
}

bool Player::attackShips(int coor) { //Index to check
    bool attackSuccess = false;

    attackSuccess = playerView.checkEnemyAttack(coor); //Work on this later

    if (attackSuccess) {
        //Grid editing
        playerView.setEnemyIndex(coor, 7); //Add hit to enemy
        playerView.setProgressIndex(coor, 7); //Add hit to progress

        //Player editing
        scoreCount++;

        //Let other player know there was a hit
        succesfulHit = true;
    }
    else {
        playerView.setProgressIndex(coor, 9); //Add miss to progress
        succesfulHit = false;
    }

    return attackSuccess;
}

void Player::showOnlyPlayer() {
    playerView.clearScreen();
    playerView.printOwnGrid();
}

void Player::displayTurn() {
    showOnlyPlayer();
    cout << endl << "Above grid is your Grid." << endl << endl;
    playerView.printProgressGrid();
    cout << endl << "Above grid is your enemy's Grid(so far)." << endl;
    cout << "Scroll up to see your grid. Hit more targets to populate your enemy's Grid." << endl << endl;
}

void Player::changeOwnGrid(int index, int status) {
    playerView.setOwnIndex(index, status);
}

void Player::changeProgressGrid(int index, int status) {
    playerView.setProgressIndex(index, status);
}

int* Player::getNewSink() {
    return newSinkSelf;
}

void Player::setNewSink(int* opp) {
    newSinkOpp = opp;
}

bool Player::sendSuccess() {
    return succesfulHit;
}

void Player::setOppSucc(bool lastTurnSucc) {
    opponentSucc = lastTurnSucc;
}

int Player::sendLastIndex() {
    return lastUsedIndex;
}
void Player::setLastIndex(int lastCoordinate) {
    lastUsedIndex = lastCoordinate;
}
