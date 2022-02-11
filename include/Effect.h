#pragma once
#include "util/rendering.h"
#include "../include/Particle.h"

class Effect {
public:
    Effect() : _isActive{true} {};

    Effect(const std::vector<Particle>& particles) : _particles{particles} {};

    virtual vec2 calculateForce(const vec2&) = 0;

    void setActive(bool active) { _isActive = active; }

    Rendering::ForceInfo render() const;

    bool isActive();

protected:
    std::vector<Particle> _particles;
    Rendering::ForceInfo _infoStruct;
    bool _isActive;
};