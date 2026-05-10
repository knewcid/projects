#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>

enum Rarity { COMMON, RARE, EPIC };

//sets the format for all items to drop
struct Item {
	string name;
	string description;
	Rarity rarity;
	int strBonus;
	int defBonus;
	bool equippable;
    int decayTimer = 0;
};

//Declared for mobs to have access
extern std::vector<Item> commonLootTable;
extern std::vector<Item> rareLootTable;
extern std::vector<Item> epicLootTable;

#endif