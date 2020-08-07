/*
Stores the warrior's allegiance as a string.

The warrior does not attack warriors that have the same allegiance.

The damage done by the warrior is the percentage of the warrior's health remaining (health / MAX_HEALTH) 
multiplied by the warrior's attack strength.
*/
#include <iostream>
#include <string>

#include "Character.h"
#include "Warrior.h"

using namespace std;

Warrior::Warrior(const string &name, double health, double attackStrength, const string &warAlleg)
    : Character(WARRIOR, name, health, attackStrength), allegiance(warAlleg) {    
}



void Warrior::attack(Character &opponent) {
    double damage = 0;

    if (opponent.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);

        if (opp.allegiance == this->allegiance) {    
            cout << "Warrior " << this->name << " does not attack Warrior " << opponent.getName() << ".";
            cout << endl;
            cout << "They share an allegiance with " << opp.allegiance << ".";
            cout <<  endl;
            return;
        }
    }
    
    damage = (this->health / MAX_HEALTH) * this->attackStrength;

    //opponent.setHealth(opponent.getHealth() - damage);
    opponent.damage(damage);

    cout << "Warrior " << this->name << " attacks " << opponent.getName() << " --- SLASH!!";
    cout << endl;
    cout << opponent.getName() << " takes " << damage << " damage.";
    cout << endl;
    return;
}