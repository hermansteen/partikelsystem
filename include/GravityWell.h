#pragma once
#include "../include/Effect.h"
#include <cmath>

class GravityWell : public Effect {
public:
    GravityWell() : Effect() { _strength = 100000.f; };

    vec2 calculateForce(const vec2&) override;

    void toggle();

private:
    const float _G = 4.323e-5f;  // gravitational force 
    bool _pull = true;
    float _strength;
};