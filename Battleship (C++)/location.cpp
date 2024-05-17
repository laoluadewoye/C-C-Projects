#include "location.h"

Location::Location() {

}

void Location::printOwnGrid() {
    Own.printGridDisplay();
}

void Location::printProgressGrid() {
    EnemyProgress.printGridDisplay();
}

int* Location::getOwnGrid() {
    return Own.getGrid();
}

int* Location::getEnemyGrid() {
    return Enemy.getGrid();
}

int* Location::getProgressGrid() {
    return EnemyProgress.getGrid();
}
void Location::setEnemyGrid(int* enemyGrid) {
    Enemy.setGrid(enemyGrid);
}

void Location::clearScreen() {
    for (int i = 0; i < 150; i++) {
        cout << endl;
    }
}

bool Location::checkOwnIndex(int tempIndex) {
    bool gridCheck = false;
    int status = Own.getIndexStatus(tempIndex);
    if (status == 0) {
        gridCheck = true;
    }
    return gridCheck;
}

bool Location::checkEnemyAttack(int tempIndex) {
    bool gridCheck = false;
    int status = Enemy.getIndexStatus(tempIndex);
    if (status != 0 || status != 8 || status != 9) {
        gridCheck = true;
    }
    return gridCheck;
}

void Location::setOwnIndex(int tempIndex, int status) {
    Own.setIndexStatus(tempIndex, status);
}

void Location::setProgressIndex(int tempIndex, int status) {
    EnemyProgress.setIndexStatus(tempIndex, status);
}

void Location::setEnemyIndex(int tempIndex, int status) {
    Enemy.setIndexStatus(tempIndex, status);
}
