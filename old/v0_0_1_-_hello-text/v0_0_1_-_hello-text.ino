#include <GxEPD2_BW.h>
#include <Adafruit_GFX.h>
#include <SPI.h>

GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> display(
  GxEPD2_154_D67(D6, D1, D2, D0)
);

bool ojosCerrados = false;
int parpadeos = 0;


// ----------------------------
// DIBUJAR LA MASCOTA
// ----------------------------
void dibujarMascota(bool dormido)
{
  // Limpiamos solamente la zona de la mascota
  display.fillRect(45, 40, 110, 110, GxEPD_WHITE);

  // Cabeza
  display.drawCircle(100, 90, 42, GxEPD_BLACK);
  display.drawCircle(100, 90, 41, GxEPD_BLACK);

  // Orejas
  display.drawLine(70, 60, 75, 38, GxEPD_BLACK);
  display.drawLine(75, 38, 88, 51, GxEPD_BLACK);

  display.drawLine(112, 51, 125, 38, GxEPD_BLACK);
  display.drawLine(125, 38, 130, 60, GxEPD_BLACK);

  // Ojos
  if (dormido)
  {
    // ojos cerrados
    display.drawLine(75, 82, 88, 82, GxEPD_BLACK);
    display.drawLine(112, 82, 125, 82, GxEPD_BLACK);
  }
  else
  {
    // ojos abiertos
    display.fillCircle(82, 82, 4, GxEPD_BLACK);
    display.fillCircle(118, 82, 4, GxEPD_BLACK);
  }

  // Nariz
  display.fillCircle(100, 96, 2, GxEPD_BLACK);

  // Boca
  display.drawLine(100, 99, 94, 105, GxEPD_BLACK);
  display.drawLine(100, 99, 106, 105, GxEPD_BLACK);
}


// ----------------------------
// REFRESCO COMPLETO
// ----------------------------
void pantallaCompleta()
{
  display.setFullWindow();

  display.firstPage();

  do
  {
    display.fillScreen(GxEPD_WHITE);

    dibujarMascota(false);

    display.setTextColor(GxEPD_BLACK);
    display.setTextSize(2);
    display.setCursor(67, 155);
    display.print("MOCHI");

  }
  while (display.nextPage());
}


// ----------------------------
// REFRESCO PARCIAL
// ----------------------------
void actualizarCara()
{
  // Solo actualizamos esta zona
  display.setPartialWindow(
    45,   // X
    40,   // Y
    110,  // ancho
    110   // alto
  );

  display.firstPage();

  do
  {
    dibujarMascota(ojosCerrados);
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

  delay(2000);
}


void loop()
{
  ojosCerrados = true;
  actualizarCara();

  delay(300);

  ojosCerrados = false;
  actualizarCara();

  delay(1500);

  parpadeos++;

  // De vez en cuando hacemos refresco completo
  // para limpiar ghosting de la e-paper
  if (parpadeos >= 20)
  {
    pantallaCompleta();
    parpadeos = 0;
  }
}