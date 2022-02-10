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
    particles = {};
    emitters = {};
    effects = {};
}

void ParticleSystem::update(float dt) {
    // @TODO: Update the state of the particle system, move particles forwards, spawn new
    // particles, destroy old particles, and apply effects
    particles.erase(
        std::remove_if(particles.begin(), particles.end(),
                       [](const Particle& p) {
                           return !p.isParticleAlive();  // remove if particle is not alive
                       }),
        particles.end());

    for (Particle& partikel : particles) {
        partikel.update(dt);
    }

    for (Emitter* emil : emitters) {
        emil->update(dt);
    }
}

void ParticleSystem::render() {
    // @TODO: Render the particles, emitters and what not contained within the system
    std::vector<Rendering::ParticleInfo> particleRenders{};
    for (const Particle& p : particles) {
        particleRenders.push_back(p.render());
        // std::cout << p.getPosition().x << ", " << p.getPosition().y << "\n";
    }

    std::vector<Rendering::EmitterInfo> emitterRenders{};
    for (const Emitter* e : emitters) {
        emitterRenders.push_back(e->render());
    }

    Rendering::renderEmitters(emitterRenders);
    Rendering::renderParticles(particleRenders);
}

void ParticleSystem::addEmitter(Emitter* e) { emitters.push_back(e); }

int ParticleSystem::numberOfParticles() { return particles.size(); }