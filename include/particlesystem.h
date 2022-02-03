#ifndef __PARTICLESYSTEM_H__
#define __PARTICLESYSTEM_H__

#include "util/color.h"
#include "util/rendering.h"
#include "util/vec2.h"
#include "../include/Particle.h"

class ParticleSystem {
public:
    ParticleSystem();

    void update(float dt);
    void render();

private:
    std::vector<Particle> particles;
};

#endif // __PARTICLESYSTEM_H__
