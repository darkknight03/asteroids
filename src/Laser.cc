#include "../include/Laser.h"

namespace asteroids {

    Laser::Laser(const vec2 &startLocation, const vec2& speed, int power, int radius) {
        location_ = startLocation;
        power_ = power;
        velocity_ = speed;
        radius_ = radius;
    }

    vec2 Laser::GetLocation() const {
        return location_;
    }

    int Laser::GetPower() const {
        return power_;
    }

    int Laser::GetRadius() const {
        return radius_;
    }

    void Laser::MakeMove() {
        location_ += velocity_;
    }
}
