#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <iostream>
#include "player.h"
#include "computer.h"

using namespace std;

class Battleship {
private:
    int turnNum;
    int* tempOppHold;
    bool lastTurnSucc;
    int lastCoordinate;
public:
    //Beginning constructor and functions
    Battleship();
    void startBattleship();

    //Setup functions
    void PVPSetup();
    void PVCSetup();
    void CVCSetup();
    void manualOrAuto(Player);

    //Gameplay functions
    void gameplay(Player, Player);
    void gameplay(Player, Computer);
    void gameplay(Computer, Computer);
    bool playerAction(Player);
    bool computerAction(Computer);

    //Endgame functions
    void endGame(Player, Player);
    void endGame(Player, Computer);
    void endGame(Computer, Computer);
};

#endif // BATTLESHIP_H
