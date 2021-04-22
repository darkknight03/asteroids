#ifndef NAIVE_BAYES_LEVEL_H
#define NAIVE_BAYES_LEVEL_H

#include "Spaceship.h"
#include <vector>
#include <map>

namespace asteroids {

    class Level {
        const int kRadius = 25;

    public:
        Level(int num_ships, int per_row, int health);

        int GetHealth() const;

        int GetNumShips() const;

        std::map<int, Spaceship> GetEnemies() const;

        std::vector<int> GetEnemiesAlive() const;

        /**
         * Checks if ship is moving right and cannot move any more right
         * @return true if on edge
         */
        bool IsOnRightEdge(Spaceship &ship);

        /**
         * Checks if ship is moving left and cannot move any more left
         * @return true if on edge
         */
        bool IsOnLeftEdge(Spaceship &ship);

        double CalculateShipSpacing(int x1, int x2, int num_ships) const;

        void InitializeShips(int x1, int y1, int x2, int y2);


    private:
        int num_ships_;

        int per_row_;

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
