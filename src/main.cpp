#include "particlesystem.h"
#include "util/rendering.h"
#include "Tracy.hpp"

int main(int, char**) {
    rendering::createWindow();

    ParticleSystem particleSystem;

    bool isRunning = true;
    while (isRunning) {
        const float dt = rendering::beginFrame();
        float speed = 1.0f;

        {
            ui::begin();
            // @TODO: Add UI calls within ui::begin() and ui::end() here
            
            // @TODO: Replace this example code with your own UI elements
            ui::text("I'm a text!");
            ui::sliderFloat("simulation speed", speed, 0.001f, 10.0f);
            if (ui::button("kill program")) {
                isRunning = false;
            }

            ui::end();
        }

        particleSystem.update(dt * speed);

        particleSystem.render();

        isRunning &= rendering::endFrame();
    }

    rendering::destroyWindow();

    return EXIT_SUCCESS;
}
