#ifndef FINAL_PROJECT_SPACESHIP_H
#define FINAL_PROJECT_SPACESHIP_H

#include "cinder/gl/gl.h"

using glm::vec2;

namespace asteroids {

    static const int kLaserRadius = 1;

    class Spaceship {
    public:
        Spaceship(const vec2& startLocation, const vec2& speed, int health, int radius);

        vec2 GetLocation() const;

        int GetHealth() const;

        vec2 GetVelocity() const;

        int GetScore() const;

        void ChangeScore(int score);

        void MakeMove(int m);

        void LoseHealth(int num);

        void ShootLaser(int power, vec2& speed);

        void SetDamage(int power);

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


#endif //FINAL_PROJECT_SPACESHIP_H
} //namespace asteroids