#include <iostream>
#include <ctime>

using namespace std;

int main() {
    
    //this lets you use seeds from counting time since Jan 1971. Ikr?
    
    srand(time(NULL));
    cout << rand() << endl;
    
    return 0;
}