//
// Created by Nathan on 4/19/2021.
//

#include "AsteroidsApp.h"

namespace asteroids {

    AsteroidsApp::AsteroidsApp() {
        ci::app::setWindowSize(kWindowSize, kWindowSize);

    }

    void AsteroidsApp::draw() {
        ci::Color background_color("black");
        ci::gl::clear(background_color);
    }

    void AsteroidsApp::update() {
        AppBase::update();
    }

    void AsteroidsApp::keyDown(ci::app::KeyEvent event) {
        AppBase::keyDown(event);
    }
}