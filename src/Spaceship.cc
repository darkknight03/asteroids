#include "../include/Spaceship.h"
#include "../include/Laser.h"

namespace asteroids {

    Spaceship::Spaceship(const vec2& startLocation, const vec2& speed, int health, int radius) {
        location_ = startLocation;
        health_ = health;
        velocity_ = speed;
        radius_ = radius;
        starting_health_ = health_;
    }

    Spaceship::Spaceship(const vec2 &startLocation, const vec2 &speed, int health, int radius, int row) {
        location_ = startLocation;
        velocity_ = speed;
        health_ = health;
        radius_ = radius;
        row_ = row;
        starting_health_ = health_;
    }


    void Spaceship::MakeMove(int m) {
        // move right
        if (m == 0) {
            location_.x += velocity_.x;
        } else if (m == 1) {
            // move left
            location_.x -= velocity_.x;
        } else if (m == 2) {
            // move down
            location_.y += velocity_.y;
            row_++;
            velocity_.x *= -1;
        } else if (m == 3) {
            // move enemy ship both directions
            // Velocity will be positive or negative depending on which row its on
            location_.x += velocity_.x;
        } else if (m == 4) {
            // shoot enemy laser
            ShootLaser(5, vec2(0,10));
        } else {
            // shoot laser
            ShootLaser(10, vec2(0,-10));
        }
    }

    void Spaceship::LoseHealth(int num) {
        health_ -= num;
    }

    void Spaceship::ShootLaser(int power, const vec2& speed) {
        Laser laser(location_, speed, power, kLaserRadius);
        lasers_.push_back(laser);
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

    std::vector<Laser> &Spaceship::GetLasers() {
        return lasers_;
    }

    bool Spaceship::CollideWithLaser(Laser &laser) const{
        return (glm::distance(laser.GetLocation(), GetLocation()) <=
                laser.GetRadius() + GetRadius());
    }

    void Spaceship::SetLocation(const vec2& location) {
        location_ = location;
    }

    float Spaceship::CalculatePercentageHealth() const{
        return float(health_) / float(starting_health_);
    }


    Spaceship::Spaceship() = default;
}
