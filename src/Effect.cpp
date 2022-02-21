#include "../include/Effect.h"

Rendering::ForceInfo Effect::render() const { return _infoStruct; }

bool Effect::isActive() const { return _isActive; }