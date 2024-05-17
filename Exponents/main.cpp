#include <iostream>

using namespace std;

int square(int &i, int j) {
    i = i * j;
    return i;
}

int main() {
    int choose;
    int num;
    int num2;
    cout << "Welcome to the exponent calculator! I couldn't do it before, but now I did.\n";
    cout << "Enter the number you want apply exponent to.\n";
    cin >> num;
    cout << "Enter the power your want to raise to.\n";
    cin >> choose;
    num2 = num;

    while (choose != (1 or -1)) {
        cout << square(num, num2) << ", ";
        if (choose > 0) {
            choose--;
        }
        else if (choose < 0) {
            choose++;
        }
        else if (choose == 0) {
            cout << "Screw you. Do the math yourself you cheeky bloke.\n";
            return 0;
        }
    }

    return 0;
}



