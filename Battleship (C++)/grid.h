#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <array>

using namespace std;

class Grid {
private:
    array<int, 100> battlefield;
public:
    //Constructor functions
    Grid();
    void populateGrid();

    //Printing
    void printGridDisplay(int);
    char numSymbolTrans(int);

    //Other basic functions
    array<int, 100> getGrid();
    void setGrid(array<int, 100>);
    int getIndexStatus(int);
    void setIndexStatus(int, int);
};

#endif // GRID_H
