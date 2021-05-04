#include "Level.h"

namespace asteroids {

    Level::Level(int num_ships, int per_row, int health) {
        num_ships_ = num_ships;
        health_ = health;
        per_row_ = per_row;
    }

    bool Level::IsOnLeftEdge(Spaceship &ship, int xEdge) {
        return (ship.GetLocation().x <= xEdge + (ship.GetRadius() * 2)) && ship.GetVelocity().x < 0;
    }

    bool Level::IsOnRightEdge(Spaceship &ship, int xEdge) {
        return (ship.GetLocation().x >= xEdge - (ship.GetRadius() * 2)) && ship.GetVelocity().x > 0;
    }

    bool Level::IsAtBottom(Spaceship &ship, int bottom) {
        return (ship.GetLocation().y >= bottom - (ship.GetRadius() * 2));
    }

    void Level::InitializeShips(int x1, int y1, int x2, int y2) {
        // Initialize enemy ships location and speed

        double xDiff = CalculateShipSpacing(x1, x2, per_row_);
        double yDiff = CalculateShipSpacing(y1, y2, per_row_);
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
                    Spaceship enemy(vec2(xStart + (xDiff * col), yStart + (yDiff * row)), vec2(1, yDiff), health_,
                                    kRadius, row);
                    enemies_[ship_index] = enemy;
                    alive_.push_back(ship_index);
                    ship_index++;
                }
            } else {
                // odd row, go left to right
                for (int col = per_row_ - 1; col >= 0; col--) {
                    Spaceship enemy(vec2(xStart + (xDiff * col), yStart + (yDiff * row)), vec2(-1, yDiff), health_,
                                    kRadius, row);
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
                Spaceship enemy(vec2(xStart + (xDiff * col), yStart + (yDiff * row)), vec2(1, yDiff), health_, kRadius,
                                row);
                enemies_[ship_index] = enemy;
                alive_.push_back(ship_index);
                ship_index++;
            }
        } else {
            // go left to right
            for (int col = per_row_ - 1; col >= per_row_ - extra; col--) {
                Spaceship enemy(vec2(xStart + (xDiff * col), yStart + (yDiff * row)), vec2(-1, yDiff), health_, kRadius,
                                row);
                enemies_[ship_index] = enemy;
                alive_.push_back(ship_index);
                ship_index++;
            }
        }
    }

    double Level::CalculateShipSpacing(int x1, int x2, int num_ships) const {
        return double((x2 - x1)) / (num_ships + 1);
    }

    std::vector<int> &Level::GetEnemiesAlive() {
        return alive_;
    }

    int Level::GetHealth() const {
        return health_;
    }

    int Level::GetNumShips() const {
        return num_ships_;
    }

    std::map<int, Spaceship> &Level::GetEnemies() {
        return enemies_;
    }

    std::vector<Laser> &Level::GetLasers() {
        return lasers_;
    }

    void Level::InitializeFallingProjectiles(int x1, int y1, int x2, int y2, int level) {
        for (int i = 0; i < level + 1; i++) {
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_int_distribution<> dist_x(x1, x2);
            std::uniform_int_distribution<> dist_speed(0, 5);
            // number of lasers also based on level
            Laser laser(vec2(dist_x(mt), y1), vec2(0, dist_speed(mt)), 10, 10);
            lasers_.push_back(laser);
        }

    }

}
