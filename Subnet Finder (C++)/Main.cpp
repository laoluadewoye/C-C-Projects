#include <iostream>
#include <sstream>
#include <string> 
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// Customized for printing IP Addresses
template<typename S> ostream& operator<<(ostream& os, const vector<S>& vector)
{
    for (int i = 0; i < (vector.size() - 1); i++) {
        os << vector[i] << ".";
    }
    os << vector[vector.size() - 1];

    return os;
}

//Validating Subnet Masks
bool validateMask(vector<int> quartetList, vector<int> lastMask) {
    vector<int> subnetNumbers = {0, 128, 192, 224, 240, 248, 252, 254, 255};
    bool maskValid = true;

    //Check basic syntax
    for (int i = 1; i < quartetList.size(); i++) {
        if (quartetList[i] > quartetList[0]) {
            maskValid = false;
        }
    }

    //Checking that proper values are used
    for (int quartet : quartetList) {
        bool foundNumber = false;

        for (int number : subnetNumbers) {
            if (quartet == number) {
                foundNumber = true;
            }
        }

        if (foundNumber == false) {
            maskValid = false;
        }
    }

    //Ensure new mask makes a smaller host pool
    for (int i = 0; i < 4; i++) {
        if (lastMask[i] > quartetList[i]) {
            maskValid = false;
        }
    }

    return maskValid;
}

//General IP Address Validation
bool validateAddress(string addr, bool zeroFlag=false, bool subnetFlag=false, vector<int> lastMask={0, 0, 0, 0}) {
    //Declaration
    bool valid = false;
    bool maskValid = true;
    stringstream testAddr(addr);
    string quartet;
    vector<int> quartetList;
    char delimiter = '.';


    //Test parsing
    try {
        while (!testAddr.eof()) {
            getline(testAddr, quartet, delimiter);
            quartetList.push_back(stoi(quartet));
        }
    }
    catch(invalid_argument) {
        cout << "IPv4 Address inputted incorrectly. Make sure to use only numbers and dots.";
        return valid;
    }

    //Test structure
    if (quartetList.size() != 4) {
        cout << "IPv4 Address inputted incorrectly. Remember you are inputting an IPv4 address.";
        return valid;
    }

    //Test Ending in Zero
    if (quartetList[3] != 0 && zeroFlag == true) {
        cout << "IPv4 Address inputted incorrectly. Remember to have the network end in '0'.";
        return valid;
    }

    //Test Number Ranges
    for (int quartet : quartetList) {
        if (quartet < 0 || quartet > 255) {
            cout << "IPv4 Address inputted incorrectly. Make sure each number is between 0 or 255.";
            return valid;
        }
    }

    //Test Subnet Requirements
    if (subnetFlag == true) {
        maskValid = validateMask(quartetList, lastMask);
    }

    if (maskValid == false) {
        cout << "IPv4 Address inputted incorrectly. Make sure to use a proper Subnet Mask.";
        return valid;
    }

    valid = true;

    return valid;
}

//String to Integer Vector Conversion
vector<int> strToVector(string addr) {
    stringstream testAddr(addr);
    string quartet;
    char delimiter = '.';
    vector<int> quartetList;

    while (!testAddr.eof()) {
        getline(testAddr, quartet, delimiter);
        quartetList.push_back(stoi(quartet));
    }

    return quartetList;
}

//Show Class of Network Address
char getClass(int firstQuartet) {
    if (firstQuartet < 128) {
        return 'A';
    }
    else if (firstQuartet < 192) {
        return 'B';
    }
    else if (firstQuartet < 224) {
        return 'C';
    }
    else if (firstQuartet < 240) {
        return 'D';
    }
    else {
        return 'E';
    }
}

//Get the default Subnet Mask
vector<int> getDefMask(char addrClass) {
    if (addrClass == 'A') {
        return {255, 0, 0, 0};
    }
    else if (addrClass == 'B') {
        return {255, 255, 0, 0};
    }
    else {
        return {255, 255, 255, 0};
    }
}

//Count the 1 bits in Subnet Mask
int getBits(vector<int> subnetMask) {
    int bitCount = 0;
    vector<int> subnetNumbers = {0, 128, 192, 224, 240, 248, 252, 254, 255};
    vector<int> subnetBitCount = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    for (int quartet : subnetMask) {
        for (int i = 0; i < subnetNumbers.size(); i++) {
            if (quartet == subnetNumbers[i]) {
                bitCount += subnetBitCount[i];
            }
        }
    }

    return bitCount;
}

//Count the number of addresses
int getAddr(int bitCount) {
    int TOTALBITS = 32;
    int zeroCount = TOTALBITS - bitCount;
    int numAddress = pow(2, zeroCount);

    return numAddress;
}

