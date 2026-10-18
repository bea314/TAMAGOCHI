#pragma once

#include "../../Animacion.h"
#include "placeholder.h"

static const Frame ZORRO_IDLE_FRAMES[] = {
  { ZORRO_TPL_MARCO, 800 },
};

static const Animacion ZORRO_IDLE = {
  ZORRO_IDLE_FRAMES,
  1,
  ZORRO_SPRITE_W,
  ZORRO_SPRITE_H,
  true,
};
