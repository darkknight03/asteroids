#ifndef FINAL_PROJECT_GAMEENGINE_H
#define FINAL_PROJECT_GAMEENGINE_H

#include <Spaceship.h>
#include <Level.h>
#include <Laser.h>

namespace asteroids {

    class GameEngine {

    public:
        GameEngine(Spaceship& ship);

        void RunGame();

        void InitializeLevels(int number_of_levels);

        bool LevelOver();

        void SwitchLevel();

    private:

        Level current_level_;

        Spaceship ship_;

        std::vector<Level> levels_;

        std::vector<Spaceship> enemies_;

    };


#endif //FINAL_PROJECT_GAMEENGINE_H
} //namespace asteroids