/*
Stores the warrior's allegiance as a string.

The warrior does not attack warriors that have the same allegiance.

The damage done by the warrior is the percentage of the warrior's health remaining (health / MAX_HEALTH) 
multiplied by the warrior's attack strength.
*/
#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include <iostream>
#include <string>

#include "Character.h"

using namespace std;

class Warrior : public Character {
    private:
        string allegiance;

    public:
        Warrior(const string &name, double health, double attackStrength, const string &warAlleg);
        void attack(Character &opponent);
};

#endif