#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//BASIC ARITHMATIC
void basicArith() {
    printf("\n\nPlease choose a basic operation you would like to do (Input initial in paraenteses)\n");
    printf("Addition(A)  Subtraction(S)  Multiplication(M)  Division(D)\n");
    printf("---------------------------------------------------------------------------------------\n");
    char choiceBasic;
    char isDecimal;
    float firstNum, secondNum;
    double result = 0;

    printf( "Enter a capital letter: ");
    scanf(" %c", &choiceBasic);

    printf("\n\nWill you have decimal numbers or a decimal answer? (Y or N)\n");
    printf("Enter here: ");
    scanf(" %c", &isDecimal);

    printf("\n\nEnter the two numbers you plan to use. Separate numbers with a comma.\n");
    printf("Enter here: ");
    scanf(" %f, %f", &firstNum, &secondNum);

    switch (choiceBasic) {
        case 'A':
            result = firstNum + secondNum;
            break;
        case 'S':
            result = firstNum - secondNum;
            break;
        case 'M':
            result = firstNum * secondNum;
            break;
        case 'D':
            if (secondNum == 0) {
                fprintf(stderr, "Division by zero! Exiting...\n");
                exit(-1);
            }
            result = firstNum / secondNum;
            break;
        default:
            printf("Wrong operation chosen. End of program.");
            break;
    }
    if (isDecimal == 'Y') {
        printf("\n\nYour answer is %0.3f.", result);
    }
    else {
        printf("\n\nYour answer is %i.", (int)result);
    }
}

//ADDITIONAL OPTIONS
//Prime factorization
void factorize (int num) {
    int factor;
    int numCheck = 0;
    int gcf = 0;
    while (num > 1)  {
        for (int i = 2; i < (num / 2); i++) { //Run through numbers up to half of number that is being factored
            if (num % i == 0) { //factor found as remainder is 0
                factor = i; //factor is recorded
                num = num / factor; //number is divded by factor for next iteration
                break; //stop looking for a factor
            }
        } //prints the factor
        if (numCheck == num) {
            //checks if the num is the same as the last iteration. If so, it means that no more factors were found.
            printf("%i", num); //The last number iteration is the final factor.
            break;
        }
        else {
            numCheck = num; //update the check for next iteration
            printf("%i, ", factor); //continue the process
        }
    }
}

void additionalArith () {
    printf("\n\nPlease choose Please choose from a list of more operations (Type the letter in parenth.)\n");
    printf("Exponents(E)  Square-Root(R)  Modulus(M)  Factorization(F)\n");
    printf("--------------------------------------------------------------------------------------------\n");
    float firstNum, secondNum;
    char choiceAddition, isDecimal;
    double result = 1;

    printf( "Enter a capital letter: ");
    scanf(" %c", &choiceAddition);

    printf("\n\nEnter the two numbers you plan to use. Separate numbers with a comma. (Don't enter a second number if you have no use for it)\n");
    printf("Enter here: ");
    scanf(" %f, %f", &firstNum, &secondNum);

    printf("\n\nWill you have decimal numbers or a decimal answer? (Y or N)\n");
    printf("Enter here: ");
    scanf(" %c", &isDecimal);

    switch (choiceAddition) {
        case 'E':
            for (int i = 0; i < secondNum; i++) {
                result *= firstNum;
            }
            break;
        case 'R':
            result = sqrt(firstNum);
            break;
        case 'M':
            result = (int)firstNum % (int)secondNum;
            break;
        case 'F':
            printf("Factors: ");
            factorize((int)firstNum);
            break;
        default:
            printf("Wrong operation chosen. End of program.");
            break;
    }

    if (choiceAddition != 'F') {
        if (isDecimal == 'Y') {
            printf("\n\nYour answer is approx. %0.3f.", result);
        }
        else {
            printf("\n\nYour answer is %i.", (int)result);
        }
    }
}

//MAIN
int main() {
    //Introduction screen
    printf("Welcome to a calculator!\n");
    printf("Please choose your choice of operation (type a number and press enter)\n\n");
    printf("Basic Arithmatic (basic), Additional Operations (extra)\n\n");
    printf("----------------------------------------------------------------------\n");

    //Declaration
    char choiceMain[6];
    int check;

    do { //Indefinite input until correct choice is made

        printf( " Enter one of the two words: ");
        fgets(choiceMain, sizeof(choiceMain), stdin);

        check = strcmp(choiceMain, "basic");
        if (check == 0) {
            basicArith();
            break;
        }

        check = strcmp(choiceMain, "extra");
        if (check == 0) {
            additionalArith();
            break;
        }

        printf(" Incorrect value. Please try again.\n\n");

    } while (check != 0);

    return 0;
}


