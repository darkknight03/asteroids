//
// Created by Nathan on 4/19/2021.
//

#include "AsteroidsApp.h"

namespace asteroids {

    AsteroidsApp::AsteroidsApp() : ship_(vec2(500, 900), vec2(25, 0), 100, 5), engine_(ship_) {
        ci::app::setWindowSize(kWindowSize, kWindowSize - 100);
        //engine_.InitializeLevels(5);
    }

    void AsteroidsApp::draw() {
        ci::Color background_color("black");
        ci::gl::clear(background_color);
        //engine_.Display();
    }

    void AsteroidsApp::update() {
        //engine_.AdvanceOneFrame();
    }

    void AsteroidsApp::keyDown(ci::app::KeyEvent event) {
        switch (event.getCode()) {
            case ci::app::KeyEvent::KEY_LEFT:
                // move user left
                ship_.MakeMove(0);
                break;
            case ci::app::KeyEvent::KEY_RIGHT:
                // move user right
                ship_.MakeMove(1);
                break;
            case ci::app::KeyEvent::KEY_SPACE:
                // shoot laser
                ship_.MakeMove(9);
                break;
        }
    }
}