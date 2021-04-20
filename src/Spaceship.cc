#include "../include/Spaceship.h"
#include "../include/Laser.h"

namespace asteroids {

    Spaceship::Spaceship(const vec2& startLocation, const vec2& speed, int health, int radius) {
        location_ = startLocation;
        health_ = health;
        velocity_ = speed;
        radius_ = radius;
    }

    Spaceship::Spaceship(int health, int radius) {
        health_ = health;
        radius_ = radius;
    }

    vec2 Spaceship::GetLocation() const {
        return location_;
    }

    int Spaceship::GetHealth() const {
        return health_;
    }

    vec2 Spaceship::GetVelocity() const {
        return velocity_;
    }

    void Spaceship::MakeMove(int m) {
        // move left
        if (m == 0) {
            location_.x -= velocity_.x;
        } else {
            // move right
            location_.x += velocity_.x;
        }
    }

    void Spaceship::LoseHealth(int num) {
        health_ -= num;
    }

    void Spaceship::ShootLaser(int power, vec2& speed) {
        // Not Implemented
        Laser laser(location_, speed, power, kLaserRadius);
    }

    int Spaceship::GetScore() const {
        return score_;
    }

    void Spaceship::ChangeScore(int score) {
        score_ += score;
    }

    void Spaceship::SetDamage(int power) {
        damage_ = power;
    }

    int Spaceship::GetDamage() const {
        return damage_;
    }

    void Spaceship::SetLocation(vec2& location) {
        location_ = location;
    }

    void Spaceship::SetVelocity(vec2& velocity) {
        velocity_ = velocity;
    }

    Spaceship::Spaceship() { }


}
