#pragma once
#include "../include/Effect.h"
#include <cmath>

class GravityWell : public Effect {
public:
    GravityWell() : Effect() {};

    vec2 calculateForce(const vec2&) override;



private:
    float _G = 6.674f * pow(19,-11);
};