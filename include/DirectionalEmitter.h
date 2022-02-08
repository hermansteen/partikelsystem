#pragma once
#include "Emitter.h"

class DirectionalEmitter : public Emitter {
public:
    DirectionalEmitter(Rendering::EmitterInfo const, float, float, const float);

    std::vector<Particle> spawnParticles(const float&) override;

private:
    float velocityAngle;
};