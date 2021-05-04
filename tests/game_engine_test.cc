#include <catch2/catch.hpp>
#include "GameEngine.h"

TEST_CASE("Test GameEngine") {
    // Number of ships starting is 3
    asteroids::Spaceship ship(vec2(500, 850), vec2(50, 0), 100, 50);
    asteroids::GameEngine engine;
    engine.InitializeLevels(1);
    asteroids::Level level = engine.GetLevels()[engine.GetCurrentLevel()];

    SECTION("Test Initial Locations of Enemies") {
        REQUIRE(level.GetEnemies()[0].GetLocation().x == Approx(208.333f).epsilon(0.1));
        REQUIRE(level.GetEnemies()[0].GetLocation().y == Approx(191.667f).epsilon(0.1));
        REQUIRE(level.GetEnemies()[2].GetLocation().x == Approx(525.0f).epsilon(0.1));
        REQUIRE(level.GetEnemies()[2].GetLocation().y == Approx(191.667f).epsilon(0.1));
    }

    SECTION("Test Location after an Update") {
        engine.AdvanceOneFrame();
        REQUIRE(level.GetEnemies()[0].GetLocation().x == Approx(208.333f).epsilon(0.1));
    }

    SECTION("Bottom Edge Testing") {
        level.GetEnemies()[2].SetLocation(vec2(500,750));
        REQUIRE(level.IsAtBottom(level.GetEnemies().at(2), 850) == false);
        level.GetEnemies()[1].SetLocation(vec2(200,800));
        REQUIRE(level.IsAtBottom(level.GetEnemies().at(1), 850) == true);
    }


}
