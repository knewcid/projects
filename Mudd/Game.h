#pragma once // Limits 1 instance to runtime
#include <vector> 
#include "Player.h"
#include "Combat.h"
#include "NPC.h"

class Game {
    public:
        Game(); // Constructor

        bool Initialize();
        void ProcessInput();
        void Update();
        void Render();
        void Shutdown();

        bool IsRunning() const { return mIsRunning; }

        private:
            bool mIsRunning;
            Player mHero;
            std::vector<NPC> mEnemies;
            CombatManager::mCombatManager; 
};