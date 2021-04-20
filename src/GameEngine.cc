#include "../include/GameEngine.h"


namespace asteroids {

    GameEngine::GameEngine(Spaceship &ship) {
        ship_ = ship;
    }

    void GameEngine::RunGame() {

    }

    void GameEngine::InitializeLevels(int number_of_levels) {
        int current_health = kEnemyStartingHealth;
        int current_number_ships = kNumberOfEnemyShipsStart;
        for (size_t l = 0; l < number_of_levels; l++) {
            Level level(current_number_ships, current_health);
            levels_.push_back(level);
            current_health += kIncreaseHealth;
            current_number_ships += 1;
        }

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

    void GameEngine::Display() const {
        // Draw game space
        ci::gl::color(ci::Color("pink"));
        ci::gl::drawStrokedRect(ci::Rectf(vec2(kTopLeftX, kTopLeftY),
                                          vec2(kBottomRightX, kBottomRightY)));


        // Draw enemy ships
        for (const int s : levels_[current_level_].GetEnemiesAlive()) {
            // Draw enemy ship
            Spaceship enemy = levels_[current_level_].GetEnemies()[s];
            ci::gl::color(ci::Color("orange"));
            ci::gl::drawSolidCircle( ci::vec2( enemy.GetLocation()), float(enemy.GetRadius()), 6 );
        }

        // Draw user controlled ship
        ci::gl::color(ci::Color("orange"));
        ci::gl::drawSolidCircle( ci::vec2( ship_.GetLocation() ), float(ship_.GetRadius()), 6 );

        // Draw health meter
        ci::gl::color(ci::Color("red"));
        ci::gl::drawStrokedRect(ci::Rectf(vec2(100.0f, 100.0f), vec2(200.0f, 200.0f)));


        // Draw scoreboard w current level
        ci::gl::color(ci::Color("pink"));
        ci::gl::drawString("Score: " + score_ + " Level: " + current_level_, vec2(100, 15),
                           ci::ColorA(25, 25, 25, 25), ci::Font("helvetica", 20));

    }

    void GameEngine::AdvanceOneFrame() {
        EnemyMove();
        UpdateScore();
        UpdateHealth();
    }

    void GameEngine::EnemyMove() {

    }

    void GameEngine::UpdateScore() {

    }

    void GameEngine::UpdateHealth() {

    }
}
