#ifndef FINAL_PROJECT_GAMEENGINE_H
#define FINAL_PROJECT_GAMEENGINE_H

#include <Level.h>
#include <Laser.h>
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/app/App.h"
#include <random>

namespace asteroids {

    const int kIncreaseHealth = 10;
    const int kEnemyStartingHealth = 10;
    const int kNumberOfEnemyShipsStart = 5;

    const static int kTopLeftX = 50;
    const static int kTopLeftY = 50;
    const static int kBottomRightX = 1000;
    const static int kBottomRightY = 900;

    class GameEngine {

    public:
        GameEngine();

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

        std::vector<Level> GetLevels() const;

        int GetCurrentLevel() const;

        Spaceship &GetShip();

        /**
         * Checks if any laser hits any enemy ship
         * Updates enemy health and removes laser from vector if it made contact
         * If enemy health <= 0, remove enemy from vector and increase score
         */
        void LaserHitEnemy();

        /**
         * Checks if any enemy ship is at bottom of screen
         * Removes any ship that is and decreases player health
         */
        void EnemyAtBottom();

        /**
         * Finds a color for enemy ship based on its percentage of health remaining
         * @param ship to find color for
         * @return a color corresponding with health of ship
         */
        ci::Color CalculateShipColor(Spaceship &ship);


        void EnemyShootLaser();

        /**
         * Set whether game is paused or not
         */
        void ChangePauseStatus();


    private:

        int current_level_ = 0;

        Spaceship ship_;

        std::vector<Level> levels_;

        int score_multiplier_ = 1;

        bool paused_;

        bool game_over_;

        std::shared_ptr<cinder::gl::Texture2d> texture;

        ci::gl::Texture2dRef mTex;

        //ci::gl::Texture myImage = ci::gl::Texture(loadImage(ci::loadResource("assets\\spaceship.png")));
        //ci::gl::Texture texture = ci::loadImage("image.jpg");


        /**
         * Removes enemy ship from vector
         * @param location to remove vector from
         */
        void RemoveEnemyShip(int location);

        void DrawGameOverScreen();

        void DrawPauseScreen();


    };


} //namespace asteroids
#endif //FINAL_PROJECT_GAMEENGINE_H