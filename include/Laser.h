#ifndef FINAL_PROJECT_LASER_H
#define FINAL_PROJECT_LASER_H

#include "cinder/gl/gl.h"
#include "Spaceship.h"

using glm::vec2;

namespace asteroids {

    class Laser {
    public:
        Laser(const vec2 &startLocation, int power, int speed, int radius);

        vec2 GetLocation() const;

        int GetPower() const;

        int GetSpeed() const;

        int GetRadius() const;

        bool CollideWithSpaceship(Spaceship &ship) const;

    private:
        vec2 location_;

        int power_;

        int speed_;

        int radius_;

    };


#endif //FINAL_PROJECT_LASER_H
} //namespace asteroids