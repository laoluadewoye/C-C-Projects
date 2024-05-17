#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"


class Computer : public Player //This should be able to select its own coors and chase after hits
{
private:
    //Main list of coordinates
    int* unusedCoor = new int[100];
    int unusedLength;

    //List of coordinates to target specifically
    int* aroundHit = new int[8]; //Array used by object to hit more. This array is reloaded with the below arary
    int AHLength;
    bool aroundHitEmpty;

    //List that generates new targets but doesn't immediately use
    int* newAround = new int[8]; //New array that gets made after every hit
    int NALength;

    bool attackSuccess; //variable is going to be changed and unchanged after a successful attack

public:
    //Constructor functions
    Computer();
    Computer(int);
    void computerSetup();

    //AI functionality
    int chooseCoordinate();
    int useAround(int);
    bool checkUnused(int);
    void updateUnused(int);
    void updateAround(int);
    void generateAround(int);
};

#endif // COMPUTER_H