//Create adjustment variable for getting accurate numbers
int adjustAddr(vector<int> quartetList, vector<int> defaultMask) {
    int adjustment = 0;
    vector<int> quartetWeights = {16777216, 65536, 256, 1};

    for (int i = 0; i < defaultMask.size(); i++) {
        if (defaultMask[i] == 0) { //Host portion of address matters for adjusting address travel distance
            adjustment += quartetList[i] * quartetWeights[i];
        }
    }

    return adjustment;
}

//Create the default network address
vector<int> getDNA(vector<int> quartetList, vector<int> defaultMask) {
    for (int i = 0; i < defaultMask.size(); i++) {
        if (defaultMask[i] == 0) {
            quartetList[i] = 0;
        }
    }

    return quartetList;
}

//Computation for getRange function
vector<int> getRangeMath(vector<int> netAddress, int numAddr) {
    //The math part, but in Q4s. Numbers represent number of addresses to reach a new item.
    int Q1 = 16777216;
    int Q2 = 65536;
    int Q3 = 256;
    int Q4 = 1;

    //Reach desired subnet address
    while (numAddr > (Q1 - 1)) {
        numAddr -= Q1;
        netAddress[0] += 1;
    }
    while (numAddr > (Q2 - 1)) {
        numAddr -= Q2;
        netAddress[1] += 1;
    }
    while (numAddr > (Q3 - 1)) {
        numAddr -= Q3;
        netAddress[2] += 1;
    }
    while (numAddr > (Q4 - 1)) {
        numAddr -= Q4;
        netAddress[3] += 1;
    }

    return netAddress;
}

//Get the address range of a network or subnet
vector<vector<int>> getRange(int subnetChoice, vector<int>quartetList, int numAddr) {
    //Set markers
    int addrToStart = (subnetChoice - 1) * numAddr;
    int addrToEnd = subnetChoice * numAddr - 1;

    vector<int> startList = getRangeMath(quartetList, addrToStart);
    vector<int> endList = getRangeMath(quartetList, addrToEnd);

    return {startList, endList};
}

int powerCount(int potential) {
    int y = 0;
    while(true) {
        int count = pow(2, y);
        if (count >= potential) {
            return y;
        }
        else {
            y++;
        }
    }
}

vector<int> getMask(int oneCount) {
    vector<int> newMask;

    //Choose quartet
    int index = oneCount / 8;

    if (index == 1) {
        newMask = {255, 0, 0, 0};
    }
    else if (index == 2) {
        newMask = {255, 255, 0, 0};
    }
    else if (index == 3) {
        newMask = {255, 255, 255, 0};
    }
    else { //Range doesn't make sense
        return {0, 0, 0, 0};
    }

    int leftoverOnes = oneCount - (index * 8);

    if (leftoverOnes == 0) {
        newMask[index] = 0;
    }
    else if (leftoverOnes == 1) {
        newMask[index] = 128;
    }
    else if (leftoverOnes == 2) {
        newMask[index] = 192;
    }
    else if (leftoverOnes == 3) {
        newMask[index] = 224;
    }
    else if (leftoverOnes == 4) {
        newMask[index] = 240;
    }
    else if (leftoverOnes == 5) {
        newMask[index] = 248;
    }
    else if (leftoverOnes == 6) {
        newMask[index] = 252;
    }
    else if (leftoverOnes == 7) {
        newMask[index] = 254;
    }

    return newMask;
}

vector<int> createCustom(int subnetOption, int defaultActAddrs, int defaultBits, vector<int> defaultMask) {
    string userMask;
    char choosePotent;
    vector<int> potentialMask;
    int zeroCount;

    if (subnetOption == 1) {
        int potentialAddr;
        cout << endl << "Enter the number of usable addresses needed per subnet: ";
        cin >> potentialAddr;
        zeroCount = powerCount(potentialAddr);
    }
    else if (subnetOption == 2) {
        int potentialSubnets;
        cout << endl << "Enter the number of subnets needed: ";
        cin >> potentialSubnets;
        int subExpo = powerCount(potentialSubnets); 
        int defaultZero = 32 - defaultBits;
        zeroCount = defaultZero - subExpo;
    }

    int oneCount = 32 - zeroCount;
    potentialMask = getMask(oneCount);
    cout << "The best estimated mask was " << potentialMask << endl;
    cout << "Does this work? (Y/n): ";
    cin >> choosePotent;

    if (subnetOption == 3 || choosePotent != 'Y') {
        cout << endl << "Enter your custom Subnet Mask. Use an X.X.X.X format" << endl;
        cout << "Enter here: ";
        cin >> userMask;

        //More Validation
        bool addrValid = validateAddress(userMask, false, true, defaultMask);
        if (addrValid == false) {
            return {0, 0, 0, 0};
        }
        return strToVector(userMask);
    }
    else {
        return potentialMask;
    }
}

