#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
    //there are five levels of affection
    //they increse in levels, each one ending on a factor of 25. Level five is 100+
    
    srand(time(NULL));
    int affection = 0;
    int raiser;
    vector<string> afflevel = {"classmates", "friends", "lover", "wife", "yandere"};
    int level;
    
    while (affection < 110) {
        raiser = rand() % 16;
        affection = affection + raiser;
        int level = affection / 25;
        cout << "Affection is increased by " << raiser << "! Affection is now " << affection << "!\n";
        cout << "Your affection level is " << afflevel[level] << "!\n";
    }
    
    cout << "Have fun!~";
    

    return 0;
}



