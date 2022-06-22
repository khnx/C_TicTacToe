#include "../include/fps_counter.h"

void fps_counter(SDL_Renderer *renderer, FPS_Counter *fps, TTF_Font *font) {

  // Display only 1 in 60 fps.
  static int tick_count = 0;
  if (tick_count == 15) {
    tick_count = 0;
  }

  static char fps_str[32];
  if (tick_count % 15 == 0) {
    snprintf(fps_str, 13, "FPS: %d", (int)fps->value);
  }
  tick_count++;

  Color color = {0, 0, 0, 255};

  display_text(renderer, 0, 0, fps_str, font, &fps->texture, &fps->rect,
               &color);
  SDL_RenderCopy(renderer, fps->texture, NULL, &fps->rect);
}