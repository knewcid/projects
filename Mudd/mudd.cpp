#include <iostream>
#include <cstdlib>
#include "Player.h"
#include "Combat.h"


int main (void) {
	srand(static_cast<unsigned>(time(0)));

	Game myGame;
	myGame.Initialize();		// The Core Logic Loop!!
		while(myGame.IsRunning()) {
			myGame.ProcessInput();
			myGame.Update();	// This is where the logic ties into life { Healing, aggro, normal, death_trap } <-- ROOMSTYPE
			myGame.Render();	//	\\|==> Move characters/check collisions		\\ Even the character and state management
		}
	    myGame.Shutdown(); // Clean up
	return 0;
}