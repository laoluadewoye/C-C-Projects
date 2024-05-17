#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main() {

    //starting screen or something idk
    srand(time(NULL));

    char start[6];
    printf ("Welcome to boss battle simulator! Type in 'start' to begin!\nBeware that your game could get ended if you don't put the right input.\n");
    do {
        printf("Please type in 'start' in all lowercase\n");
        printf("Type here: ");
        fgets(start, sizeof(start), stdin);
        if (strcmp(start, "start") == 0) {
            break;
        }
    } while (1);

    //establish health and attack damage

    int bhealth;
    int phealth;
    int maxdamage;
    int bossdamage;
    int randomd;
    char difficulty;
    printf("\nPlease put how much hp (health points) you would like your boss to have: ");
    scanf(" %i", &bhealth);
    printf("Please put how much hp you would like yourself to have: ");
    scanf(" %i", &phealth);
    printf("\nPlease type in easy [E], medium [M], hard [H], or death [D] for your difficulty.\n(Note, you cannot dodge in easy, but attacks do more damage than boss.)\n");
    printf("\nEnter here: ");
    scanf(" %c", &difficulty);

    //more mechanics
    int bossdodge;
    char playchoice;
    int dodgem;
    int parrythis;

    //how easy or hard it will be

    switch (difficulty) {
        case 'E':
            maxdamage = bhealth / 12;
            bossdamage = phealth / 18;
            bossdodge = 1;
            parrythis = 2;
            break;
        case 'M':
            maxdamage = bhealth / 12;
            bossdamage = phealth / 12;
            bossdodge = 2;
            parrythis = 3;
            break;
        case 'H':
            maxdamage = bhealth / 12;
            bossdamage = phealth / 9;
            bossdodge = 4;
            parrythis = 4;
            break;
        case 'D':
            maxdamage = bhealth / 12;
            bossdamage = phealth / 6;
            bossdodge = 2;
            parrythis = 3;
            printf("S O    Y O U    C H O O S E    D E A T H.\n");
            break;
    }

    //the part that actually matters

    printf("\nGame start!\n\n");
    while (bhealth > 0 ) {
        printf("Do you want to dodge [D], attack [A], or parry [P]: ");
        scanf(" %c", &playchoice);

        if (playchoice == 'A') {
            randomd = rand() % maxdamage;
            bhealth = bhealth - randomd;
            printf("\nYou deal %i damage! The boss has %i hp left!\n", randomd, bhealth);
            randomd = rand() % bossdamage;
            phealth = phealth - randomd;
            printf("The boss deals %i damage in return! You have %i hp left!\n", randomd, phealth);

            if (phealth < 1) {
                printf("You ran out of health before the boss. You lose!");
                return 0;
            }
        }
        else if (playchoice == 'D') {
            dodgem = rand() % bossdodge;
            if (dodgem > 0) {
                randomd = rand() % bossdamage;
                phealth = phealth - randomd;
                printf("\nThe boss deals %i damage! You have %i hp left!\n", randomd, phealth);
                if (phealth < 1) {
                    printf("You ran out of health before the boss. You lose!");
                    return 0;
                }
            }
            else if (dodgem == 0) {
               printf("You avoid damage!\n");
            }
        }
        else if (playchoice == 'P') {
            randomd = rand() % bossdamage;
            phealth = phealth - randomd;
            printf("\nThe boss deals %i damage! You have %i hp left!\n", randomd, phealth);
            if (phealth < 1) {
                printf("You ran out of health before the boss. You lose!");
                return 0;
            }
            else if (parrythis < 5) {
                bhealth = bhealth - randomd;
                randomd = randomd / parrythis;
                bhealth = bhealth - randomd;
                printf("You parry the boss back with %i additional damage! The boss has %i hp left!\n", randomd, bhealth);
                parrythis = parrythis + 1;
            }
            else {
                printf("Your parry failed! (You ran out of parries. Choosing this option is now suicide.)\n");
            }
        }
    }

    printf("You beat the boss!");
    return 0;
}

