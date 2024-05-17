#include <iostream>

using namespace std;

int main()
{
    cout << "I have made this 8 ball for yee to use or something. Ask a question out loud to yourself, type 'start' and wait for an answer.\n";
    string start;
    int randomn;
    string insult;
    cin >> start;
    
    while (start != "start") {
        cout << "You dumbass. Just type the word 'start' please.\n";
        cin >> start;
    }
    
    cout << "\n";
    randomn = rand() % 10;
    if (randomn == 1) {
        cout << "Yes.\n";
    }
    else if (randomn == 2) {
        cout << "No.\n";
    }
    else if (randomn == 3) {
        cout << "Maybe.\n";
    }
    else if (randomn == 4) {
        cout << "Who knows? Why are you asking me?\n";
    }
    else if (randomn == 5) {
        cout << "There is a high probability.\n";
    }
    else if (randomn == 6) {
        cout << "Who knows really. I can only make these answers general enough to apply to almost every possible question.\n";
    }
    else if (randomn == 7) {
        cout << "The answer lays...within you. :3\n";
    }
    else if (randomn == 8) {
        cout << "<insert answer that perfectly answers your question.\n";
    }
    else if (randomn == 9) {
        cout << "On the off chance you asked a math question and you got this answer, did you remember to check your work?\n";
    }
    else {
        cout << "Somehow this thing glitched. This isn't your fault, so feel free to insult me here.\n";
        cin >> insult;
        cout << "I hope you didn't make it too bad. However if you said something nice then thank you for being a good person.\n";
    }
    
    cout << "I hope you are statisfied with your answer.\n";
    return 0;
}

