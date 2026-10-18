#pragma once

#include "../../Emocion.h"
#include "../../Animacion.h"
#include "idle.h"
#include "feliz.h"
#include "triste.h"
#include "enojado.h"
#include "hambre.h"
#include "comiendo.h"
#include "adormitado.h"
#include "dormido.h"
#include "dormido_profundo.h"

inline const Animacion& animacionZorro(Emocion e) {
  switch (e) {
    case FELIZ: return ZORRO_FELIZ;
    case TRISTE: return ZORRO_TRISTE;
    case ENOJADO: return ZORRO_ENOJADO;
    case HAMBRE: return ZORRO_HAMBRE;
    case COMIENDO: return ZORRO_COMIENDO;
    case ADORMITADO: return ZORRO_ADORMITADO;
    case DORMIDO: return ZORRO_DORMIDO;
    case DORMIDO_PROFUNDO: return ZORRO_DORMIDO_PROFUNDO;
    case IDLE:
    default: return ZORRO_IDLE;
  }
}
