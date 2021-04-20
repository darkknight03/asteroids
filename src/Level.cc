//
// Created by Nathan on 4/19/2021.
//

#include "Level.h"
//TODO: Implement CalculateShipSpacing
//TODO: Fix enemies_ to include location and speed
namespace asteroids {

    Level::Level(int num_ships, int health) {
        num_ships_ = num_ships;
        health_ = health;
        for (int i = 0; i < num_ships; i++) {
            Spaceship enemy(vec2(0,0), vec2(0,0), health, 0);
            enemies_[i] = enemy;
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

    int Level::CalculateShipSpacing(int radius, int window_size) {
        // Not Implemented
    }

    std::vector<int> Level::GetEnemiesAlive() const {
        return alive_;
    }

    void Level::Display() const {


        ci::gl::color(ci::Color("pink"));
        ci::gl::drawStrokedRect(ci::Rectf(vec2(kTopLeftX, kTopLeftY),
                                          vec2(kBottomRightX, kBottomRightY)));

    }

    void Level::AdvanceOneFrame() {

    }
}
