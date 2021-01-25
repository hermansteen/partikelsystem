#include "particlesystem.h"

#include "Tracy.hpp"
#include <cmath>
#include <random>

namespace {
    constexpr float Pi = 3.141592654f;
    const float Tau = 2.f * Pi;
} // namespace

ParticleSystem::ParticleSystem() {

}

void ParticleSystem::update([[maybe_unused]] float dt) {
    // @TODO: Update the state of the particle system, move particles forwards, spawn new
    // particles, destroy old particles, and apply effects
}

void ParticleSystem::render() {
    // @TODO: Render the particles, emitters and what not contained within the system
}