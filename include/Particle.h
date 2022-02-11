#pragma once
#include "util/vec2.h"
#include "util/rendering.h"

class Particle {
public:
    void update(const float&);

    ~Particle() = default;
    Particle(vec2 inVelocity, float inLifeTime, vec2 inPosition, Color inColor);

    bool isParticleAlive() const;

    vec2 getPosition() const;

    Rendering::ParticleInfo render() const;

    void setForce(const vec2& _acceleration);

private:
    bool isAlive = true;
    vec2 velocity;
    vec2 force;
    vec2 acceleration;
    Rendering::ParticleInfo infoStruct;
};