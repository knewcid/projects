#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

enum Rarity { COMMON, RARE, EPIC };

//sets the format for all items to drop
struct Item {
	string name;
	string description;
	Rarity rarity;
	int strBonus;
	int defBonus;
	bool equip;
};

class Character {
	public:
		string name;
		int hp, maxHP;
		int baseStr, baseDef;
		vector<Item> inventory; // a place to hold the items found

		Character(string n) : name(n), hp(100), maxHP(100), baseStr(5), baseDef(2) {}

// Calculate total Stats from Inventory and BASE
			int getTotalStr() {
				int total = baseStr;
				for (auto& i : inventory) total += i.strBonus;
				return total;
			}

			int getTotalDef(){
				int total = baseDef;
				for (auto& i : inventory) total += i.defBonus;
				return total;
			}

			void takeDamage(int rawDamage) {
				int actualDamage = rawDamage - getTotalDef();
				if (actualDamage < 1) actualDamage = 1;  // minimum of 1 damage
				hp -= actualDamage;
				cout << name << " takes " << actualDamage << " damage! (HP: " << hp << "/" << maxHP << endl;
			}

		void showInventory() {
			cout << "\n --- " << name << " 's Inventory ---" << endl;
			if (inventory.empty()) cout << "Empty." << endl;
			for (const auto& item : inventory) {
				cout << "- " << item.name << endl;
			}
		}
};

// Item Pool with stats:  {Name, Description, rariety, STR, DEF, equipable}
vector<Item> commonLootTable = {
// Weapon Items 
	{"Rusty Dagger" , "This may fall apart.", COMMON, 1, 0, true},
	{"Rusty Sword", "A true man's weapon.", COMMON, 2, 0, true},
// Armor Items
	{"Cloth tunic", "This needs a fine wash", COMMON, 0, 1, true},
	{"Tattered Cape", "Better than nothing", COMMON, 0, 1, true},
	{"Wooden Shoes", "At least it's something", COMMON, 0, 1, true},
// Augment Items
	{"Health Vile", "Bubbly Red Liquid", COMMON, 0, 0, false},
// Valuable Items
	{"Copper Coin", "Worth a tiny bit", COMMON, 0, 0, false},
// Creature Items
	{"Wolf Pelt", "Coarse grey fur", COMMON, 0, 0, false},
// Food Items
	{"Dried Meat", "Salty and tough", COMMON, 0, 0, false}
};

vector<Item> rareLootTable = {
// Weapon Items
	{"Bronze Dagger", "It has a nice edge.", RARE, 3, 0, true},
	{"Bronze Sword", "It has a nice feel.", RARE, 4, 0, true},
// Armor Items
	{"Leather Jerkin", "Strong and sturdy", RARE, 0, 3, true},
	{"Leather Boots", "Made for walking.", RARE, 0, 2, true},
// Augment Items
	{"Health Potion", "A sweet aroma.", RARE, 0, 0, false},
// Valuable Item
	{"Silver Coin", "Worth a decent amount.", RARE, 0, 0, false},
// Creature Items
	{"Rabbit's Foot", "A slight shift in the air.", RARE, 0, 0, false},
// Food Items
	{"Red Apple", "Shiny and red.", RARE, 0, 0, false},
};

vector<Item> epicLootTable = {
	// Weapon Items
	{"Mythril Sword", "Deathly", EPIC, 10, 2, true},
	//Armor Items
	{"Gold Necklace", "Fancy and GOLD!", EPIC, 0, 3, true},
	// Augment Items
	// Valuable Items
	{"Ancient Scroll", "Dusty and smelly.", EPIC, 0, 0, false},
	// Creature Items
	// Food Items
	{"Chicken Dinner", "The smell....", EPIC, 0, 0, false}
};

void dropLoot (Character& player) {

// Chance to drop RANDOM ITEM
// later add the ability for ^% of item find -> % quality => quantiy.
	int roll = rand() % 100 + 1;

	vector<Item>* selectTier;
	string rarityName;

	if (roll <= 70){ // 70% chance for common loot
		selectTier = &commonLootTable;
		rarityName = "Common";
	} else if (roll <= 95) { // 25% chance for rare loot (71-95)
		selectTier = &rareLootTable;
		rarityName = "Rare";
	} else { 			// 5% chance for loot (96-100)
		selectTier = &epicLootTable;
		rarityName = "Epic";
	}

	int itemIndex = rand() % selectTier->size();
	Item dropped = (*selectTier)[itemIndex];
	player.inventory.push_back(dropped); // Character 'picks up' loot

	cout << ">> [LOOT]: " << player.name << "Found a [" << rarityName << "] " << dropped.name << "!" << endl;
};



	// SIMPLIFIED combat loop
	void fightNPC (Character& player) {

		int npcHP = 30, npcAtk = 10;
		cout << "A grimy GOBLIN lunges at you!" << endl;

		while (npcHP > 0 && player.hp > 0) {
			int pDamage = player.getTotalStr() + (rand() % 5);
			npcHP -= pDamage;
			cout << player.name << " hits for " << pDamage << " damage. GOBLIN HP: " << npcHP << endl; 
		}

		if (npcHP <= 0) {
			cout << "The GOBLIN collapses!" << endl;
			cout << player.name << "'s HP: " << player.hp << "/" << player.maxHP << endl;
			dropLoot(player);
		}
	};

int main (void) {
	srand(time(0));

	Character hero("Aragorn");
	cout << "Welcome, " << hero.name << "! HP: " << hero.hp << "/" << hero.maxHP << endl;

	int swarm = rand() % 10 + 1;

	for (swarm; swarm > 0; swarm --) fightNPC(hero);

	hero.showInventory();
	return 0;
}
