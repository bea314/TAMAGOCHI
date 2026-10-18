# Tamagochi — e-paper 1.54" (zorro)

Mascota virtual en pantalla **e-paper 1.54"** (200×200, driver `GxEPD2_154_D67`). Pruebas iniciales en **ESP8266**; objetivo **ESP32 Mini**. Librerías: **GxEPD2** + **Adafruit_GFX**.

## Idea

- **Emociones = assets** (bitmaps en `.h`). Cambias la reacción con `mascota.setEmocion(FELIZ)`.
- **Personaje = carpeta** (`assets/zorro/`). Otro muñeco = otra carpeta + misma API.
- **Pantalla y lógica separadas**: el `.ino` solo orquesta; el dibujo no va mezclado con el juego.

## Estructura (proyecto principal)

```
TAMAGOCHI/
├── old/                    # Pruebas iniciales (texto, parpadeo, pixel art)
├── art/zorro/              # PNG fuente (no se compila)
├── tools/png2h.py          # PNG → headers C (opcional)
└── tamagochi/              # Sketch Arduino (todo en raíz del sketch = compila en IDE)
    ├── tamagochi.ino
    ├── config.h            # Pines, demo sin botones
    ├── Pantalla.* / Mascota.* / Emocion.h / Animacion.h
    └── assets/zorro/       # idle.h, feliz.h, … + zorro.h (tabla)
```

## Cómo correr

1. Instalar en Arduino IDE: **GxEPD2**, **Adafruit GFX**, **Adafruit BusIO**.
2. Abrir la carpeta **`tamagochi/`** (sketch `tamagochi.ino`).
3. Placa: **ESP8266** (o la que uses). Ajustar **`config.h`** si cambias pines o pasas a ESP32.
4. Subir. Por defecto **`DEMO_CICLO_EMOCIONES`** en `config.h` rota emociones cada 5 s (sin botones). Para fijar una: `DEMO_CICLO_EMOCIONES 0` + `EMOCION_INICIAL`.

**Pruebas viejas:** abrir y flashear los `.ino` dentro de `old/` (mismo display y pines que en esos sketches).

## Assets

| Paso | Acción |
|------|--------|
| Dibujar | PNG 1-bit o escala de grises → export ~120×120 en `art/zorro/` |
| Convertir | [image2cpp](https://javl.github.io/image2cpp/) o `tools/png2h.py` → `assets/zorro/*.h` |
| Registrar | Incluir en `zorro.h` y mapear en `animacionZorro(Emocion)` |

Formato: bitmap **horizontal, 1 bit**, en **`PROGMEM`**.

## e-paper (importante)

- Refresco **parcial** ~300 ms → animaciones **2–4 frames**, ≥300 ms por frame.
- Ventana del sprite **fija** (ej. 40,30,120,120) para no redibujar HUD cada vez.
- Cada **~15 parciales**, un **refresh completo** para reducir ghosting (`config.h`).

## Roadmap corto

1. Esqueleto `tamagochi/` + un asset `idle`.
2. Emociones del zorro (feliz, triste, hambre, dormido…).
3. `Estado` (stats, botones) → elige `Emocion`; mascota y pantalla igual.
4. Migrar pines a ESP32 Mini en `config.h`.

## `old/`

| Carpeta | Qué prueba |
|---------|------------|
| `v0_0_1_-_hello-text` | Texto + mascota vectorial |
| `v0_0_2_-_ugly-cat-blink` | Pixel art + parpadeo parcial + HUD |

Referencia de pines en esos sketches: CS=D6, DC=D1, RST=D2, BUSY=D0.
