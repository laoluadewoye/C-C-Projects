#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL));
    
    cout << "Welcome to another encryption machine!\n";
    
    int shifter = 0; 
    int shiftertwo = 0;
    vector<int> encrypt;
    int keylength;
    cout << "How long do you wish for your key to be? (type a number)\n";
    cin >> keylength;
    
    cout << "Encrypting Key: ";
    while (shifter != keylength) {
        encrypt.push_back(rand() % 2);
        cout << encrypt[shifter] << " ";
        shifter++;
    }
    
    char input;
    int output;
    int insert;
    vector<int> binary = {0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> output2;
    shifter = 0;
    string keepgoing = "lol"; cout << "\n\n";
    
    while (keepgoing != "no") {
        cout << "Type in any letter, number, etc.\n";
        cin >> input;
        output = int(input); 
        
        while (shifter != 8) {
            insert = output % 2;
            binary[7-shifter] = insert;
            output = output / 2;
            shifter++;
        }
        
        shifter = 0; cout << "Binary: ";
        while (shifter !=8) {
            cout << binary[shifter] << " ";
            shifter++;
        }
        
        shifter = 0; cout << "\n" << "Encrypted Binary: ";
        while (shifter != 8) {
            if (binary[shifter] == encrypt[shiftertwo]) {
                output2.push_back(0);
            }
            else if (binary[shifter] != encrypt[shiftertwo]) {
                output2.push_back(1);
            }
            shifter++; shiftertwo++;
            if (shiftertwo == keylength) {
                shiftertwo = 0;
            }
            cout << output2[shifter] << " ";
        }
        cout << "\n\n" << "Do you wish to keep going? (type no if you have gotten your encrypted text).\n";
        cin >> keepgoing;
        
    }
    
    cout << "That is alright; put together the ciphertexts to get your entire coded message! Thank you!\n";
    return 0;
}

//notes

//possible structure
//first, it will ask how long your want your randomly processed key to be. That will be X-OR key
//Then, when one letter is entered, that letter is converted directly into ASCII # then into binary, then 
    //encrypted
//
