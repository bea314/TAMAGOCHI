#pragma once

#include "Animacion.h"
#include "Emocion.h"

class Pantalla {
public:
  void begin();
  void refrescoCompleto(Emocion emocionHud);
  void dibujarFrame(const Animacion& anim, uint8_t frameIndex, Emocion emocionHud);
  /** Mascota + HUD en una sola ventana parcial (cambio de emoción) */
  void dibujarEstadoParcial(Emocion emocionHud, const Animacion& anim, uint8_t frameIndex);

private:
  void dibujarSpriteEnArea(const Animacion& anim, uint8_t frameIndex);
  void dibujarHud(Emocion emocionHud);
  void ventanaParcialMascota();
  void registrarParcial(Emocion emocionHud);
  uint8_t parcialesDesdeFull = 0;
};
