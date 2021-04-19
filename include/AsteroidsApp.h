//
// Created by Nathan on 4/19/2021.
//

#ifndef NAIVE_BAYES_ASTEROIDSAPP_H
#define NAIVE_BAYES_ASTEROIDSAPP_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace asteroids {

    class AsteroidsApp : public ci::app::App {
    public:
        AsteroidsApp();

        void draw() override;
        void update() override;

        void keyDown(ci::app::KeyEvent event) override;

        const int kWindowSize = 1000;
        const int kMargin = 100;


    };


#endif //NAIVE_BAYES_ASTEROIDSAPP_H
} // namespace asteroids