#include <iostream>
using namespace std;

char tag[101] = {'o', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@'};

void board();

int main() {
    
    string endcode = "no";
    string drawline;
    int tagpicker;
    
    cout << "Welcome to Part Four! If you have given me a proper amount of time to prepare while you slay some bosses wwith some epic damage, then thank you!\n\n";
    cout << "If not, how dare you! Now I have to making something from the jump!\n\n";
    cout << "All the time: Glad you did too, this too quite the research to create... \nNo time: Um, Um, oh I know! I can um...\n\n";
    cout << "ATT: I know how much you loved drawing. All the pieces you created, whether it was for a funny representation of us in Smash, or an\nassignment throwaway...\nNT: You like drawing right? I know I do. Your animations are fast pace and natural, and fun to watch. Oh, I know!\n\n";
    cout << "ATT: Ah, my favorite was the George Mason one! I swear, if they don't do your work justice I will personally shove the admissionns\nteam into the back of a merc!\nNT: Done! Fast as frick too. Now I don't have time to explain it I need to polish it bye!\n\n";
    cout << "ATT: Right....well then. Laolu is a forgetful fellow, but some of his favorite memories of yours is seeing the passion projects that\nyou make. So, we have made you a really crude place to draw!\n\n";
    cout << "Below is your drawing space. The way the code works is that it will ask you what each time.\nType 'vert' for this line --> 'l'\nType 'whore' for this line --> '_' (get it? whore-izontal? haha owo)\nType 'reset' to get '@' back to undo\n\n";
    cout << "Next, it will ask what number you choose. Each '@' is connected to a value, that counts left to right, top to bottom, from 1 to 100.\nThat is why I chose the 10x10 grid to make it easier. Hopefully you get used to it after exploring the system. :DDLCSayoriNervous:\n\n";
    cout << "Last you, it asks you if you want to end the program. Type 'yes' if you do, 'no' if you don't. With that, hope you enjoy!\n\n";
    cout << "Oh, and last thing! I kinda lost the order thing after a while, so feel free to listen however now :DDLCMonikaShrug\n\n";
    
    while (endcode == "no") {
        board();
        cout << "vert = |\nwhore = _\nreset = @\nChoice: ";
        cin >> drawline;
        cout << "\nWhat number?\nAnswer: ";
        cin >> tagpicker;
        cout << "\nEnd the drawing? [you can always click run to do it again. Can't save though]  ";
        cin >> endcode;
    
        if (drawline == "vert") {
            tag[tagpicker] = '|';
        }
        else if (drawline == "whore") {
            tag[tagpicker] = '_';
        }
        else if (drawline == "reset") {
            tag[tagpicker] = '@';
        }
        else {
            cout << "\nYou're breaking the code! :DDLCNatsukiAngry:\nPress stop!\nHur-@##@$%\n\n";
        }
        if (endcode == "yes") {
            cout << "\n\tFinal Board\n\n";
            board();
            cout << "Fair enough. If you are ready, Part 5 will be coming in 3...2...1 - ";
            break;
        }
    }
    
    return 0;
}

void board()

{
    system("cls");

    cout << endl;

    cout << " " << endl;

    cout << " " << tag[1] << "    " << tag[2] << "    " << tag[3] << "    " << tag[4] << "    " << tag[5] << "    " << tag[6] << "    " << tag[7] << "    " << tag[8] << "    " << tag[9] << "    " << tag[10]  << endl;

    cout << " " << endl;

    cout << " " << tag[11] << "    " << tag[12] << "    " << tag[13] << "    " << tag[14] << "    " << tag[15] << "    " << tag[16] << "    " << tag[17] << "    " << tag[18] << "    " << tag[19] << "    " << tag[20]  << endl;

    cout << " " << endl;

    cout << " " << tag[21] << "    " << tag[22] << "    " << tag[23] << "    " << tag[24] << "    " << tag[25] << "    " << tag[26] << "    " << tag[27] << "    " << tag[28] << "    " << tag[29] << "    " << tag[30]  << endl;

    cout << " " << endl;

    cout << " " << tag[31] << "    " << tag[32] << "    " << tag[33] << "    " << tag[34] << "    " << tag[35] << "    " << tag[36] << "    " << tag[37] << "    " << tag[38] << "    " << tag[39] << "    " << tag[40]  << endl;

    cout << " " << endl;

    cout << " " << tag[41] << "    " << tag[42] << "    " << tag[43] << "    " << tag[44] << "    " << tag[45] << "    " << tag[46] << "    " << tag[47] << "    " << tag[48] << "    " << tag[49] << "    " << tag[50]  << endl;

    cout << " " << endl;

    cout << " " << tag[51] << "    " << tag[52] << "    " << tag[53] << "    " << tag[54] << "    " << tag[55] << "    " << tag[56] << "    " << tag[57] << "    " << tag[58] << "    " << tag[59] << "    " << tag[60]  << endl;

    cout << " " << endl;

    cout << " " << tag[61] << "    " << tag[62] << "    " << tag[63] << "    " << tag[64] << "    " << tag[65] << "    " << tag[66] << "    " << tag[67] << "    " << tag[68] << "    " << tag[69] << "    " << tag[70]  << endl;

    cout << " " << endl;

    cout << " " << tag[71] << "    " << tag[72] << "    " << tag[73] << "    " << tag[74] << "    " << tag[75] << "    " << tag[76] << "    " << tag[77] << "    " << tag[78] << "    " << tag[79] << "    " << tag[80]  << endl;

    cout << " " << endl;

    cout << " " << tag[81] << "    " << tag[82] << "    " << tag[83] << "    " << tag[84] << "    " << tag[85] << "    " << tag[86] << "    " << tag[87] << "    " << tag[88] << "    " << tag[89] << "    " << tag[90]  << endl;

    cout << " " << endl;

    cout << " " << tag[91] << "    " << tag[92] << "    " << tag[93] << "    " << tag[94] << "    " << tag[95] << "    " << tag[96] << "    " << tag[97] << "    " << tag[98] << "    " << tag[99] << "    " << tag[100]  << endl;

    cout << " " << endl;
    
    cout << "\n\tDa drawing board! [Scroll up for details. Basic info under]\n\n";
}

