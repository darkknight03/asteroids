#ifndef FINAL_PROJECT_LASER_H
#define FINAL_PROJECT_LASER_H

#include "cinder/gl/gl.h"
#include "Spaceship.h"

using glm::vec2;

namespace asteroids {

    class Laser {
    public:
        Laser(const vec2 &startLocation, const vec2& speed, int power, int radius);

        vec2 GetLocation() const;

        int GetPower() const;

        vec2 GetVelocity() const;

        int GetRadius() const;

        bool CollideWithSpaceship(Spaceship &ship) const;

        void MakeMove();

    private:
        vec2 location_;

        int power_;

        vec2 velocity_;

        int radius_;

    };


#endif //FINAL_PROJECT_LASER_H
} //namespace asteroids