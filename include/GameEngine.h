#ifndef FINAL_PROJECT_GAMEENGINE_H
#define FINAL_PROJECT_GAMEENGINE_H

#include <Spaceship.h>
#include <Level.h>
#include <Laser.h>
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/app/App.h"

namespace asteroids {

    const int kIncreaseHealth = 5;
    const int kIncreaseVelocity = 5;
    const int kEnemyStartingHealth = 25;
    const int kNumberOfEnemyShipsStart = 5;

    class GameEngine {

    public:
        GameEngine(Spaceship& ship);

        void RunGame();

        /**
         * Initializes the levels_ vector and changes to health and number of ships
         * proportionally when changing the level
         * @param number_of_levels
         */
        void InitializeLevels(int number_of_levels);

        /**
         * Checks if all the enemy ships have been destroyed
         * @return true if all ships are gone
         */
        bool LevelOver();

        void SwitchLevel();

        std::vector<Level> GetLevels() const;

        /**
         * Display the current level with the ships on the screen
         */
        void Display() const;

        void AdvanceOneFrame();

        /**
         * Move each enemy spaceship in the vector by its velocity
         * If the ship is at the edge, move it down by adjusting its location
         */
        void EnemyMove();

        /**
         * Update score if an enemy ship is destroyed
         */
        void UpdateScore();

        /**
         * Update user health if an enemy ship reaches a certain level
         */
        void UpdateHealth();

    private:

        int current_level_ = 0;

        Spaceship ship_;

        std::vector<Level> levels_;

        std::vector<Spaceship> enemies_;

        int score_ = 0;

        //ci::gl::Texture myImage = ci::gl::Texture(loadImage(ci::app::loadResource("images\\spaceship.jpg")));;

    };


#endif //FINAL_PROJECT_GAMEENGINE_H
} //namespace asteroids