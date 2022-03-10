#include "../include/DirectionalEmitter.h"

// DirectionalEmitter::DirectionalEmitter(const Rendering::EmitterInfo inStruct,
// std::vector<Particle>& inVector) {
//    t = 0;
//    particleSpawnRate = 0.001;
//    infoStruct = inStruct;
//    velocityAngle = 2/3.14;
//    particles = {inVector};
//}

void DirectionalEmitter::spawnParticles() {
    if (t > particleSpawnRate) {
        float angle = velocityAngle / 6.28f;
        vec2 velocity = {cos(angle), sin(angle)};
        Particle newParticle =
            Particle(velocity, 50.f, infoStruct.position, Color(1.0f, 1.0f, 0.f));
        particles.push_back(newParticle);
        t -= particleSpawnRate;
    }
}

void DirectionalEmitter::setAngle(const float& inputAngle) { velocityAngle = inputAngle; }