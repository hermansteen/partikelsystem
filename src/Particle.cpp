#include "../include/Particle.h"
#include "util/rendering.h"

Particle::Particle(vec2 inVelocity, float inLifeTime, vec2 inPosition, Color inColor) {
    velocity = inVelocity;
    Rendering::ParticleInfo infoStruct = {inPosition, 2.f, inColor, inLifeTime};
}

void Particle::update(const float& dt){
    //Update positions (new velocity and positions)
    velocity += acceleration * dt;
    infoStruct.position += velocity * dt;
    infoStruct.lifetime -= dt;
    const double epsilon = 1e-5;
    if (infoStruct.lifetime < epsilon) {
        isAlive = false;
    }
}

bool Particle::isParticleAlive() const { return isAlive; }

vec2 Particle::getPosition() const { return infoStruct.position; }

Rendering::ParticleInfo Particle::render() const { return infoStruct; }
