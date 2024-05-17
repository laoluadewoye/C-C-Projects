#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Order {
        string style, topping, soda;
        bool wings;
        vector<string> toppings = {"cheese"};
    public:
        void order(string, bool, string);
        void addToppings(string);
        void print();
        void printToppingList();
};

void Order::order(string c, bool w, string s) {
    style = c;
    wings = w;
    soda = s;
}

void Order::addToppings (string t) {
    topping = t;
    toppings.push_back(topping);
}

void Order::print() {
    cout << "Style choice: " << style << endl;
    cout << "Choice of soda: " << soda << endl;
    cout << "Side of Wings: " << wings << endl;
}

void Order::printToppingList() {
    cout << "Toppings: ";
    for (int i = 0; i < toppings.size(); i++) {
        cout << toppings[i] << ", ";
    }
}


int main()
{
    struct personalInfo {
        string d_or_p;
        string name;
        string address;
        string paymentMethod;
    } user;
    
    Order userOrd;
    
    string choice, sty, top, so;
    bool win;
    bool firstTime = true;
    
    cout << "Welcome to Pizza Pizza." << endl;
        
    cout << "Enter your choice of delivery (delivery OR pickup): ";
    getline(cin, user.d_or_p);
    cout << "Enter name: ";
    getline(cin, user.name);
    cout << "Enter address: ";
    getline(cin, user.address);
    cout << "Enter payment Method: ";
    getline(cin, user.paymentMethod);
    
    cout << "Enter your pizza style choice (Thin crust or NY Style): ";
    getline(cin, sty);
    
    cout << "Do you want wings? ";
    getline(cin, choice); 
    if (choice == "yes") {
        win = true;
    }
    else if (choice == "no") {
        win = false;
    }
    else {
        if (choice == "Yes") {
            win = true;
        }
        else if (choice == "No") {
            win = false;
        }
    }
    
    cout << "Enter soda(if no soda wanted, say 'No soda'): ";
    getline(cin, so);
    
    userOrd.order(sty, win, so);
    
    while (choice != "no") {
        cout << "Enter a topping choice: ";
        cin >> top;
        userOrd.addToppings(top);
        cout << "Do you want to add another topping? ";
        cin >> choice;
    }
    
    cout << "Entered information" << endl << "---------------------------------" << endl << endl;
    cout << "Name: " << user.name << endl;
    cout << "Address: " << user.address << endl;
    cout << "Pizza will be gotten by: " << user.d_or_p << endl;
    cout << "Payment method: " << user.paymentMethod << endl << endl;
    userOrd.print();
    userOrd.printToppingList();
    
}

