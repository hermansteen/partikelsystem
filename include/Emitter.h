#pragma once
#include "util/vec2.h"
#include "util/rendering.h"
#include "Particle.h"

class Emitter{
public:
    Rendering::EmitterInfo render() const;

    void update(const float&);

    virtual std::vector<Particle> spawnParticles(const float&) = 0;

protected:
    Rendering::EmitterInfo infoStruct;
    float t;
    float t0;
};