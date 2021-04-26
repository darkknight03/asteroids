#include <catch2/catch.hpp>
#include "GameEngine.h"

TEST_CASE("Test GameEngine") {
    // Number of ships starting is 3
    asteroids::Spaceship ship(vec2(500, 850), vec2(50, 0), 100, 50);
    asteroids::GameEngine engine(ship);
    engine.InitializeLevels(1);
    asteroids::Level level = engine.GetLevels()[engine.GetCurrentLevel()];

    SECTION("Test Initial Locations of Enemies") {
        REQUIRE(level.GetEnemies()[0].GetLocation().x == Approx(208.333f).epsilon(0.1));
        REQUIRE(level.GetEnemies()[0].GetLocation().y == Approx(191.667f).epsilon(0.1));
        REQUIRE(level.GetEnemies()[2].GetLocation().x == Approx(525.0f).epsilon(0.1));
        REQUIRE(level.GetEnemies()[2].GetLocation().y == Approx(191.667f).epsilon(0.1));
        //REQUIRE(level.GetEnemies()[1].GetLocation() == vec2(366.667,  191.667));
        //REQUIRE(level.GetEnemies()[2].GetLocation() == vec2(525.000,  191.667));
    }

    SECTION("Test Location after an Update") {
        engine.AdvanceOneFrame();
        REQUIRE(level.GetEnemies()[0].GetLocation() == vec2(208.333,  191.667));
    }


}
