#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <array>
#include <unistd.h>
#include "ship.h"
#include "location.h"

class Player {
protected:
    int shipAliveCount;
    int playerNumber;
    Ship shipTracker[5];
    Location playerView;
public:
    //Constructors functions
    Player();
    Player(int);
    void generateShips();

    //Placing Ships
    void placeShips();
    void placeShipsAuto();
    bool tryPlaceShip(Ship&, char, int, int);
    bool lengthCheck(int, char, int, int);
    array<int, 5> genTestCoordinates(int, char, int, int);
    bool occupationCheck(array<int, 5>, int);
    void updateShipCoor(Ship&, array<int, 5>, int);
    void placeInGrid(array<int, 5> testCoor, int, char);

    //Pre-Turn Check
    bool checkShipHealth();

    // Attack Turn
    int sendAttack();
    bool checkAttack(int coor);
    array<int, 100> passOwnGrid();
    void modifyEnemyGrid(array<int, 100>);

    // Display the player
    void showOnlyPlayer();
};

#endif // PLAYER_H
