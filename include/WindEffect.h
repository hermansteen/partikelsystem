#pragma once
#include "Effect.h"

class WindEffect : public Effect {
public:
    WindEffect(vec2& pos, vec2& dir, float force) : Effect(pos), direction{dir.normalized()} {
        setMultiplier(force);
    };

    vec2 calculateForce(const vec2& pos) override;

    private:
    vec2 direction;
    const float windForceDamping = 5e-4f;  // how much to dampen the windforce

};