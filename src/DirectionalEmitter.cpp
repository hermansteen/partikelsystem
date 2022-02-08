#include "../include/DirectionalEmitter.h"

DirectionalEmitter::DirectionalEmitter(Rendering::EmitterInfo inStruct, float inT = 0,
                                       const float inT0 = 1, const float angle = 0) {
    t = inT;
    t0 = inT0;
    infoStruct = inStruct;
    velocityAngle = angle;
}

std::vector<Particle> DirectionalEmitter::spawnParticles(const float& dt) {
    std::vector<Particle> newParticles = {};
    float angle = velocityAngle / 6.28f;
    vec2 velocity = {cos(angle), sin(angle)};
    for (int i = 0; i < 1; i++) {
        newParticles.push_back(
            Particle(infoStruct.position, 90.f, infoStruct.position, infoStruct.color));
    }
    return newParticles;
}