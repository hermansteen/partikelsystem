#pragma once
#include "util/rendering.h"

class Effect {
public:
    Effect();



    Rendering::EmitterInfo render() const;

private:
    Rendering::ForceInfo infoStruct;
};