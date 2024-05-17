#include <iostream>

using namespace std;

int main()
{
    //Part 1
    int userInput;
    
    cout << "Part 1" << endl;
    cout << "Enter a number between 1 and 100: ";
    cin >> userInput;
    
    if (userInput < 101 && userInput > 0) {
        if (userInput > 89) {
            cout << "A" << endl << endl;
        }
        else if (userInput > 79) {
            cout << "B" << endl << endl;
        }
        else if (userInput > 69) {
            cout << "C" << endl << endl;
        }
        else if (userInput > 59) {
            cout << "D" << endl << endl;
        }
        else {
            cout << "F" << endl << endl;
        }
    }
    
    //Part 2
    cout << endl << "2 to 16" << endl << "-----" << endl;
    
    for (int i = 2; i < 17; i += 2) {
        cout << i << endl << endl;
    }
    
    cout << endl << "20 to 15" << endl << "-----" << endl;
    
    for (int i = 20; i > 14; i--) {
        cout << i << endl << endl;
    }
    


    return 0;
}
