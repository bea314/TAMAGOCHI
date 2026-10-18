#pragma once

#include "../../Animacion.h"
#include "placeholder.h"

static const Frame ZORRO_FELIZ_FRAMES[] = {
  { ZORRO_TPL_OJOS, 400 },
  { ZORRO_TPL_OJOS_CERRADOS, 300 },
};

static const Animacion ZORRO_FELIZ = {
  ZORRO_FELIZ_FRAMES,
  2,
  ZORRO_SPRITE_W,
  ZORRO_SPRITE_H,
  true,
};
