#include <GxEPD2_BW.h>
#include <Adafruit_GFX.h>
#include <SPI.h>

GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> display(
  GxEPD2_154_D67(D6, D1, D2, D0)
);

bool ojosCerrados = false;
int ciclos = 0;

// ----------------------------
// DIBUJAR PIXEL ART
// ----------------------------
void pixel(int x, int y, int s, uint16_t color = GxEPD_BLACK)
{
  display.fillRect(x, y, s, s, color);
}

void dibujarMascotaPixel(bool dormido)
{
  // limpiar solo el área del personaje
  display.fillRect(40, 30, 120, 120, GxEPD_WHITE);

  int s = 6;      // tamaño del “pixel”
  int ox = 58;    // origen x
  int oy = 42;    // origen y

  // cabeza / contorno
  for (int i = 2; i <= 10; i++) {
    pixel(ox + i*s, oy + 0*s, s);
    pixel(ox + i*s, oy + 10*s, s);
  }

  for (int i = 1; i <= 9; i++) {
    pixel(ox + 0*s, oy + i*s, s);
    pixel(ox + 12*s, oy + i*s, s);
  }

  // esquinas internas para suavizar estilo pixel
  pixel(ox + 1*s, oy + 1*s, s);
  pixel(ox + 11*s, oy + 1*s, s);
  pixel(ox + 1*s, oy + 9*s, s);
  pixel(ox + 11*s, oy + 9*s, s);

  // orejas
  pixel(ox + 2*s, oy - 1*s, s);
  pixel(ox + 3*s, oy - 2*s, s);
  pixel(ox + 4*s, oy - 1*s, s);

  pixel(ox + 8*s, oy - 1*s, s);
  pixel(ox + 9*s, oy - 2*s, s);
  pixel(ox + 10*s, oy - 1*s, s);

  // ojos
  if (dormido)
  {
    pixel(ox + 3*s, oy + 4*s, s);
    pixel(ox + 4*s, oy + 4*s, s);

    pixel(ox + 8*s, oy + 4*s, s);
    pixel(ox + 9*s, oy + 4*s, s);
  }
  else
  {
    pixel(ox + 3*s, oy + 4*s, s);
    pixel(ox + 4*s, oy + 4*s, s);
    pixel(ox + 3*s, oy + 5*s, s);
    pixel(ox + 4*s, oy + 5*s, s);

    pixel(ox + 8*s, oy + 4*s, s);
    pixel(ox + 9*s, oy + 4*s, s);
    pixel(ox + 8*s, oy + 5*s, s);
    pixel(ox + 9*s, oy + 5*s, s);
  }

  // nariz
  pixel(ox + 6*s, oy + 6*s, s);

  // boca
  pixel(ox + 5*s, oy + 7*s, s);
  pixel(ox + 7*s, oy + 7*s, s);
  pixel(ox + 6*s, oy + 8*s, s);

  // piecitos
  pixel(ox + 3*s, oy + 11*s, s);
  pixel(ox + 4*s, oy + 11*s, s);
  pixel(ox + 8*s, oy + 11*s, s);
  pixel(ox + 9*s, oy + 11*s, s);
}

// ----------------------------
// PANTALLA COMPLETA
// ----------------------------
void pantallaCompleta()
{
  display.setFullWindow();
  display.firstPage();

  do
  {
    display.fillScreen(GxEPD_WHITE);

    dibujarMascotaPixel(false);

    display.setTextColor(GxEPD_BLACK);
    display.setTextSize(1);
    display.setCursor(72, 150);
    display.print("MOCHI");

    display.setCursor(55, 170);
    display.print("Hambre: ***");

    display.setCursor(55, 182);
    display.print("Feliz : ***");
  }
  while (display.nextPage());
}

// ----------------------------
// REFRESCO PARCIAL
// ----------------------------
void actualizarMascota()
{
  display.setPartialWindow(40, 30, 120, 120);

  display.firstPage();
  do
  {
    dibujarMascotaPixel(ojosCerrados);
  }
  while (display.nextPage());
}

void setup()
{
  Serial.begin(115200);
  SPI.begin();

  display.init(115200);
  display.setRotation(0);

  pantallaCompleta();
  delay(1500);
}

void loop()
{
  ojosCerrados = true;
  actualizarMascota();
  delay(250);

  ojosCerrados = false;
  actualizarMascota();
  delay(1400);

  ciclos++;

  // refresco completo ocasional para limpiar ghosting
  if (ciclos >= 15)
  {
    pantallaCompleta();
    ciclos = 0;
  }
}