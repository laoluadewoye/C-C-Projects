#include "ship.h"

using namespace std;

//Default Constructor
Ship::Ship() {
    shipLength = 0;
    shipType = 0;
    directionFacing = ' ';
    isSunk = true;

    printTest();
}

// Type-specific constructor
Ship::Ship(int type) {
    //General initialization
    directionFacing = 'R';
    isSunk = false;

    //Type specific initialization
    byTypeinit(type);

    printTest();
}

//Set up the length and arrays
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

    defaultFill();
}

// Default filling coordinates
void Ship::defaultFill() {
    int FULLLENGTH = 5;
    for (int i = 0; i < FULLLENGTH; i++) {
        shipCoordinates[i] = -1;
        shipCoorStatus[i] = -1;
    }
}

// Check to make sure ship is properly initalized.
void Ship::printTest() {
    if (shipType == 0) {
        cout << "Something went wrong with creating the object. Look in boat." << endl;
    }
    else {
        cout << "Ship Type: " << shipType << endl;
    }
}

// Getter function for ship length
int Ship::getShipLength() {
    return shipLength;
}

// Setter function for ship length
int Ship::getShipType() {
    return shipType;
}

//Getter function for ship sink status
bool Ship::getIsSunk() {
    return isSunk;
}

//Setter function for ship sink status
void Ship::setIsSunk(bool newSunk) {
    isSunk = newSunk;
}

//Getter function for ship coordinates
array<int, 5> Ship::getShipCoordinates() {
    return shipCoordinates;
}

//Setter function for ship coordinates int(&newGrid)[100]
void Ship::setShipCoordinates(array<int, 5> testCoor) {
    for (int i = 0; i < shipLength; i++){
        shipCoordinates[i] = testCoor[i];
    }
}

//Getter function for ship status
array<int, 5> Ship::getShipCoorStatus() {
    return shipCoorStatus;
}

//Setter function for ship status
void Ship::setShipCoorStatus(array<int, 5> tempCS) {
    for (int i = 0; i < shipLength; i++){
        shipCoorStatus[i] = tempCS[i];
    }
}

void Ship::setShipCoorStatusIndex(int index, int status) {
    shipCoorStatus[index] = status;
}
