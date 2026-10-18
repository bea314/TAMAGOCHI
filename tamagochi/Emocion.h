#pragma once

#include <stdint.h>

enum Emocion : uint8_t {
  IDLE = 0,
  FELIZ,
  TRISTE,
  ENOJADO,
  HAMBRE,
  COMIENDO,
  ADORMITADO,
  DORMIDO,
  DORMIDO_PROFUNDO,  // pantalla de reposo
  EMOCION_COUNT
};

inline const char* nombreEmocion(Emocion e) {
  switch (e) {
    case IDLE: return "IDLE";
    case FELIZ: return "FELIZ";
    case TRISTE: return "TRISTE";
    case ENOJADO: return "ENOJADO";
    case HAMBRE: return "HAMBRE";
    case COMIENDO: return "COMIENDO";
    case ADORMITADO: return "ADORMITADO";
    case DORMIDO: return "DORMIDO";
    case DORMIDO_PROFUNDO: return "REPOSO";
    default: return "?";
  }
}
