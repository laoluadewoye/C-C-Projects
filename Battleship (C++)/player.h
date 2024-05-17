#include "ship.h"
#include "location.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#ifndef PLAYER_H
#define PLAYER_H

class Player {
protected:
    int shipAliveCount;
    int scoreCount;
    int playerNumber;
    Ship shipTracker[5];
    int coorCatalog[22]; // -2, X, X, -2, X, X, X, -2, X, X, X, -2, X, X, X, X, -2, X, X, X, X, X --> 22 slots
    Location playerView;
    int* newSinkSelf; // {0 or 1, length of list of coordinates, subsequent arrays} --> {XX, XX, XX x 5}
    int* newSinkOpp; //Accepts the opponents coordinates to check
    //Work on this later

    bool opponentSucc; //Whether your opponent hit you
    bool succesfulHit; //Whether you hit your opponent
    int lastUsedIndex;
public:
    //Constructors functions
    Player();
    Player(int);
    void generateShips();
    void createCatalog();

    //Ship placement
    void placeShips();
    void placeShipsAuto();
    bool shipCheck(Ship, char, int, int);
    bool lengthCheck(int, char, int, int);
    int* genTestCoordinates(int, char, int, int);
    bool occupationCheck(int*, int);
    void addToCatalog(Ship, int*, int);
    void updateShipCoor(Ship, int*, int);
    void placeInGrid(int*, int, char);

    //Enemy Grid Sharing
    void acceptEnemyGrid(int*);
    int* sendOwnGrid();

    bool preTurnTasks();
    bool hitCheck(int*, int);
    void setDeadStatus(Ship);
    bool attackShips(int); //Change to void

    //Basic functions
    void showOnlyPlayer();
    void displayTurn();
    void changeOwnGrid(int, int);
    void changeProgressGrid(int, int);
    int* getNewSink(); //Send own sink
    void setNewSink(int*); //Set opp sink
    bool sendSuccess();
    void setOppSucc(bool);
    int sendLastIndex();
    void setLastIndex(int);


};

#endif // PLAYER_H
