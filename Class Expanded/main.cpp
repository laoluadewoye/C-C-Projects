#include <iostream>
using namespace std;

class Rect_Prism {
    double length, width, height;
  public:
    void prism();
    void prism(double, double, double);
    double volume() {return length * width * height;}
    double tripleVolume() {return (length * 3) * (width * 3) * (height * 3);}
};

void Rect_Prism::prism() {
    length = 1;
    width = 1;
    height = 1;
}

void Rect_Prism::prism(double l, double w, double h) {
    length = l;
    width = w;
    height = h;
}

int main () {
    double len, wid, hei;
    cout << "Enter length: ";
    cin >> len;
    cout << "Enter width: ";
    cin >> wid;
    cout << "Enter height: ";
    cin >> hei;
    
    Rect_Prism foo;
    foo.prism(len, wid, hei);
    
    if (foo.volume() == 1) {
        cout << endl << "The volume is " << foo.volume() << " by default." << endl;
    }
    else {
        cout << endl << "The volume is " << foo.volume() << endl;
    }
    
    if (foo.tripleVolume() == 27) {
        cout << "The volume when parameters are multiplied by three is " << foo.tripleVolume() << " by default." << endl;
    }
    else {
        cout << "The volume when parameters are multiplied by three is " << foo.tripleVolume() << endl;
    }

  return 0;
}