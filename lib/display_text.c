#include "../include/display_text.h"

void display_text(SDL_Renderer *renderer, int x, int y, const char *text,
                  TTF_Font *font, SDL_Texture **texture, SDL_Rect *rect,
                  Color *color) {

  int text_width, text_height;
  SDL_Surface *surface;
  SDL_Color text_color = {color->r, color->g, color->b, color->a};

  surface = TTF_RenderText_Blended(font, text, text_color);
  *texture = SDL_CreateTextureFromSurface(renderer, surface);
  text_width = surface->w;
  text_height = surface->h;
  SDL_FreeSurface(surface);
  rect->x = x;
  rect->y = y;
  rect->w = text_width;
  rect->h = text_height;
}