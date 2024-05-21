#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"

class Computer : public Player { //This should be able to select its own coors and chase after hits
private:
    //Basic predictions
    array<int, 100> unusedCoor; //1 is unused, 0 is used
    int unusedLeft;

    //Smart stack to search for patterns
    array<int, 28> smartStack; //4 x 8, 4 for each direction, very bottom is reserved
    int smartStackCounter;

    //Last number and direction(-1 means no successful attack)
    bool lastSuccess;
    int lastCoor;
    int lastDir;
public:
    //Constructor functions
    Computer();
    Computer(int);

    //Array functions
    void deleteUsed(int);

    //Stack functions
    void pushStack(int);
    void popStack();
    void popDirection(int);

    //Setting functions
    void setSuccess(bool);

    // Attack functions
    int sendAttackAuto();
    int chooseSmart();
    int checkStack(int);
};

#endif // COMPUTER_H
