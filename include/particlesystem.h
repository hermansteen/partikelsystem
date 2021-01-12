#ifndef __PARTICLESYSTEM_H__
#define __PARTICLESYSTEM_H__

#include "util/color.h"
#include "util/rendering.h"
#include "util/vec2.h"
#include <memory>
#include <optional>
#include <vector>

class ParticleSystem {
public:
    ParticleSystem();

    void update(float dt);

    // These methods are called by the client to get the information about particles,
    // emitters, and forces
    std::vector<rendering::ParticleInfo> particleInformation() const;
    std::vector<rendering::EmitterInfo> emitterInformation() const;
    std::vector<rendering::ForceInfo> forcesInformation() const;
};

#endif // __PARTICLESYSTEM_H__
