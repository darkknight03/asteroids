#ifndef NAIVE_BAYES_LEVEL_H
#define NAIVE_BAYES_LEVEL_H

#include "Spaceship.h"
#include <vector>

namespace asteroids {

    const int kNumOfShipsPerRow = 5;

    class Level {
    public:
        Level(int num_ships, int health);

        int GetHealth() const;

        int GetNumShips() const;

        std::vector<Spaceship> GetEnemies() const;

        int CalculateShipSpacing(int num, int window_size);

    private:
        int num_ships_;

        int health_;

        std::vector<Spaceship> enemies_;

    };

}
#endif //NAIVE_BAYES_LEVEL_H
