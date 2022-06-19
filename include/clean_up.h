#ifndef CLEAN_UP_H
#define CLEAN_UP_H 1

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "structs.h"

void clean_up(Game_State *game, FPS_Counter *fps, Msg *msg, Msg *submsg);

#endif // -- CLEAN_UP_H