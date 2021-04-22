#include "../include/Spaceship.h"
#include "../include/Laser.h"

namespace asteroids {

    Spaceship::Spaceship(const vec2& startLocation, const vec2& speed, int health, int radius) {
        location_ = startLocation;
        health_ = health;
        velocity_ = speed;
        radius_ = radius;
    }

    Spaceship::Spaceship(const vec2 &startLocation, const vec2 &speed, int health, int radius, int row) {
        location_ = startLocation;
        velocity_ = speed;
        health_ = health;
        radius_ = radius;
        row_ = row;
    }


    void Spaceship::MakeMove(int m) {
        // move left
        if (m == 0) {
            location_.x -= velocity_.x;
        } else if (m == 1) {
            // move right
            location_.x += velocity_.x;
        } else if (m == 2) {
            // move down
            location_.y -= velocity_.y;
        } else {
            // shoot laser
            ShootLaser(50, vec2(10,10));
        }
    }

    void Spaceship::EnemyMove() {
        // check where ship is based on game area
        // if at right end of game area and moving right, move down
        // if at left end of game area and moving left, move down
        // if row is even, move right
        // if row is odd, move left
    }

    void Spaceship::LoseHealth(int num) {
        health_ -= num;
    }

    void Spaceship::ShootLaser(int power, const vec2& speed) {
        // Not Implemented
        Laser laser(location_, speed, power, kLaserRadius);
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

    int Spaceship::GetScore() const {
        return score_;
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

    int Spaceship::GetRadius() const {
        return radius_;
    }

    int Spaceship::GetRow() const {
        return row_;
    }

    void Spaceship::SetRow(int row) {
        row_ = row;
    }

    Spaceship::Spaceship() = default;
}
