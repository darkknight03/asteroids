//
// Created by Nathan on 4/18/2021.
//

#include "../include/Laser.h"

Laser::Laser(vec2 startLocation, int power, int speed) {

}

vec2 Laser::GetLocation() const {
    return glm::vec2();
}

int Laser::GetPower() const {
    return 0;
}

int Laser::GetSpeed() const {
    return 0;
}

bool Laser::CollideWithSpaceship(Spaceship &ship) const {
    return false;
}
