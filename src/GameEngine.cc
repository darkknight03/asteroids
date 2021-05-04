#include "../include/GameEngine.h"


// TODO: Add ability for enemy to shoot back or some type of falling projectile

namespace asteroids {

    GameEngine::GameEngine() : ship_(vec2(500, 850), vec2(5, 0), 100, 100) {
        paused_ = false;
        game_over_ = false;
        auto img = ci::loadImage("./assets/spaceship.png");
        texture = ci::gl::Texture::create(img);

    }


    void GameEngine::InitializeLevels(int number_of_levels) {
        int current_health = kEnemyStartingHealth;
        int current_number_ships = kNumberOfEnemyShipsStart;
        for (int l = 0; l < number_of_levels; l++) {
            Level level(current_number_ships, 5, current_health);
            level.InitializeShips(kTopLeftX, kTopLeftY, kBottomRightX, kBottomRightY);
            levels_.push_back(level);
            current_health += kIncreaseHealth;
            // if level if multiple of 2, increase number of ships
            // no more than 15 ships
            if (current_number_ships < 15 && l % 2 == 0) {
                current_number_ships += 1;
            }
        }
    }

    void GameEngine::Display() {
        if (game_over_) {
            // Draw Game Over screen with user score
            DrawGameOverScreen();
        } else if (paused_) {
            // Draw paused screen
            DrawPauseScreen();
        } else {
            // Draw game space
            ci::gl::color(ci::Color("pink"));
            ci::gl::drawStrokedRect(ci::Rectf(vec2(kTopLeftX, kTopLeftY),
                                              vec2(kBottomRightX, kBottomRightY)));


            // Draw enemy ships
            for (const int s : levels_[current_level_].GetEnemiesAlive()) {
                // Draw enemy ship and lasers shot from them
                Spaceship enemy = levels_[current_level_].GetEnemies().at(s);
                ci::gl::color(CalculateShipColor(enemy));
                ci::gl::drawSolidCircle(ci::vec2(enemy.GetLocation()), float(enemy.GetRadius()), 6);
                for (const Laser &laser : enemy.GetLasers()) {
                    ci::gl::color(ci::Color(120, 0, 255));
                    ci::gl::drawSolidCircle(laser.GetLocation(), float(laser.GetRadius()));
                }
            }

            // Draw user controlled ship
            texture->bind();
            auto shader = ci::gl::ShaderDef().texture(texture).lambert();
            auto glsl = ci::gl::getStockShader(shader);
            ci::gl::color(ci::Color("blue"));
            auto circle = ci::geom::Circle().radius(float(ship_.GetRadius())).center(
                    vec2(ship_.GetLocation())).subdivisions(4);
            auto c = ci::gl::Batch::create(circle, glsl);
            ci::gl::enableDepthWrite();
            ci::gl::enableDepthRead();
            c->draw();

            //Draw Lasers
            for (const Laser &laser : ship_.GetLasers()) {
                ci::gl::color(ci::Color(90, 240, 245));
                ci::gl::drawSolidCircle(laser.GetLocation(), float(laser.GetRadius()));
            }

            // Draw health meter
            std::string health = "Health: " + std::to_string(ship_.GetHealth());
            ci::gl::color(ci::Color("red"));
            ci::gl::drawString(health, vec2(kTopLeftX + 25, kTopLeftY + 25),
                               ci::ColorA(25, 25, 25, 25), ci::Font("helvetica", 30));

            //ci::gl::drawSolidRect(ci::Rectf(vec2(kTopLeftX + 25, kTopLeftY + 25), vec2(kTopLeftX + 200, kTopLeftY + 75)));

            // Draw scoreboard w current level
            std::string score = "Score: " + std::to_string(ship_.GetScore());
            std::string level = "Level: " + std::to_string(current_level_);

            ci::gl::color(ci::Color("pink"));
            ci::gl::drawString(score, vec2(kTopLeftX + 600, kTopLeftY + 25),
                               ci::ColorA(25, 25, 25, 25), ci::Font("helvetica", 30));
            ci::gl::drawString(level, vec2(kTopLeftX + 750, kTopLeftY + 25),
                               ci::ColorA(25, 25, 25, 25), ci::Font("helvetica", 30));
        }
    }

    void GameEngine::AdvanceOneFrame() {
        // Check user health
        if (ship_.GetHealth() <= 0) {
            game_over_ = true;
        }
        // If all enemy ships have been destroyed, change level
        if (LevelOver()) {
            SwitchLevel();
        }
        // Move laser upward
        for (Laser &laser : ship_.GetLasers()) {
            laser.MakeMove();
        }
        // Check if laser hit enemy ship and update enemy health and laser vector
        LaserHitEnemy();
        // Move enemy based on location
        EnemyMove();
        // Check if enemy reaches ground
        EnemyAtBottom();


        // Each enemy ship has a 1% chance of shooting a laser downward
        /*EnemyShootLaser();
        for (const int s : levels_[current_level_].GetEnemiesAlive()) {
            Spaceship enemy = levels_[current_level_].GetEnemies().at(s);
            for (Laser &laser : enemy.GetLasers()) {
                laser.MakeMove();
            }
        }*/

    }

