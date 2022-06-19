#include "../include/fps_counter.h"

void fps_counter(SDL_Renderer *renderer, FPS_Counter *fps) {

  const char *font_path = "fonts/freesans/FreeSans.ttf";

  TTF_Init();
  TTF_Font *font = TTF_OpenFont(font_path, 12);
  if (!font) {
    fprintf(stderr, "Error: Font not found.\n");
    exit(EXIT_FAILURE);
  }

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