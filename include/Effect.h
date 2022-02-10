#pragma once
#include "util/rendering.h"
#include "../include/Particle.h"

class Effect {
public:
    Effect(const std::vector<Particle>& _particles) : particles{_particles} {};

    virtual void update(const float&) = 0;

    Rendering::ForceInfo render() const;

protected:
    std::vector<Particle> particles;
    Rendering::ForceInfo infoStruct;
};