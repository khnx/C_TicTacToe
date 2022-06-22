// Window width/ height.
#ifndef WIN_WIDTH_DEFAULT
#define WIN_WIDTH_DEFAULT 1080
#endif // -- WIN_WIDTH_DEFAULT

#ifndef WIN_HEIGHT_DEFAULT
#define WIN_HEIGHT_DEFAULT 720
#endif // -- WIN_HEIGHT_DEFAULT

#ifndef WIN_WIDTH_MIN
#define WIN_WIDTH_MIN 320
#endif // -- WIN_WIDTH_MIN

#ifndef WIN_HEIGHT_MIN
#define WIN_HEIGHT_MIN 240
#endif // -- WIN_HEIGHT_MIN

#ifndef INIT_H
#define INIT_H 1

#include "SDL2/SDL_ttf.h"
#include <SDL2/SDL.h>

#include "structs.h"

void init(Game_State *game, FPS_Counter *fps);

#endif // -- INIT_H