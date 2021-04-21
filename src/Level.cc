//
// Created by Nathan on 4/19/2021.
//

#include "Level.h"
//TODO: Implement CalculateShipSpacing
//TODO: Fix enemies_ to include location and speed
//TODO Implement checks for edges
namespace asteroids {

    Level::Level(int num_ships, int health) {
        num_ships_ = num_ships;
        health_ = health;

        // Initialize enemy ships location and speed
        int x_multiplier = 1;
        int y_multiplier = 1;
        int rows = num_ships / kNumOfShipsPerRow;
        int extra = num_ships % kNumOfShipsPerRow;
        for (int row = 0; row < rows; row++) {
            // check if row is even or odd
            for (int i = 0; i < kNumOfShipsPerRow; i++) {
                Spaceship enemy(vec2(kTopLeftX + (kRadius * x_multiplier), kTopLeftY), vec2(25, 25), health, kRadius);
                enemies_.at(i) = enemy;
                alive_.push_back(i);
                x_multiplier++;
            }
        }
        for (int i = 0; i < extra; i++) {
            Spaceship enemy(vec2(kTopLeftX + (kRadius * x_multiplier), kTopLeftY), vec2(25, 25), health, kRadius);
            enemies_.at(i) = enemy;
            alive_.push_back(i);
        }

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

    int Level::CalculateShipSpacing(int radius, int window_size) const {
        return (window_size - (2 * radius)) / (kNumOfShipsPerRow - 1);
    }

    std::vector<int> Level::GetEnemiesAlive() const {
        return alive_;
    }

    bool Level::IsOnLeftEdge(Spaceship &ship) {
        return false;
    }

    bool Level::IsOnRightEdge(Spaceship &ship) {
        return false;
    }

}
