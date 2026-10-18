#pragma once

#include "../../Animacion.h"
#include "placeholder.h"

static const Frame ZORRO_DORMIDO_FRAMES[] = {
  { ZORRO_TPL_OJOS_CERRADOS, 1000 },
};

static const Animacion ZORRO_DORMIDO = {
  ZORRO_DORMIDO_FRAMES,
  1,
  ZORRO_SPRITE_W,
  ZORRO_SPRITE_H,
  true,
};
