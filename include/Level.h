#ifndef NAIVE_BAYES_LEVEL_H
#define NAIVE_BAYES_LEVEL_H

#include "Spaceship.h"
#include <vector>
#include <map>

namespace asteroids {

    const int kNumOfShipsPerRow = 5;
    const static int kTopLeftX = 50;
    const static int kTopLeftY = 50;
    const static int kBottomRightX = 900;
    const static int kBottomRightY = 900;

    class Level {
    public:
        Level(int num_ships, int health);

        /**
         * Display the enemy ships on the screen
         */
        void Display() const;

        void AdvanceOneFrame();

        int GetHealth() const;

        int GetNumShips() const;

        std::map<int, Spaceship> GetEnemies() const;

        std::vector<int> GetEnemiesAlive() const;

        static int CalculateShipSpacing(int radius, int window_size);



    private:
        int num_ships_;

        int health_;

        std::map<int, Spaceship> enemies_;

        /**
         * Contains a number mimicking the enemies position in vector
         * if ship is destroyed, change number to -1
         * Used for checking if the level is over
         */
        std::vector<int> alive_;

    };

}
#endif //NAIVE_BAYES_LEVEL_H