void choosingSubnets(vector<int> quartetList, int newAddrs) {
    bool choosingSubnets = true;

    while(choosingSubnets) {
        int subnetChoice;
        char CSChoice;
        cout << endl << "Enter the subnet you would like to see. Subnet ranges include network and broadcast address." << endl;
        cout << "(Ex. 16 for 16th subnet)" << endl;
        cout << "Enter here: ";
        cin >> subnetChoice;

        vector<vector<int>> userRange = getRange(subnetChoice, quartetList, newAddrs);
        cout << endl << "SUBNET " << subnetChoice << ": " << userRange[0] << " to " << userRange[1] << endl;

        cout << endl << "Would you like to choose again? (Y/n): ";
        cin >> CSChoice;

        if (CSChoice != 'Y') {
            choosingSubnets = false;
        }
    }
}

int main() {
    //Main user Variables
    string userAddr;

    //Address validation
    bool addrValid;

    //Default Address Range Info
    char addrClass;
    vector<int> quartetList;
    vector<int> defaultMask;
    int defaultBits;
    int defaultAddrs;
    int addrAdjust;
    int defaultActAddrs;
    int defaultHosts;
    vector<vector<int>> defaultRange;
    vector<vector<int>> defaultActRange;

    //Custom Subnet Options
    int subnetOption;

    //Custom Subnet Info
    vector<int> customMask;
    vector<int> defaultNetAddr;
    int newBits;
    int bitsBorrowed;
    int newAddrs;
    int newHosts;
    vector<vector<int>> newRangeEx;
    int opSubnets; 
    int actualSubnets; 

    //Address Input
    cout << endl << endl << endl;
    cout << "Enter an IP Network Address. The last quartet must be 0." << endl;
    cout << "Enter here: ";
    cin >> userAddr;

    //Validation
    addrValid = validateAddress(userAddr, true);
    if (addrValid == false) {
        return 0;
    }

    //Default Information gathering
    quartetList = strToVector(userAddr); 
    addrClass = getClass(quartetList[0]);
    defaultMask = getDefMask(addrClass);
    defaultBits = getBits(defaultMask);
    defaultAddrs = getAddr(defaultBits);
    addrAdjust = adjustAddr(quartetList, defaultMask);
    defaultActAddrs = defaultAddrs - addrAdjust;
    defaultHosts = defaultAddrs - 2;
    defaultNetAddr = getDNA(quartetList, defaultMask);
    defaultRange = getRange(1, defaultNetAddr, defaultAddrs);
    defaultActRange = getRange(1, quartetList, defaultActAddrs);

    //Default Information
    cout << endl << "             DEFAULT NETWORK INFORMATION" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Address Class: Class " << addrClass << endl;
    cout << "Default Subnet Mask: " << defaultMask << endl;
    cout << "Default Number of Bits: " << defaultBits << endl;
    cout << "Default Number of Addresses: " << defaultAddrs << endl;
    cout << "Default Number of Usable Addresses: " << defaultHosts << endl;
    cout << "Accurate Number of Usable Addresses: " << (defaultActAddrs - 2) << endl;
    cout << "Default Address Range: " << defaultRange[0] << " to " << defaultRange[1] << endl;
    cout << "Accurate Address Range: " << defaultActRange[0] << " to " << defaultActRange[1] << endl;

    //Option Paths
    cout << endl << "What do you wish to do now?" << endl;
    cout << "1. Recommend me a subnet mask based on needed number of usable addresses." << endl;
    cout << "2. Recommend me a subnet mask based on needed number of subnets." << endl;
    cout << "3. Entering in my own subnet mask." << endl;
    cout << "Enter a number of the corresponding option: ";
    cin >> subnetOption;

    customMask = createCustom(subnetOption, defaultActAddrs, defaultBits, defaultMask);
    if (customMask[0] == 0) {
        return 0;
    }

    //Subnet Information Gathering
    newBits = getBits(customMask);
    bitsBorrowed = newBits - defaultBits;
    newAddrs = getAddr(newBits);
    newHosts = newAddrs - 2;
    opSubnets = defaultAddrs / newAddrs;
    actualSubnets = defaultActAddrs / newAddrs;
    newRangeEx = getRange(1, quartetList, newAddrs);

    //Custom Information
    cout << endl << "              CUSTOM SUBNET INFORMATION" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "New Number of Bits: " << newBits << endl;
    cout << "Bit(s) Borrowed: " << bitsBorrowed << endl;
    cout << "New Number of Addresses per Subnet: " << newAddrs << endl;
    cout << "New Number of Usable Addresses per Subnet: " << newHosts << endl;
    cout << "Optimal Number of Subnets (for full default range): " << opSubnets << endl;
    cout << "Actual Number of Subnets: " << actualSubnets << endl;
    cout << "Example of New Subnet Range: " << newRangeEx[0] << " to " << newRangeEx[1] << endl;

    //Checking all the subnets
    choosingSubnets(quartetList, newAddrs);

    return 0;
}
