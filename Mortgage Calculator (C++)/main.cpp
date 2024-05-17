#include <iostream>
#include <thread>
#include <cmath>
#include <chrono>

using namespace std;

//return parameters
double numer, demon;

class CalculationThreads {
    private:
        float rate;
        short rateExpo;
    public:
        void parameters(float, short);
        void calculateNum();
        void calculateDem();
};

void CalculationThreads::parameters(float r, short e) {
    rate = r;
    rateExpo = e;
}

void CalculationThreads::calculateNum() {
    cout << "\nTurning on numerator arithmetic program..." << endl;
    this_thread::sleep_for (chrono::milliseconds(500));
	cout << "Getting Annual Interest Rate...[Num]" << endl;
	this_thread::sleep_for (chrono::milliseconds(500));
	cout << "Getting Amount of Payments...[Num]" << endl;
	this_thread::sleep_for (chrono::milliseconds(600));
	cout << "Calculating numerator...[Num]" << endl;
	this_thread::sleep_for (chrono::milliseconds(500));

	numer = rate * pow((1 + rate), rateExpo);
}

void CalculationThreads::calculateDem() {
    cout << "\nTurning on denominator arithmetic program..." << endl;
    this_thread::sleep_for (chrono::milliseconds(600));
	cout << "Getting Annual Interest Rate...[Dem]" << endl;
	this_thread::sleep_for (chrono::milliseconds(500));
	cout << "Getting Amount of Payments...[Dem]" << endl;
	this_thread::sleep_for (chrono::milliseconds(500));
	cout << "Calculating denominator...[Dem]" << endl;
	this_thread::sleep_for (chrono::milliseconds(500));

	demon = pow((1 + rate), rateExpo) - 1;
}

int main() {
    cout << "\tWelcome to Mortgage Calculator!" << endl << endl;

    //parameters
    int principle = 0;
    float annualIR = 0.0f;
    float monthlyIR;
	short period = 0;
	short amountOfPayments;

    //user input
    cout << "\tPrinciple (in USD): ";
    cin >> principle;
    cout << "\tAnnual Interest Rate (Don't Use %): ";
    cin >> annualIR;
    cout << "\tPeriod (Years): ";
    cin >> period;

	//Calculation
	monthlyIR = (annualIR / 12) / 100;
	amountOfPayments = (short)(period * 12);

	//Class object in Main
	CalculationThreads * user = new CalculationThreads();
	user -> parameters(monthlyIR, amountOfPayments);

	thread th1(&CalculationThreads::calculateNum, user);
	thread th2(&CalculationThreads::calculateDem, user);

	th1.join();
	th2.join();

	//Calculating Mortgage
	cout << "Combining answers..." << endl;
	this_thread::sleep_for (chrono::milliseconds(500));

	double mortgage = principle * (numer/demon);

	printf("Your mortgage amount is going to be $%0.2f.\n", mortgage);
	cout << "You're making " << amountOfPayments << " mortgage payments over " << period << " years.";

    return 0;
}
