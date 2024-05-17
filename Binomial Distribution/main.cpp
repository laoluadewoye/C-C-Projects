#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    cout << "This is a binomial distribution calculator.\n";
    cout << "In light of the Dream accusation, I wondered; maybe I can make a program to calculate it.\n";
    cout << "In essence, I'm going to use vector storage to brute force any program you asked for.\n";
    cout << "I hope this works\n\n";
    
    int numerator, denominator, checktotal, addup; 
    double perc;
    int counter, countertotal = 0; //perc, couter, and countertotal won't be used until near the end
    
    cout << "First number you will put is the denominator. This will be the 'out of'. For example, the total amount of Piglin trades Dream made.\nEnter here --> ";
    cin >> denominator;
    
    cout << "\n\nThe next number you will add is is the numerator. This is basically each time the set condition happened. Such as getting desired ender orbs\nEnter here --> ";
    cin >> numerator;
    
    cout << "\n\nAlright, now the hard part. What is about to happen is that all the int variables are going to come into play\n";
    cout << "Slider is going to be set to 0. Countertotal is going to be set to finding all the possible combinations [edit this]\n\n\n";
    
    int slider = 0;
    int totalslider = 1;
    vector<int> brutecheck;
    while (slider != denominator) {
        brutecheck.push_back(0);
        slider++;
        cout << brutecheck[slider] << " ";
    }
    
    cout << "\n\n";
    addup = 0;
    slider = 0;
    int sliderlock = 0;
    int half = denominator/2 + 1;
    int subtract = denominator - (denominator - numerator); 
    while (half < denominator) {
        while (addup != numerator) {
            brutecheck[slider] = 1;
            slider++;
            addup = accumulate(brutecheck.begin(), brutecheck.end(), 0);
            cout << addup;
        }
        counter++;
        if (slider == half) {
            brutecheck[slider - 1] = 0;
            addup = accumulate(brutecheck.begin(), brutecheck.end(), 0);
            half++;
        }
    }
    
    //decide if you wanna use pop.out for if statement
    
    cout << "\nIf you are reading this, the while loop was broken.\n";
    cout << "We counted " << counter << " combinations.";
    return 0;
}
