#include "Player.h"
#include <iostream>

// Construct passes stat up the parent tree
Player::Player(std::string n)
    : Entity(n, 100, 5, 2), experience(0), level(1) {}

void Player::gainExperience(int amount) {
    experience += amount;
    std::cout << name << " gained " << amount << " XP!\n";

    // Simple LVL logic ====== > change later
    if (experience >= level * 100) {
        levelUp();
    }
}

void Player::levelUp() {
    level ++;
    maxHP += 20;
    hp = maxHP;         // Heal on LVL up
    baseStr +=2;
    baseDef += 1;

    std:: cout << "\n*** LEVEL UP ***\n";
    std:: cout << name << " is now level " << level << "!\n";
    std:: cout << "Increased to HP: " << maxHP << ", STR: " << baseStr << ", and DEF: " << baseDef << endl;    

}