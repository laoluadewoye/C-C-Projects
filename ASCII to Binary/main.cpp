#include <iostream>
#include <vector>

using namespace std;

int main() {
    char input;
    int output;
    int insert;
    int shifter = 0;
    vector<int> binary = {0, 0, 0, 0, 0, 0, 0, 0};
    
    cout << "Type in any letter, number, etc; [only one!!].\n";
    cin >> input;
    output = int(input); 
    cout << "ASCII number -> " << output << "\n";
    
    while (shifter != 8) {
        insert = output % 2;
        binary[7-shifter] = insert;
        output = output / 2;
        shifter++;
    }
    
    shifter = 0; cout << "Binary ver -> ";
    while (shifter !=8) {
        cout << binary[shifter] << " ";
        shifter++;
    }
    
    return 0;
}







