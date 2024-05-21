#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <array>

using namespace std;

class Ship {
private:
    int shipLength;
    int shipType; //Destroyer = 1, Submarine = 2, Cruiser = 3, Battleship = 4, Carrier = 5
    char directionFacing; //R (right), L (left), U (up), D (down)
    array<int, 5> shipCoordinates; //{XX, XX, XX, XX, XX} --> This tracks GRID INDEXES, and will be calculated with coordinates
    array<int, 5> shipCoorStatus; //{X, X, X, X, X} --> -1 = null, 1 = alive, 2 = hit, 3 = dead
    bool isSunk;
public:
    //Constructor functions
    Ship();
    Ship(int);
    void byTypeinit(int);
    void defaultFill();
    void printTest();

    //Getter-setter operations
    int getShipLength();
    int getShipType();
    bool getIsSunk();
    void setIsSunk(bool);
    array<int, 5> getShipCoordinates();
    void setShipCoordinates(array<int, 5>);
    array<int, 5> getShipCoorStatus();
    void setShipCoorStatus(array<int, 5>);
    void setShipCoorStatusIndex(int, int);
};

#endif // SHIP_H
