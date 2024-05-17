#include <iostream>
using namespace std;

class Sphere {
    //private
        int radius;
    
    public:
        void Data (int);
    
    friend Sphere Volume (Sphere&);
    friend Sphere Area (Sphere&);
};

//Data, for collecting the radius from user
void Sphere::Data (int x) {
    radius = x;
}

//Area, friend of Sphere
Sphere Area (Sphere& arObject) {
    Sphere outcome;
    outcome.radius = (arObject.radius * arObject.radius) * 4 * 3.1415;
    cout << outcome.radius << endl;
}

//Volume, friend of Sphere
Sphere Volume (Sphere& volObject) {
    Sphere outcome;
    outcome.radius = (volObject.radius * volObject.radius * volObject.radius) * 1.333333 * 3.1415;
    cout << outcome.radius << endl;
}

int main () {
    //Creating object in main
    Sphere userInput;
    int x;
    cin >> x;
    userInput.Data(x);
    
    //Using object on friend functions
    cout << endl;
    Area(userInput);
    Volume(userInput);
    return 0;
}