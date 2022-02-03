#include "particlesystem.h"
#include "util/rendering.h"
#include "Tracy.hpp"
#include <cmath>
#include <random>
#include "../include/Emitter.h"
#include "../include/Particle.h"

std::vector<Particle> particles;
std::vector<Emitter> emitters;

namespace {
    constexpr float Pi = 3.141592654f;
    const float Tau = 2.f * Pi;

    } // namespace

ParticleSystem::ParticleSystem() {
}

void ParticleSystem::update(float dt) {
    // @TODO: Update the state of the particle system, move particles forwards, spawn new
    // particles, destroy old particles, and apply effects
    for (Particle partikel : particles) {
        if (!partikel.isParticleAlive()) {
            particles.erase(find(particles.begin(), particles.end(), partikel));
        }
        partikel.update(dt);
    }

    for (Emitter emil : emitters) {
        emil.update(dt);
    }
}

void ParticleSystem::render() {
    // @TODO: Render the particles, emitters and what not contained within the system
    std::vector<Rendering::ParticleInfo> particleRenders{};
    for (const Particle& p : particles) {
        particleRenders.push_back(p.render());
    }

    std::vector<Rendering::EmitterInfo> emitterRenders{};
    for (const Emitter& e : emitters) {
        emitterRenders.push_back(e.render());
    }
}