#include <vector>
#include <string>
#include "Entity.h"
#include "Item.h"
#include "Combat.h"
#include <thread>       // for std::chrono::milliseconds
#include <chrono>       // for std::this_thread::sleep_for

using namespace std;


void CombatManager::executeRound(Entity& attacker, Entity& defender) {
    int damage = attacker.getTotalStr() + (rand() % 5);
    defender.takeDamage(damage);

    if(defender.hp <= 0) {
        handleDeath(attacker, defender);
    }
}

void CombatManager::handleDeath(Entity& winner, Entity& loser) {
    cout << loser.name << " has been defeated!\n" ;
    // check if the winner is player or someone to loot
    dropLoot(winner); 
}

void CombatManager::dropLoot(Entity& reciever) {
    int roll = rand() % 100 + 1;
    vector<Item>* selectTier;
    string rarityName;

    if(roll <= 70) {
        selectTier = &commonLootTable;
        rarityName = "Common";
    } else if(roll <= 95) {
        selectTier = &rareLootTable;
        rarityName = "Rare";
    } else {
        selectTier = &epicLootTable;
        rarityName = "Epic";
    }

    if (!selectTier->empty()) {
        int itemIndex = rand() % selectTier->size();
        Item dropped = (*selectTier)[itemIndex];
        reciever.inventory.push_back(dropped);
        cout << ">> [LOOT]: " << reciever.name << " found a [" << rarityName 
        << "] " << dropped.name << "!\n" ;
    }
}