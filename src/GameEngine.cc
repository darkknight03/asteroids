#include "../include/GameEngine.h"


namespace asteroids {

    GameEngine::GameEngine(Spaceship &ship) : ship_(ship) {}

    void GameEngine::RunGame() {}

    void GameEngine::InitializeLevels(int number_of_levels) {
        int current_health = kEnemyStartingHealth;
        int current_number_ships = kNumberOfEnemyShipsStart;
        for (int l = 0; l < number_of_levels; l++) {
            Level level(current_number_ships, 5, current_health);
            level.InitializeShips(kTopLeftX, kTopLeftY, kBottomRightX, kBottomRightY);
            levels_.push_back(level);
            current_health += kIncreaseHealth;
            // TODO: check if level if multiple of 5, then increase
            current_number_ships += 1;
        }

    }

    void GameEngine::Display() const {
        // Draw game space
        ci::gl::color(ci::Color("pink"));
        ci::gl::drawStrokedRect(ci::Rectf(vec2(kTopLeftX, kTopLeftY),
                                          vec2(kBottomRightX, kBottomRightY)));


        // Draw enemy ships
        for (const int s : levels_[current_level_].GetEnemiesAlive()) {
            // Draw enemy ship
            Spaceship enemy = levels_[current_level_].GetEnemies().at(s);
            ci::gl::color(ci::Color("orange"));
            ci::gl::drawSolidCircle( ci::vec2( enemy.GetLocation()), float(enemy.GetRadius()), 6);
        }

        // Draw user controlled ship
        ci::gl::color(ci::Color("orange"));
        ci::gl::drawSolidCircle( ci::vec2( ship_.GetLocation() ), float(ship_.GetRadius()), 6);

        // Draw health meter
        //ci::gl::color(ci::Color("red"));
        //ci::gl::drawStrokedRect(ci::Rectf(vec2(100.0f, 100.0f), vec2(200.0f, 200.0f)));


        // Draw scoreboard w current level
        //ci::gl::color(ci::Color("pink"));
        //ci::gl::drawString("Score: " + score_ + " Level: " + current_level_, vec2(100, 15),
                           //ci::ColorA(25, 25, 25, 25), ci::Font("helvetica", 20));

    }

    void GameEngine::AdvanceOneFrame() {
        if (LevelOver()) {
            SwitchLevel();
        }
        EnemyMove();
        UpdateScore();
        UpdateHealth();
    }

    void GameEngine::EnemyMove() {
        // move each enemy spaceship once by its velocity and updating its position
        std::map<int, Spaceship> enemies = levels_[current_level_].GetEnemies();
        for (const int x : levels_[current_level_].GetEnemiesAlive()) {
            Spaceship enemy = enemies.at(x);
            // check position of enemy
            // move right, left, or down depending on location
            if (levels_[current_level_].IsOnRightEdge(enemy) || levels_[current_level_].IsOnLeftEdge(enemy)) {
                enemy.MakeMove(2);
            }
            // if enemy on even row, move right
            // if enemy on odd row, move left
            if (enemy.GetRow() % 2 == 0) {
                enemy.MakeMove(1);
            } else {
                enemy.MakeMove(0);
            }
        }

    }

    void GameEngine::UpdateScore() {
        // check if enemy was destroyed
        // increase score by health of enemy times 10
    }

    void GameEngine::UpdateHealth() {
        // check if enemy reaches bottom of screen
        // reduce health by amount of enemy health remaining
    }

    std::vector<Level> GameEngine::GetLevels() const {
        return levels_;
    }

    bool GameEngine::LevelOver() {
        std::vector<int> alive = levels_.at(current_level_).GetEnemiesAlive();
        return alive.empty();
    }

    void GameEngine::SwitchLevel() {
        current_level_++;
    }

}
