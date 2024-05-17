#include <iostream>

#ifndef SHIP_H
#define SHIP_H

using namespace std;

class Ship {
private:
    int shipLength;
    int shipType; //Destroyer = 1, Submarine = 2, Cruiser = 3, Battleship = 4, Carrier = 5
    char directionFacing; //R (right), L (left), U (up), D (down)
    int* shipCoordinates; //{XX, XX, XX, XX, XX} --> This tracks GRID INDEXES, and will be calculated with coordinates
    int* shipCoorStatus; //{X, X, X, X, X} --> -1 = null, 1 = alive, 2 = hit, 3 = dead
    bool isSunk;
    bool alreadyDead;
    char backArrow;

public:
    //Constructor functions
    Ship();
    Ship(int);
    void byTypeinit(int);
    void defaultFill(int*, int*); //Coor THEN Status
    void printTest();

    //Basic operations
    int getShipLength();
    int getShipType();
    bool getAlreadyDead();
    void setAlreadyDead(bool);
    bool getIsSunk();
    void setIsSunk(bool);
    int* getShipCoordinates();
    void setShipCoordinates(int*);
    int* getShipCoorStatus();
    void setShipCoorStatus(int*);
};

#endif // SHIP_H
