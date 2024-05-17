#include <iostream>
#include <vector>

using namespace std;

int yes(int x, int y) {
    
    int product, productsub, productnum, subtract; 
    double finalnum;
    
    int shift = y;
    vector<int> total;
    vector<int> totalsub;
    vector<int> totalnum;
    
    while (shift > 0) {
        total.push_back(shift);
        shift--;
    }
    
    shift = 0;
    product = 1;
    while (shift < y - 1) {
        product = product * total[shift];
        shift++;
    }
    
    subtract = y - x;
    shift = subtract;
    
    while (shift > 0) {
        totalsub.push_back(shift);
        shift--;
    }
    
    shift = 0;
    productsub = 1;
    while (shift < subtract - 1) {
        productsub = productsub * totalsub[shift];
        shift++;
    }
    
    shift = x;
    
    while (shift > 0) {
        totalnum.push_back(shift);
        shift--;
    }

    shift = 0;
    productnum = 1;
    while (shift < x - 1) {
        productnum = productnum * totalnum[shift];
        shift++;
    }
    
    finalnum = product/(productnum * productsub);
    cout << "\n Number of possible combinations = " << finalnum;
    
    return finalnum;

}

int main() { 
    
    int numerator, denominator, finaldenom, total2, shift2;
    double percent, total3, finalfinalnum;
    cout << "Welcome to a binomail distribution calculator! First thing you should know is that the highest number that you can enter is 14 right\nnow. Now, please enter a whole number as numerator, or how many times something happened.\n";
    cin >> numerator;
    cout << "\nNice. Now, enter the total sample size, or a denominator. Whole number again please.\n";
    cin >> denominator;
    
    if (numerator > 15) {
        cout << "Not gonna work bro. I'm sorry, but my puny code can't handle this. Gotta run it back.";
        return 0;
    }
    else if (denominator > 15) {
        cout << "Not gonna work bro. I'm sorry, but my puny code can't handle this. Gotta run it back.";
        return 0;
    }
    
    yes(numerator, denominator);
    
    cout << "\n\nCongradulations! Unfortunately I don't know how to transfer what you have gotten into the main. Enter your output again and you will\nget your binomial distribution.\n";
    cin >> finalfinalnum;
    
    shift2 = 1;
    total2 = 0;
    while (shift2 < denominator + 1) {
        total2 = total2 + yes(shift2, denominator);
        shift2++;  
    }
    cout << "\n\nThe total amount of combinations = " << total2;
    total3 = total2;
    percent = finalfinalnum / total2 * 100;
    cout << "\n\nThe chance that something happened " << numerator << "\ntimes in a total sample of " << denominator << " is around ";
    cout << percent << "%";

    return 0;
}


