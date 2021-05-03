#include <catch2/catch.hpp>
#include "Spaceship.h"

TEST_CASE("Test Spaceship methods") {
    asteroids::Spaceship ship(vec2(100,100), vec2(25,10),50, 25);

    SECTION("Test Getter Methods") {
        REQUIRE(ship.GetRadius() == 25);
        REQUIRE(ship.GetLocation().x == Approx(100).epsilon(0.1));
        REQUIRE(ship.GetLocation().y == Approx(100).epsilon(0.1));
        REQUIRE(ship.GetVelocity().x == Approx(25).epsilon(0.1));
        REQUIRE(ship.GetVelocity().y == Approx(10).epsilon(0.1));
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
        REQUIRE(ship.GetLocation().x == Approx(125).epsilon(0.1));
        REQUIRE(ship.GetLocation().y == Approx(100).epsilon(0.1));
        ship.MakeMove(2);
        REQUIRE(ship.GetLocation().x == Approx(125).epsilon(0.1));
        REQUIRE(ship.GetLocation().y == Approx(110).epsilon(0.1));
    }

    SECTION("Test Enemy Colors") {
        ship.LoseHealth(25);
        REQUIRE(ship.CalculatePercentageHealth() == 0.5f);
    }

    SECTION("Test Laser") {
        // Not Implemented
    }
}

