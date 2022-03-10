#pragma once
#include "Emitter.h"
class UniformEmitter : public Emitter {
public:
    UniformEmitter(std::vector<Particle>& _particles, const vec2& _position) : Emitter(_particles) {
        setPosition(_position);
    };

    void spawnParticles() override;
};
