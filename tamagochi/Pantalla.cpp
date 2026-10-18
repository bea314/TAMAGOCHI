#include "Pantalla.h"
#include "config.h"
#include "assets/zorro/zorro.h"

#include <SPI.h>
#include <GxEPD2_BW.h>
#include <Adafruit_GFX.h>

static GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> display(
  GxEPD2_154_D67(EPD_CS, EPD_DC, EPD_RST, EPD_BUSY));

void Pantalla::begin() {
  SPI.begin();
  display.init(115200);
  display.setRotation(0);
  parcialesDesdeFull = 0;
}

void Pantalla::dibujarSpriteEnArea(const Animacion& anim, uint8_t frameIndex) {
  if (anim.numFrames == 0) return;
  if (frameIndex >= anim.numFrames) frameIndex = 0;

  const Frame& f = anim.frames[frameIndex];
  const int16_t dx = PET_X + (int16_t)((PET_W - anim.w) / 2);
  const int16_t dy = PET_Y + (int16_t)((PET_H - anim.h) / 2);

  display.fillRect(PET_X, PET_Y, PET_W, PET_H, GxEPD_WHITE);
  display.drawBitmap(dx, dy, f.bitmap, anim.w, anim.h, GxEPD_BLACK);
}

void Pantalla::dibujarHud(Emocion emocionHud) {
  display.setTextColor(GxEPD_BLACK);
  display.setTextSize(1);
  display.setCursor(72, 150);
  display.print(MASCOTA_NOMBRE);

  display.setCursor(48, 168);
  display.print("Demo: ");
  display.print(nombreEmocion(emocionHud));
}

void Pantalla::refrescoCompleto(Emocion emocionHud) {
  display.setFullWindow();
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    const Animacion& anim = animacionZorro(emocionHud);
    dibujarSpriteEnArea(anim, 0);
    dibujarHud(emocionHud);
  } while (display.nextPage());
  parcialesDesdeFull = 0;
}

void Pantalla::ventanaParcialMascota() {
  display.setPartialWindow(PET_X, PET_Y, PET_W, PET_H);
}

void Pantalla::registrarParcial(Emocion emocionHud) {
  parcialesDesdeFull++;
  if (parcialesDesdeFull >= PARCIALES_ANTES_DE_FULL) {
    refrescoCompleto(emocionHud);
  }
}

void Pantalla::dibujarEstadoParcial(Emocion emocionHud, const Animacion& anim, uint8_t frameIndex) {
  display.setPartialWindow(ZONA_UI_X, ZONA_UI_Y, ZONA_UI_W, ZONA_UI_H);
  display.firstPage();
  do {
    display.fillRect(ZONA_UI_X, ZONA_UI_Y, ZONA_UI_W, ZONA_UI_H, GxEPD_WHITE);
    dibujarSpriteEnArea(anim, frameIndex);
    dibujarHud(emocionHud);
  } while (display.nextPage());
  registrarParcial(emocionHud);
}

void Pantalla::dibujarFrame(const Animacion& anim, uint8_t frameIndex, Emocion emocionHud) {
  ventanaParcialMascota();
  display.firstPage();
  do {
    dibujarSpriteEnArea(anim, frameIndex);
  } while (display.nextPage());
  registrarParcial(emocionHud);
}
