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

void ParticleSystem::update(float dt) {
    // @TODO: Update the state of the particle system, move particles forwards, spawn new
    // particles, destroy old particles, and apply effects


}

std::vector<rendering::ParticleInfo> ParticleSystem::particleInformation() const {
    std::vector<rendering::ParticleInfo> result;

    // @TODO: Fill the data with your internal particle data

    return result;
}

std::vector<rendering::EmitterInfo> ParticleSystem::emitterInformation() const {
    std::vector<rendering::EmitterInfo> result;

    // @TODO: Fill the data with your internal particle data

    return result;
}

std::vector<rendering::ForceInfo> ParticleSystem::forcesInformation() const {
    std::vector<rendering::ForceInfo> result;

    // @TODO: Fill the data with your internal particle data

    return result;
}
