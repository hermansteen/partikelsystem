#pragma once
#include "Emitter.h"

class DirectionalEmitter : public Emitter {
public:
    DirectionalEmitter() = default;

        DirectionalEmitter(std::vector<Particle> & _particles, float _angle)
        : Emitter(_particles) {
        setAngle(_angle);
    }

    void setAngle(const float&);

    void spawnParticles(const float&) override;

private:
    float velocityAngle;
    bool first = true;
};