#include "grid.h"

#ifndef LOCATION_H
#define LOCATION_H

class Location {
private:
    Grid Own;
    Grid Enemy;
    Grid EnemyProgress;
public:
    //Constructor
    Location();

    //Basic operations
    void printOwnGrid();
    void printProgressGrid();
    int* getOwnGrid();
    void setEnemyGrid(int*);
    int* getEnemyGrid();
    int* getProgressGrid();
    void setEnemyGrid();
    void clearScreen();

    bool checkOwnIndex(int);
    bool checkEnemyAttack(int);
    void setOwnIndex(int, int);
    void setProgressIndex(int, int);
    void setEnemyIndex(int, int);
};

#endif // LOCATION_H
