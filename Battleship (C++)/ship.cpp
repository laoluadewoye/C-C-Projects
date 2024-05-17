#include "ship.h"

using namespace std;

Ship::Ship() {
    shipLength = 0;
    shipType = 0;
    directionFacing = ' ';
    shipCoordinates = nullptr;
    shipCoorStatus = nullptr;
    isSunk = true;
    alreadyDead = true;
    backArrow = 'N';

    printTest();
}

Ship::Ship(int type) {
    //General initialization
    directionFacing = 'R';
    isSunk = false;
    alreadyDead = false;
    backArrow = '<';

    //Type specific initialization
    byTypeinit(type);

    printTest();
}

void Ship::byTypeinit(int type) {
    shipType = type;

    switch(type) {
        case 1:
            shipLength = 2;
            break;
        case 2:
            shipLength = 3;
            break;
        case 3:
            shipLength = 3;
            break;
        case 4:
            shipLength = 4;
            break;
        case 5:
            shipLength = 5;
            break;
        default:
            cout << "You know who you are. Look in boat :)" << endl;
            break;
    }

    shipCoordinates = new int[shipLength];
    shipCoorStatus = new int[shipLength];
    defaultFill(shipCoordinates, shipCoorStatus);
}

void Ship::defaultFill(int* shipCoordinates, int* shipCoorStatus) {
    for (int i = 0; i < shipLength; i++) {
        shipCoordinates[i] = -1;
        shipCoorStatus[i] = -1;
    }
}

void Ship::printTest() {
    if (shipType == 0) {
        cout << "Something went wrong with creating the object. Look in boat." << endl;
    }
    else {
        cout << "Ship Type: " << shipType << endl;
    }
}

int Ship::getShipLength() {
    return shipLength;
}

int Ship::getShipType() {
    return shipType;
}

bool Ship::getAlreadyDead() {
    return alreadyDead;
}

void Ship::setAlreadyDead(bool newAD) {
    alreadyDead = newAD;
}

bool Ship::getIsSunk() {
    return isSunk;
}

void Ship::setIsSunk(bool newSunk) {
    isSunk = newSunk;
}

int* Ship::getShipCoordinates() {
    return shipCoordinates;
}

void Ship::setShipCoordinates(int* testCoor) {
    shipCoordinates = testCoor;
}

int* Ship::getShipCoorStatus() {
    return shipCoorStatus;
}

void Ship::setShipCoorStatus(int* tempCS) {
    shipCoorStatus = tempCS;
}
