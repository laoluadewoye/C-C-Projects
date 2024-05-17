#include <iostream>
#include <vector>

using namespace std;

int main () {
    vector<int> number = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int input;
    int remain;
    int shifter = 0;
    
    cout << "Time to convert a number to binary! Type in a number! (max is 65535)\n";
    cin >> input;
    while (shifter != 15) {
        remain = input % 2;
        cout << remain << " ";
        number[14 - shifter] = remain;
        input = input / 2;
        cout << input << "\n";
        shifter++;
    }
    
    shifter = 0; cout << "Binary version: ";
    while (shifter !=15) {
        cout << number[shifter] << " ";
        shifter++;
     }
    
    return 0;
}