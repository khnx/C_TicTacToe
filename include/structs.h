#include <SDL2/SDL.h>

#ifndef MSG_S
#define MSG_S 1

typedef struct Msg {
  const char *text;
  SDL_Rect rect;
  SDL_Texture *texture;
} Msg;

#endif // -- MSG_S

#ifndef COLOR_S
#define COLOR_S 1

typedef struct Color {
  Uint16 r;
  Uint16 g;
  Uint16 b;
  Uint16 a;
} Color;

#endif // -- COLOR_S

#ifndef FPS_COUNTER_S
#define FPS_COUNTER_S 1

typedef struct FPS_Counter {
  SDL_Rect rect;
  SDL_Texture *texture;
  double value;
} FPS_Counter;

#endif // -- FPS_COUNTER_S

#ifndef GAME_STATE_S
#define GAME_STATE_S 1

typedef struct Game_State {
  SDL_Renderer *renderer;
  SDL_Window *win;
  SDL_bool quit;
} Game_State;

#endif // -- GAME_STATE_S

#ifndef BOARD_S
#define BOARD_S 1

typedef struct Board {
  SDL_Rect tiles[3][3];
  Uint16 values[3][3];
} Board;

#endif // -- BOARD_S