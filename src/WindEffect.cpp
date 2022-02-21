#include "../include/WindEffect.h"

vec2 WindEffect::calculateForce(const vec2& p) {
    // return distance squared between effect position and particles position
    float distanceSquared =
        (_infoStruct.position.x - p.x) * (_infoStruct.position.x - p.x) + (_infoStruct.position.y - p.y) * (_infoStruct.position.y - p.y);
    return direction * (1.f / (1 + distanceSquared)) * _forceMultiplier * windForceDamping;
}
