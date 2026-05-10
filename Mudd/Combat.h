#ifndef COMBAT_H
#define COMBAT_H

#include "Entity.h" 
#include <vector>
#include "Item.h"

class CombatManager {
    public:
        void executeRound(Entity& attacker, Entity& defender);

    private: 
        void handleDeath(Entity& winner, Entity& loser);
        void dropLoot(Entity& winner);

        std::vector<Item> commonLootTable;
        std::vector<Item> rareLootTable;
        std::vector<Item> epicLootTable;
};

#endif