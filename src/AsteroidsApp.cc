#include "AsteroidsApp.h"

namespace asteroids {

    AsteroidsApp::AsteroidsApp() : engine_() {
        ci::app::setWindowSize(kWindowSize, kWindowSize - 150);
        engine_.InitializeLevels(26);
    }

    void AsteroidsApp::draw() {
        ci::Color background_color("black");
        ci::gl::clear(background_color);
        engine_.Display();
    }

    void AsteroidsApp::update() {
        engine_.AdvanceOneFrame();
    }

    void AsteroidsApp::keyDown(ci::app::KeyEvent event) {
        switch (event.getCode()) {
            case ci::app::KeyEvent::KEY_RIGHT:
                // move user right
                engine_.GetShip().MakeMove(0);
                break;
            case ci::app::KeyEvent::KEY_LEFT:
                // move user left
                engine_.GetShip().MakeMove(1);
                break;
            case ci::app::KeyEvent::KEY_SPACE:
                // shoot laser
                engine_.GetShip().MakeMove(9);
                break;
            case ci::app::KeyEvent::KEY_ESCAPE:
                // Pause screen
                engine_.ChangePauseStatus();
        }
    }
}