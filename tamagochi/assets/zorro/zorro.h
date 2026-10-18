#pragma once

#include "../../Emocion.h"
#include "../../Animacion.h"
#include "idle.h"
#include "feliz.h"
#include "triste.h"
#include "hambre.h"
#include "dormido.h"

inline const Animacion& animacionZorro(Emocion e) {
  switch (e) {
    case FELIZ: return ZORRO_FELIZ;
    case TRISTE: return ZORRO_TRISTE;
    case HAMBRE: return ZORRO_HAMBRE;
    case DORMIDO: return ZORRO_DORMIDO;
    case IDLE:
    default: return ZORRO_IDLE;
  }
}
