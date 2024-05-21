#include "location.h"

// Empty Constructor class
Location::Location() {

}

//Print function for own grid
void Location::printOwnGrid() {
    Own.printGridDisplay(1);
}

// Getter function for own grid
array<int, 100> Location::getOwnGrid() {
    return Own.getGrid();
}

// Print function for enemy grid
void Location::printEnemyGrid() {
    Enemy.printGridDisplay(2);
}

// Setter function for enemy grid
void Location::setEnemyGrid(array<int, 100> enemyGrid) {
    Enemy.setGrid(enemyGrid);
}

// Getter function for enemy grid
array<int, 100> Location::getEnemyGrid() {
    return Enemy.getGrid();
}

// Clearing Screen utility
void Location::clearScreen() {
    for (int i = 0; i < 150; i++) {
        cout << endl;
    }
}

// Check index for an empty spot
bool Location::checkOwnEmpty(int tempIndex) {
    bool gridCheck = false;
    int status = Own.getIndexStatus(tempIndex);
    if (status == 0) { // Code for empty spot
        gridCheck = true;
    }
    return gridCheck;
}

// Attack process
// Player 1 sends an attack to Player 2
// Player 2 checks their board
// If there is a hit, Player two will send a message back saying so.
bool Location::checkEnemyAttack(int tempIndex) {
    bool gridCheck = false;
    int status = Own.getIndexStatus(tempIndex);
    if (status >= 1 && status <= 6) { // Codes for ship parts
        gridCheck = true;
    }
    return gridCheck;
}

// Setting index on own board
void Location::setOwnIndex(int tempIndex, int status) {
    int oldStatus = Own.getIndexStatus(tempIndex);

    //Only place misses in empty spots
    if (oldStatus != 0 && status == 9) {
        status == oldStatus;
    }

    Own.setIndexStatus(tempIndex, status);
}

// Setting index on enemy board
// Enemy board must be able to preserve misses
void Location::setEnemyIndex(int tempIndex, int status) {
    //Check Index Status
    int tempStatus = Enemy.getIndexStatus(tempIndex);

    // Ship filter
    if (status >= 1 && status <= 6) {
        status = 0;
    }

    // Question filter
    if (tempStatus == 9) {
        status = 9;
    }

    Enemy.setIndexStatus(tempIndex, status);
}
