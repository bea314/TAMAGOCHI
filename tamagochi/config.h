#pragma once

// --- Placa / pines e-paper (mismo wiring que old/) ---
#if defined(ESP8266)
  #define EPD_CS D6
  #define EPD_DC D1
  #define EPD_RST D2
  #define EPD_BUSY D0
#elif defined(ESP32)
  #define EPD_CS 5
  #define EPD_DC 17
  #define EPD_RST 16
  #define EPD_BUSY 4
#else
  #error "Define ESP8266 o ESP32 en la placa de Arduino IDE"
#endif

#define PANTALLA_W 200
#define PANTALLA_H 200

// Zona del personaje (refresco parcial fijo)
#define PET_X 40
#define PET_Y 30
#define PET_W 120
#define PET_H 120

// Tras N refrescos parciales, un full limpia ghosting (sin hacerlo en cada emoción)
#define PARCIALES_ANTES_DE_FULL 50

#define MASCOTA_NOMBRE "MOCHI"

// Mascota + HUD en un solo parcial al cambiar emoción (y=30…180)
#define ZONA_UI_X PET_X
#define ZONA_UI_Y PET_Y
#define ZONA_UI_W PET_W
#define ZONA_UI_H 150

// --- Prueba sin botones ---
// 1 = rota IDLE → FELIZ → … cada DEMO_INTERVALO_MS
// 0 = solo EMOCION_INICIAL (útil para pulir un asset)
#define DEMO_CICLO_EMOCIONES 1
#define DEMO_INTERVALO_MS 5000
#define EMOCION_INICIAL 0  // Emocion::IDLE
