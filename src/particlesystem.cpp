#include "particlesystem.h"
#include "util/rendering.h"
#include "../ext/tracy/Tracy.hpp"
#include <cmath>
#include <random>
#include <iostream>

namespace {
constexpr float Pi = 3.141592654f;
const float Tau = 2.f * Pi;
}  // namespace

ParticleSystem::ParticleSystem() {
    _particles = {};
    _emitters = {};
    _effects = {};
}

void ParticleSystem::update(float dt) {
    // @TODO: Update the state of the particle system, move particles forwards, spawn new
    // particles, destroy old particles, and apply effects
    _particles.erase(
        std::remove_if(_particles.begin(), _particles.end(),
                       [](const Particle& p) {
                           return !p.isParticleAlive();  // remove if particle is not alive
                       }),
        _particles.end());

    for (Particle& partikel : _particles) {
        for (Effect* effekt : _effects) {
            vec2 force = effekt->calculateForce(partikel.getPosition());
            partikel.setForce(force);
        }
        partikel.update(dt);
    }

    for (Emitter* emil : _emitters) {
        emil->update(dt);
    }
}

void ParticleSystem::render() {
    // @TODO: Render the particles, emitters and what not contained within the system
    std::vector<Rendering::ParticleInfo> particleRenders{};
    for (const Particle& p : _particles) {
        particleRenders.push_back(p.render());
        // std::cout << p.getPosition().x << ", " << p.getPosition().y << "\n";
    }

    std::vector<Rendering::EmitterInfo> emitterRenders{};
    for (const Emitter* e : _emitters) {
        emitterRenders.push_back(e->render());
    }

    std::vector<Rendering::ForceInfo> effectRenders {};
    for (const Effect* e : _effects) {
        effectRenders.push_back(e->render());
    }

    Rendering::renderEmitters(emitterRenders);
    Rendering::renderParticles(particleRenders);
    Rendering::renderForces(effectRenders);
}

void ParticleSystem::addEmitter(Emitter* e) { _emitters.push_back(e); }

size_t ParticleSystem::numberOfParticles() { return _particles.size(); }

void ParticleSystem::addEffect(Effect* e) { _effects.push_back(e); };