#include "particlesystem.h"
#include "util/rendering.h"
#include "Tracy.hpp"

int main(int, char**) {
    rendering::createWindow();

    ParticleSystem particleSystem;
    bool isRunning = true;
    while (isRunning) {
        const float dt = rendering::beginFrame();

        // @TODO: Add your calls that should happen every frame (for example UI) here


        // Should be no need to change the following code
        particleSystem.update(dt);
        rendering::updateParticles(particleSystem.particleInformation());
        rendering::updateForces(particleSystem.forcesInformation());
        rendering::updateEmitters(particleSystem.emitterInformation());

        rendering::render();
        isRunning = rendering::endFrame();
    }

    rendering::destroyWindow();

    return EXIT_SUCCESS;
}
