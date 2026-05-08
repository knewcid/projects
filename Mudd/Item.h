#ifndef Item_H
#define Item_H

#include <string>
#include <vector>

using namespace std;

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
extern vector<Item> commonLootTable;
extern vector<Item> rareLootTable;
extern vector<Item> epicLootTable;

#endifs