/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main() {
    
    for (char i = 32; i < 127; ++i) {
        std::cout << i << ' ';
        if (i % 16 == 15) {
            std::cout << '\n';
        }
    }
    

    return 0;
}

