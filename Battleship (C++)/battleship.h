#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <iostream>
#include <unistd.h>
#include "player.h"
#include "computer.h"

using namespace std;

class Battleship {
private:
    int turnNum;
public:
    //Beginning constructor and functions
    Battleship();
    void startBattleship();

    //Setup functions
    void PVPSetup();
    void PVCSetup();
    void CVCSetup();
    void manualOrAuto(Player&);

    //Gameplay functions
    void gameplay(Player&, Player&);
    void gameplay(Player&, Computer&);
    void gameplay(Computer&, Computer&);

    //Endgame
    void endgame(int, int);
};

#endif // BATTLESHIP_H
