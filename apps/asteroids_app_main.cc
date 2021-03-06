#include <AsteroidsApp.h>

using asteroids::AsteroidsApp;

void prepareSettings(AsteroidsApp::Settings* settings) {
    settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(AsteroidsApp, ci::app::RendererGl, prepareSettings);
