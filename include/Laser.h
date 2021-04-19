//
// Created by Nathan on 4/18/2021.
//

#ifndef FINAL_PROJECT_LASER_H
#define FINAL_PROJECT_LASER_H

#include "cinder/gl/gl.h"
#include "Spaceship.h"

using glm::vec2;


class Laser {
public:
    Laser(vec2 startLocation, int power, int speed);

    vec2 GetLocation() const;

    int GetPower() const;

    int GetSpeed() const;

    bool CollideWithSpaceship(Spaceship& ship) const;


};


#endif //FINAL_PROJECT_LASER_H
