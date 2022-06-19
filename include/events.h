#ifndef EVENTS_H
#define EVENTS_H 1

#include <SDL2/SDL.h>

#include "display_text.h"
#include "render_tiles.h"

#include "structs.h"

#include <stdio.h>

SDL_bool event_loop(Board *board, Uint16 *won);

#endif // -- EVENTS_H