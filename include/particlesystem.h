#ifndef __PARTICLESYSTEM_H__
#define __PARTICLESYSTEM_H__

#include "util/color.h"
#include "util/rendering.h"
#include "util/vec2.h"
#include "../include/Emitter.h"
#include "../include/Particle.h"
#include "../include/Effect.h"
#include "../include/DirectionalEmitter.h"
#include "../include/UniformEmitter.h"
#include "../include/GravityWell.h"
#include "../include/WindEffect.h"

class ParticleSystem {
public:
    ParticleSystem();

    void update(float dt);
    void render();

    void addEmitter(Emitter* e);

    void addEffect(Effect* e);

    int numberOfParticles();

    std::vector<Particle> _particles;
private:
    std::vector<Emitter*> _emitters;
    std::vector<Effect*> _effects;
};

#endif // __PARTICLESYSTEM_H__
