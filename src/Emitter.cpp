#include "../include/Emitter.h"

Emitter::Emitter() {

}

Rendering::EmitterInfo Emitter::render() const { return infoStruct; }

void Emitter::update(const float& dt) {
	//@TODO uppdatera n�n grej typ
}