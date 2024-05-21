#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "grid.h"
#include "location.h"
#include "ship.h"
#include "player.h"
#include "computer.h"
#include "battleship.h"

using namespace std;

void testGrid() {
    // Create random seed
    srand(time(NULL));

    // Initialize and print
    Grid g;
    g.printGridDisplay(1);

    //Fuzz test the grid inputs
    for(int i = 0; i < 1000; i++) {
        g.setIndexStatus(floor(rand() % 100), floor(rand() % 11));
    }
    g.printGridDisplay(1);

    // Swap grids
    Grid g2;
    for(int i = 0; i < 100; i++) {
        g2.setIndexStatus(i, 7); // Fully struck board
    }

    Grid temp;

    temp.setGrid(g2.getGrid());
    g2.setGrid(g.getGrid());
    g.setGrid(temp.getGrid());

    g.printGridDisplay(1);

    // Get an index
    cout << g.getIndexStatus(72) << endl;
}

void testLocation() {
    //Initialize
    Location view;
    view.printOwnGrid();
    view.printEnemyGrid();

    // Filter testing
    for(int i = 0; i < 10; i++) {
        view.setEnemyIndex(i, i);
    }
    view.printEnemyGrid();

    // Square checking
    view.setOwnIndex(0, 0); // Empty space
    view.setOwnIndex(1, 1); // Start of ship

    cout << "Enemy at 0: " << view.checkEnemyAttack(0) << endl;
    cout << "Enemy at 1: " << view.checkEnemyAttack(1) << endl;

    cout << "Empty at 0: " << view.checkOwnEmpty(0) << endl;
    cout << "Empty at 1: " << view.checkOwnEmpty(1) << endl;
}

void testShip() {
    //Initialize
    Ship def;
    Ship ship = Ship(5);

    //Print
    cout << ship.getShipCoordinates()[0] << endl;
    cout << ship.getIsSunk() << endl;
    cout << ship.getShipLength() << endl;
}

void testPlayer() {
    int numWrong = 0;

    //100 rounds of fuzzing for boards
    for (int i = 0; i < 30; i++) {
        //Test ship placement with random attempts
        Player p = Player(1);
        p.placeShipsAuto();

        //Check the grid
        array<int, 100> testGrid = p.passOwnGrid();
        int numFilled = 0;
        for (int i = 0; i < 100; i++) {
            if (testGrid[i] != 0) {
                numFilled++;
            }
        }

        //See if its a bad grid
        if (numFilled != 17) {
            numWrong++;
        }
    }

    cout << "# of bad boards: " << numWrong << endl;

    // Player interactions
    Computer p1 = Computer(1);
    p1.placeShipsAuto();

    Computer p2 = Computer(2);
    p2.placeShipsAuto();

    int alive = p1.checkShipHealth();
    if (alive == true) {
        int att = p1.sendAttackAuto();
        bool result = p2.checkAttack(att);
        if (result == true) {
            p1.modifyEnemyGrid(p2.passOwnGrid());
        }
    }
    else {
        cout << "Player 1 has lost the game." << endl;
    }

    p1.showOnlyPlayer();
    p2.showOnlyPlayer();
}

void testSet() {
    testGrid();
    testLocation();
    testShip();
    testPlayer();
}

void game() {
    Battleship game;
    game.startBattleship();
}

int main() {
    // Testing Functionality
    //testSet();

    // Running the game
    game();

    int a;
    cout << endl << "Press any letter/number then press enter key to close the program..." << endl;
    cin >> a;

    return 0;
}

