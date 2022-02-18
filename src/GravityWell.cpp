#pragma once
#include "../include/GravityWell.h"

vec2 GravityWell::calculateForce(const vec2& particlePosition) {
        // pull = true gives positive vector, pull = false gives negative
        vec2 forceDirection = _pull ? _infoStruct.position - particlePosition : _infoStruct.position - particlePosition;
        float r = forceDirection.length();
        // limits very high values if particles are close to the effect
        if (r < 0.2f) r = 0.2f;

        return forceDirection.normalized() * _G * _strength / (r * r);
}

void GravityWell::toggle() { _pull != _pull; }
