//
// Created by Nathan on 4/19/2021.
//

#include "Level.h"

//TODO: Implement checks for edges
namespace asteroids {

    Level::Level(int num_ships, int per_row, int health) {
        num_ships_ = num_ships;
        health_ = health;
        per_row_ = per_row;
    }

    bool Level::IsOnLeftEdge(Spaceship &ship) {
        return false;
    }

    bool Level::IsOnRightEdge(Spaceship &ship) {
        return false;
    }

    void Level::InitializeShips(int x1, int y1, int x2, int y2) {
        // Initialize enemy ships location and speed

        double xDiff = CalculateShipSpacing(x1, x2, num_ships_);
        double yDiff = CalculateShipSpacing(y1, y2, num_ships_);
        double xStart = x1 + xDiff;
        double yStart = y1 + yDiff;
        int lines = num_ships_ / per_row_;
        int extra = num_ships_ % per_row_;
        int ship_index = 0;
        int row;

        // Populate full rows of ships
        for (row = 0; row < lines; row++) {
            // check if row is even or odd
            if (row % 2 == 0) {
                // even row, go right to left
                for (int col = 0; col < per_row_; col++) {
                    Spaceship enemy(vec2(xStart + (xDiff * col), yStart + (yDiff * row)), vec2(25, 25), health_, kRadius, row);
                    enemies_[ship_index] = enemy;
                    alive_.push_back(ship_index);
                    ship_index++;
                }
            } else {
                // odd row, go left to right
                for (int col = per_row_ - 1; col >= 0; col--) {
                    Spaceship enemy(vec2(xStart + (xDiff * col), yStart + (yDiff * row)), vec2(25, 25), health_, kRadius, row);
                    enemies_[ship_index] = enemy;
                    alive_.push_back(ship_index);
                    ship_index++;
                }
            }
            // move down to next row
        }

        // Populate rows where the entire row isn't filled up
        if (row % 2 == 0) {
            // go right to left
            for (int col = 0; col < extra; col++) {
                Spaceship enemy(vec2(xStart + (xDiff * col), yStart + (yDiff * row)), vec2(25, 25), health_, kRadius);
                enemies_[ship_index] = enemy;
                alive_.push_back(ship_index);
                ship_index++;
            }
        } else {
            // go left to right
            for (int col = per_row_ - 1; col >= per_row_ - extra; col--) {
                Spaceship enemy(vec2(xStart + (xDiff * col), yStart + (yDiff * row)), vec2(25, 25), health_, kRadius);
                enemies_[ship_index] = enemy;
                alive_.push_back(ship_index);
                ship_index++;
            }
        }

    }

    double Level::CalculateShipSpacing(int x1, int x2, int num_ships) const {
        return double((x2-x1)) / (num_ships + 1);
    }

    std::vector<int> Level::GetEnemiesAlive() const {
        return alive_;
    }

    int Level::GetHealth() const {
        return health_;
    }

    int Level::GetNumShips() const {
        return num_ships_;
    }

    std::map<int, Spaceship> Level::GetEnemies() const {
        return enemies_;
    }

}
