#ifndef FPS_COUNTER_H
#define FPS_COUNTER_H 1

#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "display_text.h"

#include "structs.h"

void fps_counter(SDL_Renderer *renderer, FPS_Counter *fps, TTF_Font *font);

#endif // -- FPS_COUNTER_H