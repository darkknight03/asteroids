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

        std::map<int, Spaceship>& GetEnemies();

        std::vector<int> GetEnemiesAlive() const;

        /**
         * Checks if ship is moving right and cannot move any more right
         * @return true if on edge
         */
        bool IsOnRightEdge(Spaceship &ship, int xEdge);

        /**
         * Checks if ship is moving left and cannot move any more left
         * @return true if on edge
         */
        bool IsOnLeftEdge(Spaceship &ship, int xEdge);

        /**
         * Calculates the spacing in between ships evenly
         * @param x1 the first coordinate
         * @param x2 the second coordinate
         * @param num_ships per row
         * @return the calculation
         */
        double CalculateShipSpacing(int x1, int x2, int num_ships) const;

        void InitializeShips(int x1, int y1, int x2, int y2);

    private:
        int num_ships_;

        /**
         * Number of enemies per row
         */
        int per_row_;

        int health_;

        /**
         * Map from index to spaceship
         */
        std::map<int, Spaceship> enemies_;

        /**
         * Contains a number mimicking the enemies position in vector
         * if ship is destroyed, remove index from vector
         * Used for checking if the level is over
         */
        std::vector<int> alive_;

    };

}
#endif //NAIVE_BAYES_LEVEL_H
