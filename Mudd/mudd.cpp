#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Player.h"
#include "Combat.h"

using namespace std;

enum RoomType { NORMAL, SHOP, HEALING, DEATH_TRAP };


int main (void) {
	srand(time(0));

	Game myGame;
    myGame.Initialize(); // Setup everything

    while (myGame.IsRunning()) {
        myGame.ProcessInput(); // Handle keys/mouse
        myGame.Update();       // Move characters/check collisions
        myGame.Render();       // Draw to screen
    }

    myGame.Shutdown(); // Clean up

	if (currentRoom.type == HEALING) {player.hp += 5;}

	Character hero("Aragorn");
	cout << "Welcome, " << hero.name << "! HP: " << hero.hp << "/" << hero.maxHP << endl;

	int swarm = rand() % 10 + 1;

	for (swarm; swarm > 0; swarm --) fightNPC(hero);

	hero.showInventory();
	return 0;
}
