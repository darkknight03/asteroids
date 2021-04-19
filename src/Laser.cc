#include "../include/Laser.h"

namespace asteroids {

    Laser::Laser(const vec2 &startLocation, int power, int speed, int radius) {
        location_ = startLocation;
        power_ = power;
        speed_ = speed;
        radius_ = radius;
    }

    vec2 Laser::GetLocation() const {
        return location_;
    }

    int Laser::GetPower() const {
        return power_;
    }

    int Laser::GetSpeed() const {
        return speed_;
    }

    bool Laser::CollideWithSpaceship(Spaceship &ship) const {
        vec2 loc = ship.GetLocation();

        return false;
    }

    int Laser::GetRadius() const {
        return radius_;
    }
}
