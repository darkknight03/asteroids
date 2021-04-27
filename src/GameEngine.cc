#include "../include/GameEngine.h"

// TODO: Decrease health when laser hits ship
// TODO: Decrease health when ship reaches bottom of screen
// TODO: Add Image as ship
// TODO: Shade of enemy ship depends on health

namespace asteroids {

    GameEngine::GameEngine() : ship_(vec2(500, 850), vec2(5, 0), 100, 50) { }

    void GameEngine::RunGame() {}

    void GameEngine::InitializeLevels(int number_of_levels) {
        int current_health = kEnemyStartingHealth;
        int current_number_ships = kNumberOfEnemyShipsStart;
        for (int l = 0; l < number_of_levels; l++) {
            Level level(current_number_ships, 5, current_health);
            level.InitializeShips(kTopLeftX, kTopLeftY, kBottomRightX, kBottomRightY);
            levels_.push_back(level);
            current_health += kIncreaseHealth;
            // TODO: check if level if multiple of 3, then increase
            current_number_ships += 1;
        }
    }

    void GameEngine::Display()  {
        // Draw game space
        ci::gl::color(ci::Color("pink"));
        ci::gl::drawStrokedRect(ci::Rectf(vec2(kTopLeftX, kTopLeftY),
                                          vec2(kBottomRightX, kBottomRightY)));


        // Draw enemy ships
        for (const int s : levels_[current_level_].GetEnemiesAlive()) {
            // Draw enemy ship
            Spaceship enemy = levels_[current_level_].GetEnemies().at(s);
            ci::gl::color(ci::Color("orange"));
            ci::gl::drawSolidCircle(ci::vec2(enemy.GetLocation()), float(enemy.GetRadius()), 6);
        }

        // Draw user controlled ship
        ci::gl::color(ci::Color("green"));
        ci::gl::drawSolidCircle(ci::vec2(ship_.GetLocation()), float(ship_.GetRadius()), 3);

        //Draw Lasers
        for (const Laser& laser : ship_.GetLasers()) {
            ci::gl::color(ci::Color(58,26,229));
            ci::gl::drawSolidCircle(laser.GetLocation(), float(laser.GetRadius()));
        }

        // Draw health meter
        ci::gl::color(ci::Color("red"));
        ci::gl::drawSolidRect(ci::Rectf(vec2(kTopLeftX + 25, kTopLeftY + 25), vec2(kTopLeftX + 200, kTopLeftY + 75)));

        // Draw scoreboard w current level
        std::string score = "Score: " + std::to_string(ship_.GetScore());
        std::string level = "Level: " + std::to_string(current_level_);

        ci::gl::color(ci::Color("pink"));
        ci::gl::drawString(score, vec2(kTopLeftX + 600, kTopLeftY + 25),
                           ci::ColorA(25, 25, 25, 25), ci::Font("helvetica", 30));
        ci::gl::drawString(level, vec2(kTopLeftX + 750, kTopLeftY + 25),
                           ci::ColorA(25, 25, 25, 25), ci::Font("helvetica", 30));

    }

    void GameEngine::AdvanceOneFrame() {
        // Check is all enemy ships have been destroyed
        // Change level
        if (LevelOver()) {
            SwitchLevel();
        }
        // Move laser upward
        for (Laser& laser : ship_.GetLasers()) {
            laser.MakeMove();
        }
        // Check if laser hit enemy ship and update enemy health and laser vector
        LaserHitEnemy();
        EnemyMove();
        UpdateHealth();
    }

    void GameEngine::EnemyMove() {
        for (const int s : levels_[current_level_].GetEnemiesAlive()) {
            Spaceship& enemy = levels_[current_level_].GetEnemies()[s];

            if (levels_[current_level_].IsOnRightEdge(enemy, kBottomRightX) ||
                levels_[current_level_].IsOnLeftEdge(enemy, kTopLeftX)) {
                enemy.MakeMove(2);
            }
            enemy.MakeMove(3);
        }
    }

    void GameEngine::LaserHitEnemy() {
        for (size_t s = 0; s < levels_[current_level_].GetEnemiesAlive().size(); s++) {
            int map_index = levels_[current_level_].GetEnemiesAlive()[s];
            Spaceship &enemy = levels_[current_level_].GetEnemies()[map_index];
            for (size_t i = 0; i < ship_.GetLasers().size(); i++) {
                if (enemy.CollideWithLaser(ship_.GetLasers()[i])) {
                    // if laser hits enemy, decrease enemy health and remove laser from vector
                    enemy.LoseHealth(ship_.GetLasers()[i].GetPower());
                    ship_.GetLasers().erase(ship_.GetLasers().begin()+i);
                    if (enemy.GetHealth() <= 0) {
                        ship_.ChangeScore(500);
                        RemoveEnemyShip(s);
                    }
                }
            }
        }
    }

    void GameEngine::UpdateHealth() {
        // check if enemy reaches bottom of screen
        // reduce health by amount of enemy health remaining
    }

    bool GameEngine::LevelOver() {
        std::vector<int> alive = levels_.at(current_level_).GetEnemiesAlive();
        return alive.empty();
    }

    void GameEngine::SwitchLevel() {
        current_level_++;
    }

    std::vector<Level> GameEngine::GetLevels() const {
        return levels_;
    }

    int GameEngine::GetCurrentLevel() const {
        return current_level_;
    }

    Spaceship& GameEngine::GetShip() {
        return ship_;
    }

    void GameEngine::RemoveEnemyShip(int location) {
        std::vector<int>& enemies = levels_[current_level_].GetEnemiesAlive();
        enemies.erase(enemies.begin() + location);
    }


}
