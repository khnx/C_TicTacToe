#ifndef RENDER_TILES_H
#define RENDER_TILES_H 1

#include <SDL2/SDL.h>

#include "init.h"

void render_tiles(SDL_Renderer *renderer, Board *board);
void set_tiles(Board *board);

#endif // -- RENDER_TILES_H