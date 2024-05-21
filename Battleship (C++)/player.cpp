#include "player.h"

using namespace std;

// Default Player constructor class
Player::Player() {
    cout << "Default Player created";
    srand(time(NULL));
}

// ID-specific Player constructor class
Player::Player(int playerNum) {
    cout << "Player " << playerNum << " created" << endl;
    srand(time(NULL));

    playerNumber = playerNum;

    generateShips();
}

// Generate the five ships for the player
void Player::generateShips() {
    for (int i = 0; i < 5; i++) {
        shipTracker[i] = Ship(i+1);
    }
}

// Main function for player manually placing ships
void Player::placeShips() {
    int currentShip = 0;
    do {
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
            cout << "Enter letter here: ";
            cin >> direction;
            if (direction == 'R' || direction == 'L' || direction == 'U' || direction == 'D') {
                directionCheck = true;
                break;
            }
        }

        //Do final check
        if (vertCheck && horiCheck && directionCheck) {
            mainCheck = tryPlaceShip(shipTracker[currentShip], direction, vert, hori);
        }

        //Move on to next ship if placement was successful
        if (mainCheck) {
            currentShip++;
        }
        else {
            cout << "Check failed. Please try again" << endl;
        }
    } while (currentShip < 5);

    cout << "All ships are set." << endl;
    sleep(4);
}

// Main function for player automatically placing ships
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

            mainCheck = tryPlaceShip(shipTracker[i], direction, vert, hori);

            if (mainCheck) {
                success = true;
            }
        }
    }
    cout << endl << endl << "All ships are set." << endl;
    sleep(4);
}

// Attempt to place the ship with given coordinates and direciton
bool Player::tryPlaceShip(Ship& ship, char direction, int vert, int hori) {
    bool mainCheck = false;
    bool occCheck = false;
    bool lenCheck;

    array<int, 5> testCoor;

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

        updateShipCoor(ship, testCoor, slotCount); //Update ship properties
        placeInGrid(testCoor, slotCount, direction); //Lock placements in grid
        showOnlyPlayer(); //Show and purge
    }

    return mainCheck;
}

// Check if the head of the ship extends off the board
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

// Generate coordinates to test on board
array<int, 5> Player::genTestCoordinates(int len, char dir, int vert, int hori) {
    array<int, 5> testCoor = {-1, -1, -1, -1, -1};

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

// Check if squares to place ship on are free
bool Player::occupationCheck(array<int, 5> testCoor, int len) {
    bool allClear = true;

    //Check indexes on players own grid
    for (int i = 0; i < len; i++) {
        int tempIndex = testCoor[i];
        bool gridCheck = playerView.checkOwnEmpty(tempIndex);
        if (gridCheck == false) {
            allClear = false;
        }
    }

    return allClear;
}

// Update the ship's coordinates and coordinate status
void Player::updateShipCoor(Ship& ship, array<int, 5> testCoor, int len) {
    ship.setShipCoordinates(testCoor);

    array<int, 5> tempCS = {-1, -1, -1, -1, -1};
    for (int i = 0; i < len; i++) {
        tempCS[i] = 1; //1 means alive
    }
    ship.setShipCoorStatus(tempCS);
}

// Place the ship in grid
void Player::placeInGrid(array<int, 5> testCoor, int len, char dir) {
    //Place the tail
    int shiptail;
    switch(dir) {
    case 'R':
        shiptail = 3;
        break;
    case 'L':
        shiptail = 4;
        break;
    case 'U':
        shiptail = 5;
        break;
    case 'D':
        shiptail = 6;
        break;
    }
    playerView.setOwnIndex(testCoor[0], shiptail);

    //Place the middle
    for (int i = 1; i < (len - 1); i++) {
        int tempIndex = testCoor[i];
        const int SHIPMID = 2;
        playerView.setOwnIndex(tempIndex, SHIPMID);
    }

    //Place the head
    const int SHIPHEAD = 1;
    playerView.setOwnIndex(testCoor[len - 1], SHIPHEAD);
}

// Checking if all five ships still have a healthy part left
bool Player::checkShipHealth() {
    bool notAllDead = false;
    int shipIndex = 0;
    int ALIVE = 1;

    // Using Ship Tracker to check attack
    while (notAllDead == false && shipIndex < 5) {
        array<int, 5> shipCoor = shipTracker[shipIndex].getShipCoorStatus();
        for (int i = 0; i < 5; i++) {
            if (shipCoor[i] == ALIVE) {
                notAllDead = true;
                break;
            }
        }
        shipIndex++;
    }

    return notAllDead;

}

// Sending an attack to the other player
int Player::sendAttack() {
    bool attackSuccess = false;
    bool horiCheck, vertCheck;
    int hori, vert, coor;

    // Ask player to strike
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
        return coor;
    }
    else {
        cout << "Coordinates were found incorrect. Turn must be skipped." << endl;
        return -1; //Meaning no square was hit
    }
}

// Checking an attack from another player
bool Player::checkAttack(int coor) { //Index to check
    bool attackSuccess = false;
    int shipIndex = 0;

    // Using Ship Tracker to check attack
    while (attackSuccess == false && shipIndex < 5) {
        array<int, 5> shipCoor = shipTracker[shipIndex].getShipCoordinates();
        for (int i = 0; i < 5; i++) {
            if (shipCoor[i] == coor) {
                //Set status to true, modify the coor status index, and update the board
                attackSuccess = true;
                shipTracker[shipIndex].setShipCoorStatusIndex(i, 2);
                playerView.setOwnIndex(coor, 7);
            }
        }
        shipIndex++;
    }

    //Put miss if the success is still false
    if (attackSuccess == false) {
        playerView.setOwnIndex(coor, 9);
    }

    //Using Location to check attack. It's obviously more efficient I just want to use Ship ngl
    // attackSuccess = playerView.checkEnemyAttack(coor);
    // if (attackSuccess) {
    //     playerView.setOwnIndex(coor, 7); //Add hit to board
    // }

    return attackSuccess;
}

// Sending grid up to battleship level
array<int, 100> Player::passOwnGrid() {
    return playerView.getOwnGrid();
}

// Modifying view of enemy grid with updated enemy grid
void Player::modifyEnemyGrid(array<int, 100> enemyGrid) {
    for (int i = 0; i < 100; i++) {
        playerView.setEnemyIndex(i, enemyGrid[i]);
    }
}

// Showing the player's view of the game
void Player::showOnlyPlayer() {
    cout << endl << "Player " << playerNumber << "'s Board";
    playerView.printOwnGrid();

    cout << endl << "Enemy's Board";
    playerView.printEnemyGrid();
}
