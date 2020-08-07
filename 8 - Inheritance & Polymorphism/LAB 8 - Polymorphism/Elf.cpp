/*
Stores the elf's family name as a string.

The elf does not attack elf's from its own family.

The damage done by the elf is the percentage of the elf's health remaining (health / MAX_HEALTH) 
multiplied by the elf's attack strength.
*/
#include <iostream>
#include <string>

#include "Elf.h"
#include "Character.h"

using namespace std;

Elf::Elf(const string &name, double health, double attackStrength, const string &family) 
    : Character(ELF, name, health, attackStrength), familyName(family) {    
}



void Elf::attack(Character &opponent) {
    double damage = 0;
    
    if (opponent.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(opponent);

        if (opp.familyName == this->familyName) {    
            cout << "Elf " << this->name << " does not attack Elf " << opponent.getName() << ".";
            cout << endl;
            cout << "They are both members of the " << opp.familyName << " family.";
            cout <<  endl;
            return;
        }
    }
    damage = (this->health / MAX_HEALTH) * this->attackStrength;

    //opponent.setHealth(opponent.getHealth() - damage);
    opponent.damage(damage);

    cout << "Elf " << this->name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!";
    cout << endl;
    cout << opponent.getName() << " takes " << damage << " damage.";
    cout << endl;
    return;
}