#include "Item.h"

using namespace std;

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