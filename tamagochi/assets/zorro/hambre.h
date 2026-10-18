#pragma once

#include "../../Animacion.h"
#include "placeholder.h"

static const Frame ZORRO_HAMBRE_FRAMES[] = {
  { ZORRO_TPL_HAMBRE, 500 },
  { ZORRO_TPL_MARCO, 500 },
};

static const Animacion ZORRO_HAMBRE = {
  ZORRO_HAMBRE_FRAMES,
  2,
  ZORRO_SPRITE_W,
  ZORRO_SPRITE_H,
  true,
};
