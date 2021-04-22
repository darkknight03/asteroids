#include <catch2/catch.hpp>
#include "Spaceship.h"

TEST_CASE("Test Spaceship methods") {
    asteroids::Spaceship ship(vec2(100,100), vec2(25,10),50, 25);

    SECTION("Test Getter Methods") {
        REQUIRE(ship.GetRadius() == 25);
        REQUIRE((ship.GetLocation() == vec2(100,100)));
        REQUIRE(ship.GetVelocity() == vec2(25,10));
    }

    SECTION("Test Row Setter") {
        ship.SetRow(2);
        REQUIRE(ship.GetRow() == 2);
    }

    SECTION("Test Damage Setter") {
        ship.SetDamage(15);
        REQUIRE(ship.GetDamage() == 15);
    }

    SECTION("Test Health") {
        REQUIRE(ship.GetHealth() == 50);
        ship.LoseHealth(10);
        REQUIRE(ship.GetHealth() == 40);
    }

    SECTION("Test Movement") {
        ship.MakeMove(0);
        REQUIRE(ship.GetLocation() == vec2(75,100));
        ship.MakeMove(2);
        REQUIRE(ship.GetLocation() == vec2(75,90));
    }

    SECTION("Test Laser") {
        // Not Implemented
    }
}

