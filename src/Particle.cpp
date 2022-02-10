#include "../include/Particle.h"
#include "util/rendering.h"
#include <cmath>

Particle::Particle(vec2 inVelocity, float inLifeTime, vec2 inPosition, Color inColor) {
    velocity = inVelocity;
    infoStruct = {inPosition, 10.f, inColor, inLifeTime};
}

void Particle::update(const float& dt){
    //Update positions (new velocity and positions)
    velocity += acceleration * dt;
    infoStruct.position += velocity * dt;
    infoStruct.lifetime -= dt;
    const double epsilon = 1e-5;
    if (infoStruct.lifetime < epsilon || std::abs(infoStruct.position.x) > 1.1f || std::abs(infoStruct.position.y) > 1.1f) {
        isAlive = false;
    }
}

bool Particle::isParticleAlive() const { return isAlive; }

vec2 Particle::getPosition() const { return infoStruct.position; }

Rendering::ParticleInfo Particle::render() const { return infoStruct; }

void Particle::setAcceleration(const vec2& _acceleration) { acceleration = _acceleration; }