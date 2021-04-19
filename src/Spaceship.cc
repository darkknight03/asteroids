#include "../include/Spaceship.h"

namespace asteroids {

    Spaceship::Spaceship(const vec2& startLocation, int health, int speed) {
        location_ = startLocation;
        health_ = health;
        speed_ = speed;
    }

    vec2 Spaceship::GetLocation() const {
        return location_;
    }

    int Spaceship::GetHealth() const {
        return health_;
    }

    int Spaceship::GetSpeed() const {
        return speed_;
    }

    void Spaceship::MakeMove() {

    }

    void Spaceship::LoseHealth(int num) {
        health_ -= num;
    }

    void Spaceship::ShootLaser(int power, int speed) {

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

}
