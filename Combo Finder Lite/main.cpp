#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
    
int main() {
    vector<int> test = {0, 0, 0, 0, 0, 0};
    int list = 6;
    int slider = 0;
    int value = 4;
    int counter = 0;
    int add;
    int subtract = list - value;
    int subtract2;
    int subtract3 = subtract;
    int softlock = 0;
    
    while (subtract > 0) {
        while (slider < list) {
            test[slider + softlock] = 1;
            slider++;
            add = accumulate(test.begin(), test.end(), 0);
            if (add == value) {
                counter++;
                slider = 0;
                while (slider < list) {
                    test[slider] = 0;
                    slider++;
                }
                test.pop_back();
                slider = 0;
            }
            cout << add << " " << counter << " \n";
        }
        
        subtract2 = subtract;
        while (subtract2 > 0) {
            test.push_back(0);
            subtract2--;
        }
        
        list = 6;
        slider = 0;
        value = 4;
        subtract--;
    }


    cout << "\n\ncounter = " << counter + 1;
    

    return 0;
}
