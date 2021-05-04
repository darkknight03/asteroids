#ifndef NAIVE_BAYES_LEVEL_H
#define NAIVE_BAYES_LEVEL_H

#include "Spaceship.h"
#include <vector>
#include <map>

namespace asteroids {

    class Level {
        const int kRadius = 30;

    public:
        Level(int num_ships, int per_row, int health);

        int GetHealth() const;

        int GetNumShips() const;

        std::map<int, Spaceship>& GetEnemies();

        std::vector<int>& GetEnemiesAlive();

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
         * Checks if ship at bottom of screen
         * @param ship enemy ship
         * @param bottom y coordinate of bottom
         * @return
         */
        bool IsAtBottom(Spaceship& ship, int bottom);

        /**
         * Calculates the spacing in between ships evenly
         * @param x1 the first coordinate
         * @param x2 the second coordinate
         * @param num_ships per row
         * @return the calculation
         */
        double CalculateShipSpacing(int x1, int x2, int num_ships) const;

        /**
         * Initializes enemy ships original position based on game board coordinates
         * @param x1 top right x
         * @param y1 top right y
         * @param x2 bottom left x
         * @param y2 bottom left y
         */
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
