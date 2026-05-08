#ifndef NPC_H
#define NPC_H

#include "Entity.h"
#include <string>

// The AI modes of mobs
enum class AIstate { IDLE, AGGRESSIVE, FLEEING };

class NPC : public Entity {
    public:
        AIstate state;
        int xpValue; // the amount of exp npc gives player 

    // Constructor: Passes name and basic stats up to the Entity parent 
        NPC(std::string n, int h, int s, int d, int xp);

    // Automated logic called during the game update tick
        void update();

    // Specific behavior for when an NPC take a turn
        void performAction();
};

#endif