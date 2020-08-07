/*
Stores the wizard's rank as an int.

When a wizard attacks another wizard, the damage done is the wizard's attack strength multiplied by the ratio of 
the attacking wizard's rank over the defending wizard's rank.

The damage done to non-wizards is just the attack strength. The wizard's health is not taken into consideration.
*/
#ifndef __WIZARD_H__
#define __WIZARD_H__

#include <iostream>
#include <string>

#include "Character.h"

using namespace std;

class Wizard : public Character {
    private:
        int rank;

    public:
        Wizard(const string &name, double health, double attackStrength, int wizRank);
        void attack(Character &opponent);
};

#endif