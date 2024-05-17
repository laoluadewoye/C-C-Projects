#include "grid.h"

using namespace std;

Grid::Grid() {
    populateGrid();
}

void Grid::populateGrid() {
    for (int i = 0; i < 100; i++) {
        battlefield[i] = 0;
    }
    cout << "Grid populated" << endl;
}

void Grid::printGridDisplay() {
    //Top line
    cout << endl << "   -----------------------------------------" << endl;

    for (int i = 0; i < 10; i++) {
        //Row Label
        cout << " " << i << " ";

        //Row
        for (int j = 0; j < 10; j++) {
            int num = (i * 10) + j;
            cout << "| " << numSymbolTrans(battlefield[num]) << " ";
        }
        cout << "|" << endl << "   -----------------------------------------" << endl;
    }

    cout << "     0   1   2   3   4   5   6   7   8   9" << endl;
}

char Grid::numSymbolTrans(int num) {
    switch(num) {
    case 0: //Empty
        return ' ';
    case 1: //Front of Ship
        return '@';
    case 2: //Middle of ship
        return 'O';
    case 3: //End of ship (right)
        return '>';
    case 4: //End of ship (left)
        return '<';
    case 5: //End of ship (up)
        return 'A';
    case 6: //End of ship (down)
        return 'V';
    case 7: //Target hit
        return 'X';
    case 8: //Target sunk
        return '!';
    case 9: //Target missed
        return '?';
    default:
        return 'Z';
    }
}

int* Grid::getGrid() {
    return battlefield;
}

void Grid::setGrid(int* newGrid) {
    battlefield = newGrid;
}

int Grid::getIndexStatus(int tempIndex) {
    return battlefield[tempIndex];
}

void Grid::setIndexStatus(int tempIndex, int status) {
    battlefield[tempIndex] = status;
}
