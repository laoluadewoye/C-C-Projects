#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    int defense, offense, damageoutput, output, defensecheck, offensecheck;
    double damage, percentconvert;
    
    defense = rand() % 256;
    offense = rand() % 256;
    defensecheck = defense - offense;
    offensecheck = offense - defense;
    
    damage = rand() % 1001;
    cout << "Quickly, how this works. Damage is not tied to level, but the offense and defense stats are. They are, in layman's terms, compared and the output is the calculated damage done, applied to whatever damage is chosen.\n\nThe attacker has a " << offense << " offensive rating and the other has a " << defense << " defensive rating.\nThe original damage done is " << damage << " damage.\n\nCalculating(.  .  .)\n\n";
    
    if (defensecheck > 50) {
        cout << "No damage is done, attacker is getting parried to the exosphere. 0 damage dealt.";
    }
    else if (offensecheck > 50) {
        cout << "All damage giveth is taketh, prepare for a funeral lmao. " << damage << " damage dealt.";
    }
    else {
        cout << "O.C. --> " << offensecheck << "\n";
        cout << "D.C. --> " << defensecheck << "\n\n";
        if (offense > defense) {
            percentconvert = 100 - offensecheck;
            cout << percentconvert << "\n\n";
            damage = damage * (percentconvert / 100);
            cout << "Attacker has advantage, but there is still some damage deflected. " << damage << " damage dealt.";
        }
        else if (defense > offense) {
            percentconvert = 50 - defensecheck;
            cout << percentconvert << "\n\n";
            damage = damage * (percentconvert / 100);
            cout << "Defender has advantage, so most of the damage is shrugged off. " << damage << " damage dealt.";
        }
        else if (offense = defense) {
        damage = damage / 2;
        cout << "Pretty even and stable, so it's split in half. " << damage << " damage dealt.";
        }
    }

    return 0;
}
