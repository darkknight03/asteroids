#ifndef FINAL_PROJECT_SPACESHIP_H
#define FINAL_PROJECT_SPACESHIP_H

#include "cinder/gl/gl.h"

using glm::vec2;

namespace asteroids {

    class Spaceship {
    public:
        Spaceship(const vec2& startLocation, int health, int speed);

        vec2 GetLocation() const;

        int GetHealth() const;

        int GetSpeed() const;

        int GetScore() const;

        void ChangeScore(int score);

        void MakeMove();

        void LoseHealth(int num);

        void ShootLaser(int power, int speed);

        void SetDamage(int power);

        int GetDamage() const;

    private:
        vec2 location_;

        int health_;

        int speed_;

        int score_;

        int damage_;

    };


#endif //FINAL_PROJECT_SPACESHIP_H
} //namespace asteroids