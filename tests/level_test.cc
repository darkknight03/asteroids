#include <catch2/catch.hpp>
#include "Level.h"

TEST_CASE("Test Level methods") {
    asteroids::Level level(7, 5, 25);
    level.InitializeShips(50,50,550,550);

    SECTION("Check vector and map sizes") {
        REQUIRE(level.GetEnemies().size() == 7);
        REQUIRE(level.GetEnemiesAlive().size() == 7);
    }

    SECTION("Check ships' initial position") {
        REQUIRE(level.GetEnemies().at(0).GetLocation() == vec2(112.5,112.5));
        REQUIRE(level.GetEnemies().at(1).GetLocation() == vec2(175,112.5));
        REQUIRE(level.GetEnemies().at(2).GetLocation() == vec2(237.5,112.5));
        REQUIRE(level.GetEnemies().at(3).GetLocation() == vec2(300,112.5));
        REQUIRE(level.GetEnemies().at(4).GetLocation() == vec2(362.5,112.5));
        REQUIRE(level.GetEnemies().at(5).GetLocation() == vec2(362.5,175));
        REQUIRE(level.GetEnemies().at(6).GetLocation() == vec2(300,175));
    }

    SECTION("Edge Testing") {
        // Not implemented
    }

}

