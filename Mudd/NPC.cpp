#include "NPC.h"
#include <iostream>

NPC:: NPC(std::string n, int h, int s, int d, int xp)
    : Entity(n, h, s, d), state(AIstate::IDLE), xpValue(xp) {}

void NPC::update() {
    // Basic AI State Machine Logic
    switch (state) {
        case AIstate::IDLE:
            if(rand() % 10 == 0) std::cout << name << " wanders around aimlessly.\n";
            break;
        case AIstate::AGGRESSIVE:
            performAction();
            break;
        case AIstate::FLEEING:
            std::cout << name << " tries to run away!\n";
            break;
    }
}

void NPC::performAction() {
    std::cout << name << " lunges at you with ferocity!!\n";
    
}