    void GameEngine::EnemyMove() {
        for (size_t s = 0; s < levels_[current_level_].GetEnemiesAlive().size(); s++) {
            int map_index = levels_[current_level_].GetEnemiesAlive()[s];
            Spaceship &enemy = levels_[current_level_].GetEnemies()[map_index];
            if (levels_[current_level_].IsOnRightEdge(enemy, kBottomRightX) ||
                levels_[current_level_].IsOnLeftEdge(enemy, kTopLeftX)) {
                enemy.MakeMove(2);
            } else if (levels_[current_level_].IsAtBottom(enemy, kBottomRightY)) {
                RemoveEnemyShip(s);
                ship_.LoseHealth(enemy.GetHealth());
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
                    ship_.GetLasers().erase(ship_.GetLasers().begin() + i);
                    if (enemy.GetHealth() <= 0) {
                        ship_.ChangeScore(kEnemyStartingHealth * score_multiplier_);
                        RemoveEnemyShip(s);
                    }
                }
            }
        }
    }


    bool GameEngine::LevelOver() {
        std::vector<int> alive = levels_.at(current_level_).GetEnemiesAlive();
        return alive.empty();
    }

    void GameEngine::SwitchLevel() {
        current_level_++;
        score_multiplier_++;

    }

    std::vector<Level> GameEngine::GetLevels() const {
        return levels_;
    }

    int GameEngine::GetCurrentLevel() const {
        return current_level_;
    }

    Spaceship &GameEngine::GetShip() {
        return ship_;
    }

    void GameEngine::RemoveEnemyShip(int location) {
        std::vector<int> &enemies = levels_[current_level_].GetEnemiesAlive();
        enemies.erase(enemies.begin() + location);
    }

    void GameEngine::EnemyAtBottom() {
        for (size_t s = 0; s < levels_[current_level_].GetEnemiesAlive().size(); s++) {
            int map_index = levels_[current_level_].GetEnemiesAlive()[s];
            Spaceship &enemy = levels_[current_level_].GetEnemies()[map_index];
            if (levels_[current_level_].IsAtBottom(enemy, kBottomRightY)) {
                RemoveEnemyShip(s);
                ship_.LoseHealth(enemy.GetHealth());
            }
        }
    }


    ci::Color GameEngine::CalculateShipColor(Spaceship &ship) {
        float percentage = ship.CalculatePercentageHealth();
        if (percentage > 0.75) {
            return ci::Color("Green");
        } else if (percentage > 0.5) {
            return ci::Color("Yellow");
        } else if (percentage > 0.25) {
            return ci::Color("Orange");
        } else if (percentage > 0.10) {
            return ci::Color("Red");
        } else {
            return ci::Color(115, 30, 50);
        }
    }

    void GameEngine::EnemyShootLaser() {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<> dist(0, 10000);
        for (size_t s = 0; s < levels_[current_level_].GetEnemiesAlive().size(); s++) {
            int map_index = levels_[current_level_].GetEnemiesAlive()[s];
            Spaceship &enemy = levels_[current_level_].GetEnemies()[map_index];
            if (dist(mt) < 10) {
                enemy.MakeMove(4);
            }
        }

    }

    void GameEngine::ChangePauseStatus() {
        paused_ = !paused_;
    }

    void GameEngine::DrawGameOverScreen() {
        std::string score = "Score: " + std::to_string(ship_.GetScore());
        ci::gl::color(ci::Color("Red"));
        ci::gl::drawStrokedRect(ci::Rectf(vec2(kTopLeftX, kTopLeftY),
                                          vec2(kBottomRightX, kBottomRightY)));


        ci::gl::drawString("Game Over", vec2(kTopLeftX + ((kTopLeftX + kBottomRightX) / 3),
                                             kTopLeftY + ((kTopLeftY + kBottomRightY) / 3)),
                           ci::ColorA(100, 100, 100, 100), ci::Font("helvetica", 75));

        ci::gl::drawString(score, vec2(kTopLeftX + ((kTopLeftX + kBottomRightX) / 3),
                                       kTopLeftY + ((kTopLeftY + kBottomRightY) / 3) + 150),
                           ci::ColorA(25, 25, 25, 25), ci::Font("helvetica", 30));
    }

    void GameEngine::DrawPauseScreen() {
        ci::gl::color(ci::Color("blue"));
        ci::gl::drawStrokedRect(ci::Rectf(vec2(kTopLeftX, kTopLeftY),
                                          vec2(kBottomRightX, kBottomRightY)));
        ci::gl::drawString("Paused", vec2(kTopLeftX + ((kTopLeftX + kBottomRightX) / 3),
                                          kTopLeftY + ((kTopLeftY + kBottomRightY) / 3)),
                           ci::ColorA(100, 100, 100, 25), ci::Font("helvetica", 75));
    }


}
