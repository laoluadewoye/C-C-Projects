#include <iostream>
#include <ctime> 

using namespace std;

int main() {
    
    srand(time(NULL));
    
    //Part two!
    cout << "Welcome to Part two! In this part, I'm using one of the few things I know. Encryption!\n\n";
    cout << "You see, learning about cybersecurity isn't all boring. You can get tidbits like this to play with~\n\n";
    cout << "While you are jamming out to gogobebe (or another song), you can solve this Vigenère puzzle-\n\n";
    cout << "Fkealfqscnih \n\n";
    cout << "No one know's what a Vigenère cipher is these days, so i'll explain it. It is basically multiple Ceaser shifts put together. You know how you write a secret code by writing it out and like, moving everything one letter?\n\n";
    cout << "For example, you can turn 'apple' into 'bqqmf' by shifting each letter once. However, this is suprisingly easy to figure out by brute force\n\n";
    cout << "Which is where the Vigenere comes in. More shifts = harder code = bigger brain tim.\n\n";
    cout << "For your 'key' to figure this out, you will take each number from how you would write out your birthday. You might remember this\nquestion from earlier .>.\n\n";
    cout << "You should have six numbers to use in order. After, take each number and go in order as you shift the corresponding letter that many\ntimes. For example...\n\n";
    cout << "If we apply your birth year of '2003' to 'apple', a will be shifted 2 times to c, both ps will remain the same, l will be shifted 3\ntimes to o, and e will be shifted 2 times to g. Note that it wrapped around back to the '2'\n\n";
    cout << "However, this is encrypting. To find out your answer, you must DEcrypt. Meaning you will subtract two instead of adding two. Rememba\ndis!\n\n";
    cout << "So do that, but with all six numbers in order! Then you will get the next song to listen to! If, like, you wanna....\n\n";
    cout << "Type 'yes' in all lowercase to continue [Warning: this will reveal the answer to cypher].\n";
    
    
     //Part three
    string answer;
    int fakeload = 101;
    int fakeload2 = 100;
    cin >> answer;
    if (answer == "yes") {
        cout << "\n\n\n\n\n\nLoading time for Part three/four assets - " << rand()% fakeload << "." << rand()% fakeload2 << " milliseconds\n ______________ \n\n";
        cout << "Welcome to part three!\n\n";
        cout << "Hopefully you are enjoying your complementary music IN THE RIGHT ORDER.\n\n";
        cout << "However, if you couldn't get the code, it was Decalcomanie. It was supposed to be HIP next, but that short title wasn't sadistic\nenough~\n\n";
        cout << "I respect you for trying though (or being lazy and realizing I actually don't have power through this code). For that, I have\nbrought you a turn-based battle game as a reward while I work on part four!\n\n";
        cout << "Boss Battle Simulator for unwinding - https://onlinegdb.com/iJKSsVuEm\n";
        cout << "Part 4 link [plz give time I need to think of something on the fly :DDLCSayoriCry:] - https://onlinegdb.com/XlnjB8L3Q";
        
    }
    

    return 0;
}


