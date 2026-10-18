#include "Mascota.h"

Mascota::Mascota(Pantalla& pantallaRef, AnimacionLookup lookupFn)
  : pantalla(pantallaRef), lookup(lookupFn) {}

void Mascota::pintarFrameActual() {
  const Animacion& anim = lookup(actual);
  pantalla.dibujarFrame(anim, frameIndex, actual);
}

void Mascota::setEmocion(Emocion e, bool redibujar) {
  if (e >= EMOCION_COUNT) e = IDLE;
  actual = e;
  frameIndex = 0;
  ultimoCambioMs = millis();
  if (redibujar) pintarFrameActual();
}

void Mascota::update() {
  const Animacion& anim = lookup(actual);
  if (anim.numFrames <= 1) return;

  const Frame& f = anim.frames[frameIndex];
  if ((uint32_t)(millis() - ultimoCambioMs) < f.duracionMs) return;

  ultimoCambioMs = millis();
  frameIndex++;
  if (frameIndex >= anim.numFrames) {
    frameIndex = anim.loop ? 0 : (anim.numFrames - 1);
  }
  pintarFrameActual();
}
