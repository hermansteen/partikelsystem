#include "../include/Emitter.h"

Rendering::EmitterInfo Emitter::render() const { return infoStruct; }

void Emitter::update(const float& dt) {
    t += dt;
    spawnParticles();
}

void Emitter::setPosition(const vec2& position) { infoStruct.position = position; }