#ifndef FINAL_PROJECT_SPACESHIP_H
#define FINAL_PROJECT_SPACESHIP_H

#include "cinder/gl/gl.h"
#include "Laser.h"
#include "vector"

using glm::vec2;

namespace asteroids {

    class Spaceship {
        static const int kLaserRadius = 3;

    public:
        Spaceship(const vec2 &startLocation, const vec2 &speed, int health, int radius);

        Spaceship(const vec2 &startLocation, const vec2 &speed, int health, int radius, int row);

        Spaceship();

        void SetRow(int row);

        void SetDamage(int power);

        void ChangeScore(int score);

        void MakeMove(int m);

        void LoseHealth(int num);

        void ShootLaser(int power, const vec2 &speed);

        vec2 GetLocation() const;

        int GetHealth() const;

        vec2 GetVelocity() const;

        int GetScore() const;

        int GetDamage() const;

        int GetRadius() const;

        int GetRow() const;

        std::vector<Laser> &GetLasers();

    private:
        vec2 location_;

        int health_;

        vec2 velocity_;

        int score_ = 0;

        int damage_ = 0;

        int radius_;

        int row_;

        std::vector<Laser> lasers_;

    };


} //namespace asteroids
#endif //FINAL_PROJECT_SPACESHIP_H