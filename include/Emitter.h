#pragma once
#include "util/vec2.h"
#include "util/rendering.h"
#include "Particle.h"

class Emitter{
public:
    Rendering::EmitterInfo render() const;

    void update(const float&);

    virtual void spawnParticles(const float&) = 0;

protected:
    Emitter(std::vector<Particle>& _particles) : particles{_particles} {}

    Rendering::EmitterInfo infoStruct;
    float t = 0;
    float particleSpawnRate = 0.5;

    std::vector<Particle>& particles;
};