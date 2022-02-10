#pragma once
#include "Emitter.h"

class DirectionalEmitter : public Emitter {
public:
    DirectionalEmitter() = default;

        DirectionalEmitter(std::vector<Particle> & _particles, float _angle, vec2 position)
        : Emitter(_particles) {
        setAngle(_angle);
            setPosition(position);
    }

    void setAngle(const float&);

    void spawnParticles(const float&) override;

private:
    float velocityAngle;
    bool first = true;
};