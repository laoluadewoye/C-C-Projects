#include "grid.h"

using namespace std;

// Grid Constructor
Grid::Grid() {
    populateGrid();
}

// Set all grid spaces to zero
void Grid::populateGrid() {
    for (int i = 0; i < 100; i++) {
        battlefield[i] = 0;
    }
    cout << "Grid populated" << endl;
}

// Print out the Grid Display
void Grid::printGridDisplay(int boardtype) { //1 = Own, 2 = Enemy
    //Top line
    cout << endl << "     0   1   2   3   4   5   6   7   8   9" << endl;
    cout << "   -----------------------------------------" << endl;

    for (int i = 0; i < 10; i++) {
        //Row Label
        cout << " " << i << " ";

        //Row
        for (int j = 0; j < 10; j++) {
            int num = (i * 10) + j;

            //Type logic
            if (battlefield[num] == 9 && boardtype == 1) {
                cout << "| " << numSymbolTrans(0) << " ";
            }
            else {
                cout << "| " << numSymbolTrans(battlefield[num]) << " ";
            }
        }
        cout << "| " << i << endl << "   -----------------------------------------" << endl;
    }

    cout << "     0   1   2   3   4   5   6   7   8   9" << endl;
}

// Number Conversion Case Table
char Grid::numSymbolTrans(int num) {
    switch(num) {
    case 0: //Empty
        return ' ';
    case 1: //Front of Ship
        return '@';
    case 2: //Middle of ship
        return 'O';
    case 3: //End of ship (right)
        return '<';
    case 4: //End of ship (left)
        return '>';
    case 5: //End of ship (up)
        return 'V';
    case 6: //End of ship (down)
        return 'A';
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

// Return grid down the call stack
array<int, 100> Grid::getGrid() {
    return battlefield;
}

// Set grid to a new set of values
void Grid::setGrid(array<int, 100> newGrid) {
    battlefield = newGrid;
}

// Get the index status at a grid point
int Grid::getIndexStatus(int tempIndex) {
    return battlefield[tempIndex];
}

// Set the index status at a grid point
void Grid::setIndexStatus(int tempIndex, int status) {
    battlefield[tempIndex] = status;
}
