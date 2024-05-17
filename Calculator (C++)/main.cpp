#include <iostream>

using namespace std;

int main()
{
    //introduces program and establishes variables
    
    cout<<"Welcome to my simple calculator\n";
    int operation;
    int num_one, num_two;
    double outcome;
    int expo;
    
    //directions for operation var
    
    cout<<"Please print the number of what operation you want\n\n";
    cout<<"Addition (1)\nSubtraction (2)\nMultiplication (3)\nDivision (4)\nExponents (5)\n";
    cin>>operation;
    
    //this is where the control+c begins (exponents is w.i.p.)
    
    if (operation==1) {
        cout<<"Please print the first number\n";
        cin>>num_one;
        cout<<"Please print the second number\n";
        cin>>num_two;
        outcome=num_one+num_two;
        cout<<num_one<<" plus "<<num_two<<" equals "<<outcome;
    }
    if (operation==2) {
        cout<<"Please print the first number\n";
        cin>>num_one;
        cout<<"Please print the second number\n";
        cin>>num_two;
        outcome=num_one-num_two;
        cout<<num_one<<" minus "<<num_two<<" equals "<<outcome;
    }
    if (operation==3) {
        cout<<"Please print the first number\n";
        cin>>num_one;
        cout<<"Please print the second number\n";
        cin>>num_two;
        outcome=num_one*num_two;
        cout<<num_one<<" times "<<num_two<<" equals "<<outcome;
    }
    if (operation==4) {
        cout<<"Please print the first number\n";
        cin>>num_one;
        cout<<"Please print the second number\n";
        cin>>num_two;
        outcome=num_one/num_two;
        cout<<num_one<<" divided by "<<num_two<<" equals (about) "<<outcome;
    }
    if (operation==5) {
        
        cout<<"Please print the first number\n";
        cin>>num_one;
        cout<<"Please print the second number\n";
        cin>>num_two;
        outcome==1;
        expo==0;
        
        while (expo<num_two) {
            outcome=outcome*num_one;
            expo=expo+1;
        }
        cout<<num_one<<" raised by an exponent of "<<num_two<<" equals "<<outcome;
    }

    return 0;
}

