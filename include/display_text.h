#ifndef DISPLAY_TEXT_H
#define DISPLAY_TEXT_H 1

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "structs.h"

void display_text(SDL_Renderer *renderer, int x, int y, const char *text,
                  TTF_Font *font, SDL_Texture **texture, SDL_Rect *rect,
                  Color *color);

#endif // -- DISPLAY_TEXT_H