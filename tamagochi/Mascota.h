#pragma once

#include "Animacion.h"
#include "Emocion.h"
#include "Pantalla.h"

typedef const Animacion& (*AnimacionLookup)(Emocion);

class Mascota {
public:
  Mascota(Pantalla& pantalla, AnimacionLookup lookup);

  void setEmocion(Emocion e, bool redibujar = true);
  Emocion emocionActual() const { return actual; }
  void update();

private:
  void pintarFrameActual();

  Pantalla& pantalla;
  AnimacionLookup lookup;
  Emocion actual = IDLE;
  uint8_t frameIndex = 0;
  uint32_t ultimoCambioMs = 0;
};
