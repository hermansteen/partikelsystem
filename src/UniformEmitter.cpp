#include "UniformEmitter.h"

void UniformEmitter::spawnParticles() {
    if (t > particleSpawnRate) {
        const int n = 16;  // number of particles to spawn per "wave"
        for (int i = 0; i < n; i++) {
            vec2 velocity = {cos(i * (3.14f / 8.f)), sin(i * (3.14f / 8.f))};
            particles.push_back(
                Particle(velocity, 90.f, infoStruct.position, Color(1.0f, 0.f, 1.0f)));
        }
            t -= particleSpawnRate;
    }
}
