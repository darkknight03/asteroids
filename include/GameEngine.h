#ifndef FINAL_PROJECT_GAMEENGINE_H
#define FINAL_PROJECT_GAMEENGINE_H

#include <Level.h>
#include <Laser.h>
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/app/App.h"

namespace asteroids {

    const int kIncreaseHealth = 5;
    const int kIncreaseVelocity = 1;
    const int kEnemyStartingHealth = 25;
    const int kNumberOfEnemyShipsStart = 5;

    const static int kTopLeftX = 50;
    const static int kTopLeftY = 50;
    const static int kBottomRightX = 1000;
    const static int kBottomRightY = 900;

    class GameEngine {

    public:
        GameEngine(Spaceship& ship);

        GameEngine();

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

        /**
         * Display the current level with the ships on the screen
         */
        void Display();

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

        std::vector<Level> GetLevels() const;

        int GetCurrentLevel() const;

        Spaceship& GetShip();

    private:

        int current_level_ = 0;

        Spaceship ship_;

        std::vector<Level> levels_;

        int score_ = 0;

        //ci::gl::Texture myImage = ci::gl::Texture(loadImage(ci::app::loadResource("images\\spaceship.jpg")));;

    };


} //namespace asteroids
#endif //FINAL_PROJECT_GAMEENGINE_H