#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>
#include <iostream>
#include <Item.h>

class Entity {
    public:
        std::string name;
        int hp, maxHP, baseStr, baseDef;
        
        std::vector<Item> inventory;

    // Constructor to set base stats
        Entity (std::string n, int h, int s, int d)
        : name(n), hp(h), maxHP(h), baseStr(s), baseDef(d) {}

    // Essential for inheritance!!!
        virtual ~Entity() {}

    // Players and Mobs use the 
        int getTotalStr();
        int getTotalDef();
        void takeDamage(int rawDamage);
        
};

#endif