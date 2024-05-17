#ifndef GRID_H
#define GRID_H

#include <iostream>

using namespace std;

class Grid {

private:
    int* battlefield = new int[100];

public:
    //Constructor functions
    Grid();
    void populateGrid();

    //Printing
    void printGridDisplay();
    char numSymbolTrans(int);

    //Other basic functions
    int* getGrid();
    void setGrid(int*);
    int getIndexStatus(int);
    void setIndexStatus(int, int);
};

#endif // GRID_H
