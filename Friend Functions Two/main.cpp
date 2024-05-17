#include <iostream>
using namespace std;

class Sphere {
    //private
        int radius;
    
    public:
        int Area() 
            {return ((radius * radius) * 4 * 3.1415);}
        int Volume()
            {return ((radius * radius * radius) * 1.333333 * 3.1415);}
        void Transfer(int);
};

//For bringing value in friend class to main class
void Sphere::Transfer(int input) {
    radius = input;
}

class Gather {
    friend class Sphere;
    public:
        int rad;
        void Data (int);
};

//Getting user input and storing it in friend class
void Gather::Data (int x) {
    rad = x;
}

int main () {
    //Establishing objects
    Sphere input;
    Gather userInput;
    
    //User value
    int x;
    cin >> x;
    userInput.Data(x);
    input.Transfer(userInput.rad);
    
    //Using functions in main class
    cout << endl << input.Area() << endl << input.Volume() << endl;
    return 0;
}