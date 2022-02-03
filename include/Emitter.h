#pragma once
#include "util/vec2.h"
#include "util/rendering.h"

class Emitter {
public:
    Emitter();

    Rendering::EmitterInfo render() const;

    void update(const float&);

    ~Emitter() = default;

private:
    vec2 position;
    Rendering::EmitterInfo infoStruct;
};