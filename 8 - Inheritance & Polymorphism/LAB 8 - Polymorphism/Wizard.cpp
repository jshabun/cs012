/*
Stores the wizard's rank as an int.

When a wizard attacks another wizard, the damage done is the wizard's attack strength multiplied by the ratio of 
the attacking wizard's rank over the defending wizard's rank.

The damage done to non-wizards is just the attack strength. The wizard's health is not taken into consideration.
*/
#include <iostream>
#include <string>

#include "Character.h"
#include "Wizard.h"

using namespace std;

Wizard::Wizard(const string &name, double health, double attackStrength, int wizRank) 
    : Character(WIZARD, name, health, attackStrength), rank(wizRank) {
}


void Wizard::attack(Character &opponent) {
    double damage = 0;
    
    if (opponent.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);

        // add static_cast<double> to ratio to get correct rounding
        damage = this->attackStrength * (static_cast<double>(this->rank) / static_cast<double>(opp.rank));

        //opponent.setHealth(opponent.getHealth() - damage);
        opponent.damage(damage);

        cout << "Wizard " << this->name << " attacks " << opponent.getName() << " --- POOF!!";
        cout << endl;
        cout << opponent.getName() << " takes " << damage << " damage.";
        cout << endl;
        return;
    } else {
        damage = attackStrength;

        //opponent.setHealth(opponent.getHealth() - damage);
        opponent.damage(damage);

        cout << "Wizard " << this->name << " attacks " << opponent.getName() << " --- POOF!!";
        cout << endl;
        cout << opponent.getName() << " takes " << damage << " damage.";
        cout << endl;
        return;
    }
}