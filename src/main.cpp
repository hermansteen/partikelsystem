#include "Tracy.hpp"
#include "particlesystem.h"
#include "util/rendering.h"

#include <algorithm>
#include <iterator>
#include <random>

// A function strictly used to exemplify the
// render[Particles/Emitters/Forces] functions.
// Note: This function should be removed in your final implementation.
void particleRenderingExample();

int main(int, char**) {
    rendering::createWindow();

    ParticleSystem particleSystem;

    float speed = 1.0f;
    bool isRunning = true;
    while (isRunning) {
        const float dt = rendering::beginFrame();

        {
            ui::GuiScope ui;  // Initiates and finalizes UI rendering upon
                              // construction/destruction
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

        // Particle generation and rendering example. Remove in your implementation.
        particleRenderingExample();

        isRunning &= rendering::endFrame();
    }

    rendering::destroyWindow();

    return EXIT_SUCCESS;
}

void particleRenderingExample() {
    // One-time initialization of particles. The lambda function creates
    // random ParticleInfo. The ParticleInfo struct contains all visual properties
    // used to render particles.
    static std::vector<rendering::ParticleInfo> particles = [](size_t numberOfParticles = 100) {
        std::random_device rd;
        std::mt19937 gen(rd());  // Standard mersenne_twister_engine seeded with rd()
        // Closed interval distribution helper. [first, last) -> [first, last]
        auto closedInterval = [](float val) {
            return std::nextafter(val, std::numeric_limits<float>::max());
        };
        // Particle data distributions
        // Position in [-1,1] = Screen extent
        std::uniform_real_distribution<float> posDist(-1.f, closedInterval(1.f));
        // Color [0, 1] per channel
        std::uniform_real_distribution<float> colorDist(0.f, closedInterval(1.f));
        // Radius
        std::uniform_real_distribution<float> radiusDist(1.f, closedInterval(10.f));

        // Use the distributions to initialize the ParticleInfo structs
        std::vector<rendering::ParticleInfo> randomParticles;
        std::generate_n(std::back_inserter(randomParticles), numberOfParticles,
                        [posDist, colorDist, radiusDist, &gen]() {
                            auto lifetime = 10.f;
                            return rendering::ParticleInfo{
                                {posDist(gen), posDist(gen)},
                                radiusDist(gen),
                                {colorDist(gen), colorDist(gen), colorDist(gen)},
                                lifetime};
                        });

        return randomParticles;
    }();

    // Issue the draw call to render all particles at once.
    rendering::renderParticles(particles);
}
