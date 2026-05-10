#include <vector>
#include <thread>        // for std::this_thread::sleep_for
#include <chrono>       // for std::chrono::milliseconds
#include <string>
#include "Entity.h"
#include "Item.h"
#include "Combat.h"
#include <iostream>
    

using namespace std;


void CombatManager::executeRound(Entity& attacker, Entity& defender) {
    int damage = attacker.getTotalStr() + (rand() % 5);
    defender.takeDamage(damage);

    this_thread::sleep_for(chrono::milliseconds(1000));         // The delay trigger for time lapse

    if(defender.hp <= 0) {
        handleDeath(attacker, defender);
    }
}

void CombatManager::handleDeath(Entity& winner, Entity& loser) {
    cout << loser.name << " has been defeated!\n" ;

    Player* player = dynamic_cast<Player>(&winner);
    if(player) {
        player->gainExperience(50);  // Will need to assign xp dynamic from npc list
        dropLoot(player);
    }
}

void CombatManager::dropLoot(Entity& receiver) {
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
        receiver.inventory.push_back(dropped);
        cout << ">> [LOOT]: " << receiver.name << " found a [" << rarityName 
        << "] " << dropped.name << "!\n" ;
    }
}