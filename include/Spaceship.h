#ifndef FINAL_PROJECT_SPACESHIP_H
#define FINAL_PROJECT_SPACESHIP_H

#include "cinder/gl/gl.h"
#include "Laser.h"
#include "vector"

using glm::vec2;

namespace asteroids {

    class Spaceship {
        static const int kLaserRadius = 10;

    public:
        Spaceship(const vec2 &startLocation, const vec2 &speed, int health, int radius);

        Spaceship(const vec2 &startLocation, const vec2 &speed, int health, int radius, int row);

        Spaceship();

        void SetRow(int row);

        void SetDamage(int power);

        void SetLocation(const vec2& location);

        void ChangeScore(int score);

        /**
         * Move right, left, down, or shoot laser
         * @param m determines which move to make
         */
        void MakeMove(int m);

        /**
         * Decrease health
         * @param num to decrease health by
         */
        void LoseHealth(int num);

        /**
         * Create a laser from center of ship
         * @param power starting power
         * @param speed of laser
         */
        void ShootLaser(int power, const vec2 &speed);

        vec2 GetLocation() const;

        int GetHealth() const;

        vec2 GetVelocity() const;

        int GetScore() const;

        int GetDamage() const;

        int GetRadius() const;

        int GetRow() const;

        std::vector<Laser> &GetLasers();

        /**
         * Checks if laser hits ship
         */
        bool CollideWithLaser(Laser& laser) const;

        /**
         * Calculates how much health a ship has left
         * @return
         */
        float CalculatePercentageHealth() const;

    private:
        vec2 location_;

        int health_;

        int starting_health_;

        vec2 velocity_;

        int score_ = 0;

        int damage_ = 0;

        int radius_;

        int row_;

        std::vector<Laser> lasers_;

    };


} //namespace asteroids
#endif //FINAL_PROJECT_SPACESHIP_H