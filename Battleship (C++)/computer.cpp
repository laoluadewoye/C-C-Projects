#include "computer.h"

using namespace std;

// Default computer constructor class
Computer::Computer() {

}

// ID-specific computer constructor class
Computer::Computer(int computerNum) {
    cout << "Player " << computerNum << " created" << endl;
    srand(time(NULL));

    playerNumber = computerNum;

    unusedLeft = 100;

    smartStackCounter = 0;

    lastSuccess = false;
    lastCoor = -1;
    lastDir = -1;

    for (int i = 0; i < 100; i++) {
        unusedCoor[i] = i;
    }

    generateShips();
}

// Array Overwriting function to "delete" used numbers
void Computer::deleteUsed(int index) {
    unusedLeft--;

    for (int i = index; i < unusedLeft; i++) {
        unusedCoor[i] = unusedCoor[i+1];
    }
}

// Stack Push function for smartstack
void Computer::pushStack(int coor) {
    //Check if counter is below 24
    if (smartStackCounter < 28) {
        // Increment counter
        smartStackCounter = smartStackCounter + 4;

        //Up, down, left, right
        smartStack[smartStackCounter] = coor - 10; //Up
        smartStack[smartStackCounter+1] = coor + 10; //Down
        smartStack[smartStackCounter+2] = coor - 1; //Left
        smartStack[smartStackCounter+3] = coor + 1; //Right
    }
}

// Stack Pop function for smartstack
void Computer::popStack() {
    //Check if counter is above 3
    if (smartStackCounter > 3) {
        smartStackCounter = smartStackCounter - 4;
    }
}

// Direction-level popping for smartstack
void Computer::popDirection(int dirIndex) {
    //Up = 0, down = 1, left = 2, right = 3
    smartStack[smartStackCounter+dirIndex] = -1;
}

// Setting "last" variables to track previous guesses
void Computer::setSuccess(bool succStatus) {
    lastSuccess = succStatus;
    if (lastSuccess == false) {
        lastCoor = -1;
        lastDir = -1;
    }
}

// Main function for AI coordinate selection
int Computer::sendAttackAuto() {
    bool unusedCheck = false;
    int choiceIndex = -1;

    //Give up if choices are empty
    if (unusedLeft <= 0) {
        return -2;
    }


    int choice = chooseSmart();

    //Check if smart choice worked
    for (int i = 0; i < unusedLeft; i++) {
        if (choice == unusedCoor[i]) {
            unusedCheck = true;
            choiceIndex = i;
            break;
        }
    }

    // Do plain guess
    if (unusedCheck == false) {
        choiceIndex = rand() % unusedLeft;
        choice = unusedCoor[choiceIndex];
    }

    lastCoor = choice;
    deleteUsed(choiceIndex);

    return choice;
}

// Smart selection using the smartsnack
int Computer::chooseSmart() {
    int choice = -1;

    if (lastCoor != -1) { //Was the last attack successful?
        pushStack(lastCoor);
        choice = checkStack(lastDir);
    }
    else if (smartStackCounter > 3) { //Is there still a place on the stack to try?
        choice = checkStack(lastDir);
    }

    return choice;
}

// Pulling a number from the smartstack
int Computer::checkStack(int lDir) {
    int choice = -1;
    bool emptyRow = true;

    if (lDir != -1) {
        choice = smartStack[smartStackCounter+lDir];
        popDirection(lDir);
    }
    else {
        //Continue until either we find a new attempt to test or run out of rows on the stack.
        while (smartStackCounter > 3 && emptyRow == true) {
            for (int i = 0; i < 4; i++) {
                //break and leave both loops if true
                if (smartStack[smartStackCounter+i] != -1) {
                    emptyRow = false;
                    choice = smartStack[smartStackCounter+i];
                    lastDir = i;
                    popDirection(i);
                    break;
                }
            }
            if (emptyRow == true) {
                popStack();
            }
        }
    }

    return choice;
}