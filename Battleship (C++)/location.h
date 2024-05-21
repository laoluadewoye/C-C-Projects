#ifndef LOCATION_H
#define LOCATION_H

#include "grid.h"

class Location {
private:
    Grid Own;
    Grid Enemy;
public:
    //Constructor
    Location();

    //Own Grid Functions
    void printOwnGrid();
    array<int, 100> getOwnGrid();

    // Enemy Grid Functions
    void printEnemyGrid();
    void setEnemyGrid(array<int, 100>);
    array<int, 100> getEnemyGrid();

    // Clear Utility
    void clearScreen();

    // Checking emptiness for placement
    bool checkOwnEmpty(int);

    // Checking attack from enemy
    bool checkEnemyAttack(int);

    // Index Setter functions
    void setOwnIndex(int, int);
    void setEnemyIndex(int, int);
};

#endif // LOCATION_H
