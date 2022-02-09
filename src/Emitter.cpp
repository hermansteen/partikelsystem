#include "../include/Emitter.h"

Rendering::EmitterInfo Emitter::render() const { return infoStruct; }

void Emitter::update(const float& dt) {
    spawnParticles(dt);
    t += dt;
}