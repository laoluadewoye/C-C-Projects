#include <iostream>
#include <ctime>

using namespace std;

int main() {
    
    srand(time(NULL));
    int series = rand() % 2;
    cout << "And the character you get is...";
    
    if (series == 0) {
        int g_se = rand() % 206;
        int virto = rand() % 24;
        int leana = rand() % 17;
        int isuka = rand() % 6;
        int regina = rand() % 4;
        int ville = rand() % 4;
        int viscosa = rand() % 8;
        int cidnei = rand() % 4;
        if (g_se == 1) {
            cout << "Hey look it's Virto. You got form #" << virto;
        }
        else if (g_se == 63) {
            cout << "Oh, wow. Good job, you got the one that drinks starbucks everyday. At least version #" << leana << " of her.";
        }
        else if (g_se > 1 and g_se < 20) {
            cout << "G1-" << g_se << ". Oh here's a neat, versatile one.";
            if (g_se == 7) {
                cout << " And who's more versestile than a Mage aye? Looks like she's in form " << isuka << " today."; 
            }
            else if (g_se == 13) {
                cout << " Well, she is versatile, but she prefers to just eat, be it form " << regina << " or another.";
            }
            else if (g_se == 18) {
                cout << " Sweet too. Right now she's in form " << ville << " but don't eat her!";
            }
            else if (g_se == 19) {
                cout << " Extreamly versatile. I wouldn't get on the bad end of this slime dom. Form " << viscosa << " is down the hall.";
            }
        }
        else if (g_se > 19 and g_se < 34) {
            cout << "G2-" << g_se << ". Hope he/she isn't too busy with the squad storming Fort Knox.";
        }
        else if (g_se > 33 and g_se < 45) {
            cout << "G3-" << g_se << ". Remember to donate to your yokai so you can be blessed with her power!";
        }
        else if (g_se > 44 and g_se < 54) {
            cout << "G4-" << g_se << ". Wonder who's the parent.";
            if (g_se == 44) {
                cout << " Also wonder which species of her's form " << cidnei << " is.";
            }
        }
        else if (g_se > 53 and g_se < 63) {
            cout << "G5-" << g_se << ". Hi Night!";
        }
        else if (g_se > 63 and g_se < 89) {
            cout << "G7-" << g_se << ". Make sure to get your day pass before entering the garden!";
        }
        else if (g_se > 88 and g_se < 102) {
            cout << "G8-" << g_se << ". Before one can storm Fort Knox, one must learn the ways.";
        }
        else if (g_se > 101 and g_se < 130) {
            cout << "G9-" << g_se << ". Time for some fun in the tropical sun!";
        }
        else if (g_se > 129 and g_se < 153) {
            cout << "G10-" << g_se << ". I don't have anything witty, so uhh...enjoy snow?"; 
        }
        else if (g_se > 152 and g_se < 164) {
            cout << "G11-" << g_se << ". No matter what, your character has lived long enough to expect the spanish inquisition.";
        }
        else if (g_se > 163 and g_se < 188) {
            cout << "G12-" << g_se << ". Have you ever wondered what happens when you put mamono in modern times?";
        }
        else if (g_se > 189) {
            cout << "G13-" << g_se << ". Careful spending time with her. Where she lives is the most dangerous for purity.";
        }
    }
    else if (series == 1) {
        int h_se = rand() % 97;
        if (h_se < 34) {
            cout << "H1-" << h_se << ". An animal alter...Pog?";
        }
        else if (33 < h_se and h_se < 42) {
            cout << "H2-" << h_se << ". Wonder if they know Calice's real name...";
        }
        else if (41 < h_se and h_se < 49) {
            cout << "H3-" << h_se << ". Make sure to wear warm garments outside of the facilities at all times!";
        }
        else if (48 < h_se and h_se < 64) {
            cout << "H4-" << h_se << ". Great, now it smells like Capitalism again.";
        }
        else if (63 < h_se and h_se < 76) {
            cout << "H5-" << h_se << ". Wait this isn't even MGE. >:(";
        }
        else if (h_se > 75) {
            cout << "H6-" << h_se << ". You've heard of monster girls, now get ready for...";
        }
    }
    
    return 0;
}

