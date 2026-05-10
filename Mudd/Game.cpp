#include "Game.h"
#include <iostream>

Game::Game() : mIsRunning(true), mHero("Aragorn") {

}

bool Game::Initialize() {

    
    std::cout << "Welcome, " << mHero.name << "!" << std::endl;

    return true;
}

void Game::ProcessInput() {

                // Process Keystrokes here

}

void Game::Update() {

    // Room logic goes here .. CALL FOR ROOM.H
    if (mCurrentRoom.hasEnemy()) {
        Entity* enemy = mCurrentRoom.getEnemy();

        // Now pass mHero as reference 
        mCombatManager.executeRound(mHero, *enemy);
    }
    // NPC encoutners here also
}

void Game::Render() {

    std::cout <<  "HP: " << mHero.hp << "/" << mHero.maxHP << std::endl;

}

void Game::Shutdown() {

    mIsRunning = false;
    
    // Clean up memory here also

}