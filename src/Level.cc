//
// Created by Nathan on 4/19/2021.
//

#include "Level.h"

namespace asteroids {

    Level::Level(int num_ships, int health) {
        num_ships_ = num_ships;
        health_ = health;
        for (size_t i = 0; i < num_ships; i++) {
            Spaceship enemy(vec2(0,0), vec2(0,0), health, 0);
            enemies_.push_back(enemy);
        }

    }

    int Level::GetHealth() const {
        return health_;
    }

    int Level::GetNumShips() const {
        return num_ships_;
    }

    std::vector<Spaceship> Level::GetEnemies() const {
        return enemies_;
    }

    int Level::CalculateShipSpacing(int num, int window_size) {

    }
}
