#include "../include/clean_up.h"

void clean_up(Game_State *game) {

  TTF_Quit();
  SDL_DestroyRenderer(game->renderer);
  SDL_DestroyWindow(game->win);

  SDL_Quit();
}