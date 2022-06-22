#include "../include/init.h"

static Uint32 renderer_flags =
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

void init(Game_State *game, FPS_Counter *fps) {
  game->quit = SDL_FALSE;
  game->renderer = NULL;
  game->win = NULL;

  fps->value = 0.0f;
  fps->texture = NULL;

  if (SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("Unable to Initialize SDL: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  if (TTF_Init()) {
    SDL_Log("Unable to Initialize TTF: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  game->win = SDL_CreateWindow("Window Name", SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH_DEFAULT,
                               WIN_HEIGHT_DEFAULT, 0);
  if (!game->win) {
    SDL_Log("Unable to Initialize Window: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  game->renderer = SDL_CreateRenderer(game->win, -1, renderer_flags);
  if (!game->renderer) {
    SDL_Log("Unable to Initialize Renderer: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  // Limit minimal size of window, so it's visible. Comes after the renderer is
  // created.
  SDL_SetWindowMinimumSize(game->win, WIN_WIDTH_MIN, WIN_HEIGHT_MIN);
}