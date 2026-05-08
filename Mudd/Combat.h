#ifndef COMBAT_H
#define COMBAT_H

#include "Entity.h" 

class CombatManager {
    public:
        static void executeRound(Entity& attacker, Entity& defender);

    private: 
        static void handleDeath(Entity& winner, Entity& loser);
        static void dropLoot(Entity& winner);
};

#endif