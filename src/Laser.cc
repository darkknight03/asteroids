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

    vec2 Laser::GetVelocity() const {
        return velocity_;
    }

    /*bool Laser::CollideWithSpaceship(Spaceship &ship) {
        float moving_toward = glm::dot((GetVelocity() - ship.GetVelocity()),
                                       (GetLocation() - ship.GetLocation()));
        return (glm::distance(GetLocation(), ship.GetLocation()) <=
                GetRadius() + ship.GetRadius() && moving_toward < 0);
    }*/

    int Laser::GetRadius() const {
        return radius_;
    }

    void Laser::MakeMove() {
        location_ += velocity_;
    }
}
