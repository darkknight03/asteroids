#ifndef FINAL_PROJECT_SPACESHIP_H
#define FINAL_PROJECT_SPACESHIP_H

#include "cinder/gl/gl.h"

using glm::vec2;

namespace asteroids {

    class Spaceship {
        static const int kLaserRadius = 1;

    public:
        Spaceship(const vec2 &startLocation, const vec2 &speed, int health, int radius);

        Spaceship(int health, int radius);

        void SetLocation(vec2 &location);

        void SetVelocity(vec2 &velocity);

        void SetDamage(int power);

        void ChangeScore(int score);

        void MakeMove(int m);

        void EnemyMove();

        void LoseHealth(int num);

        void ShootLaser(int power, const vec2 &speed);

        vec2 GetLocation() const;

        int GetHealth() const;

        vec2 GetVelocity() const;

        int GetScore() const;

        int GetDamage() const;

        int GetRadius() const;

    private:
        vec2 location_;

        int health_;

        vec2 velocity_;

        int score_;

        int damage_;

        int radius_;

    };


} //namespace asteroids
#endif //FINAL_PROJECT_SPACESHIP_H