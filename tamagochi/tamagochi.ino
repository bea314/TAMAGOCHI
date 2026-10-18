#include "config.h"
#include "Emocion.h"
#include "Pantalla.h"
#include "Mascota.h"
#include "assets/zorro/zorro.h"

Pantalla pantalla;
Mascota mascota(pantalla, animacionZorro);

#if DEMO_CICLO_EMOCIONES
static uint32_t ultimoCambioDemo = 0;
static Emocion demoEmocion = IDLE;

static void demoAvanzarEmocion() {
  if ((uint32_t)(millis() - ultimoCambioDemo) < (uint32_t)DEMO_INTERVALO_MS) return;

  ultimoCambioDemo = millis();
  demoEmocion = (Emocion)((demoEmocion + 1) % EMOCION_COUNT);

  mascota.setEmocion(demoEmocion, false);
  pantalla.dibujarEstadoParcial(demoEmocion, animacionZorro(demoEmocion), 0);

  Serial.print(F("[demo] emocion -> "));
  Serial.println(nombreEmocion(demoEmocion));
}
#endif

void setup() {
  Serial.begin(115200);
  Serial.println(F("tamagochi — demo sin botones"));

  pantalla.begin();

#if DEMO_CICLO_EMOCIONES
  const Emocion inicial = IDLE;
  demoEmocion = inicial;
#else
  const Emocion inicial = (Emocion)EMOCION_INICIAL;
#endif

  // Igual que old/v0_0_2: un full al inicio y luego solo parciales
  pantalla.refrescoCompleto(inicial);
  mascota.setEmocion(inicial, false);

#if DEMO_CICLO_EMOCIONES
  ultimoCambioDemo = millis();
#endif

  Serial.print(F("Emocion inicial: "));
  Serial.println(nombreEmocion(mascota.emocionActual()));
}

void loop() {
  mascota.update();
#if DEMO_CICLO_EMOCIONES
  demoAvanzarEmocion();
#endif
}
