#pragma once
#include "util/rendering.h"
#include "../include/Particle.h"

class Effect {
public:
    Effect() {
        _infoStruct = {{0, 0}, 12.5f, Color(0.8f, 0.2f, 1.f)};
        _isActive = true;
        _forceMultiplier = 1.0f;
    }

    Effect(vec2& pos) : Effect() { setPosition(pos); }

    virtual vec2 calculateForce(const vec2&) = 0;

    void setActive(bool active) { _isActive = active; }

    void setMultiplier(float& coefficient) { _forceMultiplier = coefficient; }

    void setPosition(vec2& pos) { _infoStruct.position = pos; }

    Rendering::ForceInfo render() const;

    bool isActive() const;

protected:
    Rendering::ForceInfo _infoStruct;
    bool _isActive;
    float _forceMultiplier = 1.0f;
};