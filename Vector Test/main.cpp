#include <iostream>

using namespace std;

int main() {
    
    cout << "This is vector practice. You will be asked to enter something 8 times.\n";
    int xorinput[8];
    int key[8];
    int encryption[8];
    int keymove = 0;
    int enterstuff = 0;
    
    
    while (enterstuff != 8) {
        cout << "Please enter a 0 or a 1.\n";
        cin >> key[keymove];
        enterstuff++;
        keymove++;
    }
    cout << "Your input: " << key[0] << " " << key[1] << " " << key[2] << " " << key[3] << " " << key[4] << " " << key[5] << " " << key[6] << " " << key[7] << "\n";
    
    
    keymove = 0; cout << "Key: ";
    while (keymove != 8) {
        key[keymove] = rand() % 2;
        cout << key[keymove] << " ";
        keymove++;
    }
    
    
    cout << "\n";
    keymove = 0; cout << "X-OR encryption: ";
    while (keymove != 8) {
        if (xorinput[keymove] == key[keymove]) {
            encryption[keymove] = 0; 
        }
        else if (xorinput[keymove] != key[keymove]){
            encryption[keymove] = 1;
        }
        
        cout << encryption[keymove] << " ";
        keymove++;
    }
    
    return 0;
}

