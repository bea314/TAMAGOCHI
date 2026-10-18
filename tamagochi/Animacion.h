#pragma once

#include <Arduino.h>

struct Frame {
  const uint8_t* bitmap;
  uint16_t duracionMs;
};

struct Animacion {
  const Frame* frames;
  uint8_t numFrames;
  uint8_t w;
  uint8_t h;
  bool loop;
};
