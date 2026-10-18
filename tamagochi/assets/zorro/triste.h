#pragma once

#include "../../Animacion.h"
#include "placeholder.h"

static const Frame ZORRO_TRISTE_FRAMES[] = {
  { ZORRO_TPL_TRISTE, 600 },
};

static const Animacion ZORRO_TRISTE = {
  ZORRO_TRISTE_FRAMES,
  1,
  ZORRO_SPRITE_W,
  ZORRO_SPRITE_H,
  true,
};
