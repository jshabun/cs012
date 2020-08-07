/*
Stores the elf's family name as a string.

The elf does not attack elf's from its own family.

The damage done by the elf is the percentage of the elf's health remaining (health / MAX_HEALTH) 
multiplied by the elf's attack strength.
*/

#ifndef __ELF_H__
#define __ELF_H__

#include <iostream>
#include <string>

#include "Character.h"

using namespace std;

class Elf : public Character {
    private:
        string familyName;

    public:
        Elf(const string &name, double health, double attackStrength, const string &family);
        void attack(Character &opponent);
};

#endif