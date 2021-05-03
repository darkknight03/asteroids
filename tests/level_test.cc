#include <catch2/catch.hpp>
#include "Level.h"

TEST_CASE("Test Level methods") {
    asteroids::Level level(7, 5, 25);
    level.InitializeShips(50,50,550,550);

    SECTION("Check vector and map sizes") {
        REQUIRE(level.GetEnemies().size() == 7);
        REQUIRE(level.GetEnemiesAlive().size() == 7);
    }

}

