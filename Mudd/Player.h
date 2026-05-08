#include "Enitity.h"

class Player : public Entity {
    public:
        int experience;
        int level;

        // Call Entity constructor
        Player(std::string n) : Entity(n, 100, 5, 2), 
        experience(0), level(1) {}

        void gainExperience(int amount);
};