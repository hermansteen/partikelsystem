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
            ui::GuiScope ui; // Initiates and finalizes UI rendering upon construction/destruction
            // @TODO: Add UI calls
            
            // @TODO: Replace this example code with your own UI elements
            ui::text("I'm text!");
            ui::sliderFloat("Simulation speed", speed, 0.001f, 10.0f);
            if (ui::button("Close application")) {
                isRunning = false;
            }
        }

        particleSystem.update(dt * speed);

        particleSystem.render();

        isRunning &= rendering::endFrame();
    }

    rendering::destroyWindow();

    return EXIT_SUCCESS;
}
