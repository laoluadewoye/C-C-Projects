//Project #3 - Turn based battle game. Created to learn how to use random.

#include <ctime>
#include <iostream>

using namespace std;

int main() {

    //starting screen or something idk
    srand(time(NULL));
    string start;
    cout << "Welcome to boss battle simulator! Type in 'start' to begin!\nBeware that your game could get ended if you don't put the right input.\n";
    cin >> start;
    while (start != "start") {
        cout << "Please type in 'start' in all lowercase\n";
        cin >> start;
    }

    //establish health and attack damage

    int bhealth;
    int phealth;
    int maxdamage;
    int bossdamage;
    int randomd;
    string difficulty;
    cout << "\n";
    cout << "Please put how much hp (health points) you would like your boss to have\n";
    cin >> bhealth;
    cout << "Please put how much hp you would like yourself to have\n";
    cin >> phealth;
    cout << "Please type in 'easy', 'medium', 'hard', or 'death' for your difficulty.\n(Note, you cannot dodge in easy, but attacks do more damage than boss.)\n";
    cin >> difficulty;

    //more mechanics
    int bossdodge;
    string playchoice;
    int dodgem;
    int parrythis;

    //how easy or hard it will be

    if (difficulty == "easy") {
        maxdamage = bhealth / 12;
        bossdamage = phealth / 18;
        bossdodge = 1;
        parrythis = 2;
    }
    if (difficulty == "medium") {
        maxdamage = bhealth / 12;
        bossdamage = phealth / 12;
        bossdodge = 2;
        parrythis = 3;
    }
    if (difficulty == "hard") {
        maxdamage = bhealth / 12;
        bossdamage = phealth / 9;
        bossdodge = 4;
        parrythis = 4;
    }
    if (difficulty == "death") {
        maxdamage = bhealth / 12;
        bossdamage = phealth / 6;
        bossdodge = 2;
        parrythis = 3;
        cout << "S O    Y O U    C H O O S E    D E A T H.\n";
    }

    //the part that actually matters

    cout << "\n";
    cout << "Game start!\n\n";
    while (bhealth > 0 ) {
        cout << "Do you want to dodge, attack, or parry?\n";
        cin >> playchoice;

        if (playchoice == "attack") {
            cout << "\n";
            randomd = rand() % maxdamage;
            bhealth = bhealth - randomd;
            cout << "You deal " << randomd << " damage! The boss has " << bhealth << " hp left!\n";
            randomd = rand() % bossdamage;
            phealth = phealth - randomd;
            cout << "The boss deals " << randomd << "damage in return! You have " << phealth << " hp left!\n";
            if (phealth < 1) {
                cout << "You ran out of health before the boss. You lose!";
                return 0;
            }
        }
        if (playchoice == "dodge") {
            cout << "\n";
            dodgem = rand() % bossdodge;
            if (dodgem > 0) {
                randomd = rand() % bossdamage;
                phealth = phealth - randomd;
                cout << "The boss deals " << randomd << "damage! You have " << phealth << " hp left!\n";
                if (phealth < 1) {
                    cout << "You ran out of health before the boss. You lose!";
                    return 0;
                }
            }
            else if (dodgem == 0) {
                cout << "You avoid damage!\n";
            }
        }
        if (playchoice == "parry") {
            cout << "\n";
            randomd = rand() % bossdamage;
            phealth = phealth - randomd;
            cout << "The boss deals " << randomd << "damage! You have " << phealth << " hp left!\n";
            if (phealth < 1) {
                cout << "You ran out of health before the boss. You lose!";
                return 0;
            }
            else if (parrythis < 5) {
                bhealth = bhealth - randomd;
                randomd = randomd / parrythis;
                bhealth = bhealth - randomd;
                cout << "You parry the boss back with " << randomd << " additional damage! The boss has " << bhealth << " hp left!\n";
                parrythis = parrythis + 1;
            }
            else {
                cout << "Your parry failed! (You ran out of parries. Choosing this option is now suicide.)\n";
            }
        }
    }

    cout << "You beat the boss!";
    return 0;
}

