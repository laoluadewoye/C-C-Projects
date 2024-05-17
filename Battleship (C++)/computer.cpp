#include "computer.h"

using namespace std;

Computer::Computer() {

}

Computer::Computer(int computerNum) {
    cout << "Player " << computerNum << " created" << endl;
    srand (time(NULL));

    shipAliveCount = 5;
    scoreCount = 0;
    playerNumber = computerNum;
    //PlayerView is already technically initialized

    generateShips(); //So is shipTracker?
    createCatalog();
    computerSetup();
}

void Computer::computerSetup() {
    for (int i = 0; i < 100; i++) {
        unusedCoor[i] = i;
    }

    for (int i = 0; i < 8; i++) {
        aroundHit[i] = -1;
    }

    unusedLength = 100;
    aroundHitEmpty = true;
    attackSuccess = false;
    AHLength = 8;
}

int Computer::chooseCoordinate() {
    int randIndex;
    bool foundIndex = false;

    while (foundIndex == false) {
        if (aroundHitEmpty) { //There are no specific targets
            randIndex = rand() % unusedLength;
            foundIndex = checkUnused(randIndex);
            continue; //Skip rest of turn
        }

        else if (attackSuccess) { //There are no specific targets but there was a hit last turn
            aroundHit = newAround;
            AHLength = NALength;
            attackSuccess = false;
        }

        //There are specific targets to go after
        int AHIndex = rand() % AHLength;
        randIndex = useAround(AHIndex);
        foundIndex = checkUnused(randIndex);
    }

    updateUnused(randIndex);

    return randIndex;
}

int Computer::useAround(int AHIndex) {
    updateAround(aroundHit[AHIndex]);

    //Around check
    if (AHLength == 0) {
        aroundHitEmpty = true;
    }
    else {
        aroundHitEmpty = false;
    }

    return aroundHit[AHIndex];
}

bool Computer::checkUnused(int randIndex) {
    bool foundIndex = false;

    int first = 0;
    int last = unusedLength - 1;
    int searchItem = randIndex;
    int mid = 0;

    while (first <= last && foundIndex == false) {
        mid = (first + last) / 2;
        if (unusedCoor[mid] == searchItem) {
            foundIndex = true;
        }
        else if (unusedCoor[mid] > searchItem) {
            last = mid - 1;
        }
        else {
            first = mid + 1;
        }
    }

    return foundIndex;
}

void Computer::updateUnused(int randIndex) { //3
    unusedLength--; //99
    int j = 0;
    int* tempUnused = new int[unusedLength];

    for (int i = 0; i < unusedLength; i++) { //i --> 3
        if (i == randIndex) { //true
            j++; //j = 1
        }
        tempUnused[i] = i + j; //3+1 = 4
    }

    unusedCoor = tempUnused;
}

void Computer::updateAround(int randIndex) { //6
    AHLength--; //5 --> 4
    int j = 0; //0
    int* tempAround = new int[AHLength]; //4 numbers

    for (int i = 0; i < AHLength; i++) {
        if (aroundHit[i] == randIndex) { //{2, 4, 6, 8, 10}
            j++; //2 --> 3
        }
        tempAround[i] = aroundHit[j]; //{2, 4, 8, 10}
        j++;
    }

    aroundHit = tempAround;
}

void Computer::generateAround(int succIndex) { //This should take the successful index that hit. Generates every time
    //Make sure to first check if indexes have not been used
    int* pureGen;
    int* tempGen;
    int genLength;

    //PURE AROUND CREATION BY CASE
    switch (succIndex) {
    case 0: //Index 00 - top left corner - 3 other indexes
        genLength = 3;
        pureGen = new int[genLength];
        pureGen[0] = 1;
        pureGen[1] = 10;
        pureGen[2] = 11;
        break;
    case 9: //Index 09 - top right corner - 3 other indexes
        genLength = 3;
        pureGen = new int[genLength];
        pureGen[0] = 8;
        pureGen[1] = 18;
        pureGen[2] = 19;
        break;
    case 90: //Index 90 - bottom left corner - 3 other indexes
        genLength = 3;
        pureGen = new int[genLength];
        pureGen[0] = 80;
        pureGen[1] = 81;
        pureGen[2] = 91;
        break;
    case 99: //Index 99 - bottom right corner - 3 other indexes
        genLength = 3;
        pureGen = new int[genLength];
        pureGen[0] = 88;
        pureGen[1] = 89;
        pureGen[2] = 98;
        break;
    default:
        switch (succIndex % 10) {
        case 0: //Horizontal digit is 0 - left edge row - 5 other indexes
            genLength = 5;
            pureGen = new int[genLength];
            pureGen[0] = succIndex - 10; //Above
            pureGen[1] = pureGen[0] + 1;
            pureGen[2] = succIndex + 1; //Right
            pureGen[3] = succIndex + 10; //Below
            pureGen[4] = pureGen[3] + 1;
            break;
        case 9: //Horizontal digit is 9 - right edge row - 5 other indexes
            genLength = 5;
            pureGen = new int[genLength];
            pureGen[1] = succIndex - 10; //Above
            pureGen[0] = pureGen[1] - 1;
            pureGen[2] = succIndex - 1; //Left
            pureGen[3] = pureGen[2] + 10;
            pureGen[4] = succIndex + 10; //Below
            break;
        default:
            switch (succIndex / 10) {
            case 0: //Vertical digit is 0 - top edge row - 5 other indexes
                genLength = 5;
                pureGen = new int[genLength];
                pureGen[0] = succIndex - 1; //Left
                pureGen[1] = succIndex + 1; //Right
                pureGen[2] = pureGen[0] + 10;
                pureGen[3] = succIndex + 10; //Below
                pureGen[4] = pureGen[1] + 10;
                break;
            case 9: //Vertical digit is 9 - bottom edge row - 5 other indexes
                genLength = 5;
                pureGen = new int[genLength];
                pureGen[1] = succIndex - 10; //Above
                pureGen[0] = pureGen[1] - 1;
                pureGen[2] = pureGen[1] + 1;
                pureGen[3] = succIndex - 1; //left
                pureGen[4] = succIndex + 1; //Right
                break;
            default: //All other cases - within grid - 8 other indexes
                genLength = 8;
                pureGen = new int[genLength];
                pureGen[1] = succIndex - 10; //Above
                pureGen[0] = pureGen[1] - 1;
                pureGen[2] = pureGen[1] + 1;
                pureGen[3] = succIndex - 1; //Left
                pureGen[4] = succIndex + 1; //Right
                pureGen[6] = succIndex + 10; //Below
                pureGen[5] = pureGen[6] - 1;
                pureGen[7] = pureGen[6] + 1;
                break;
            }
        }
    }

    //NARROWING LIST TO ONLY UNUSED NUMBERS
    tempGen = new int[genLength];
    int j = 0;

    for (int i = 0; i < genLength; i++) {
        bool foundIndex = checkUnused(pureGen[i]);

        if (foundIndex) {
            tempGen[j] = pureGen[i];
            j++;
            continue;
        }
    }

    //COPYING LIST TO FRESH AROUND ARRAY
    NALength = j;
    newAround = new int[NALength];
    for (int i = 0; i < NALength; i++) {
        newAround[i] = tempGen[i];
    }
}
