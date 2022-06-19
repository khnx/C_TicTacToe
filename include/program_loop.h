#ifndef PROGRAM_LOOP_H
#define PROGRAM_LOOP_H 1

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "events.h"
#include "fps_counter.h"
#include "init.h"
#include "render_tiles.h"

#include "structs.h"

void program_loop(Game_State *game, FPS_Counter *fps, Board *board, Msg *msg);

#endif // -- PROGRAM_LOOP_H