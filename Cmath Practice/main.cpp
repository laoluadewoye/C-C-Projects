#include <iostream>
#include <cmath>

using namespace std;

int main () {
    cout << "First is absolute value --> " << abs(3.0) << " minus " << abs(-3.0) << " equals " << abs(3.0) - abs (-3.0) << "\n";
    cout << "Next is expos and logs. The common log of 100 is " << log10(100) << ".\n";
    cout << "The natural log of e is roughly " << log(2.71) << ".\n";
    cout << "Now we test out some trig. but first, know that pi = " << 2*acos(0.0) << ".\n";
    double pi = 2*acos(0.0);
    cout << "Sine of pi over 2 radians, or 90 degress, is " << sin(pi/2) << ".\n";
    cout << "You know what also equals 1? cosine of 0, which is " << cos(0) << ".\n";
    cout << "Finally, there is tan of pi over 4 radians, or 45 degress, which is also " << tan(pi/4) << ".\n";

    return 0;
}