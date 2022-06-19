#include "../include/clean_up.h"

void clean_up(Game_State *game, FPS_Counter *fps, Msg *msg, Msg *submsg) {

  SDL_DestroyTexture(msg->texture);
  SDL_DestroyTexture(submsg->texture);
  SDL_DestroyTexture(fps->texture);

  TTF_Quit();

  SDL_DestroyRenderer(game->renderer);
  SDL_DestroyWindow(game->win);

  SDL_Quit();
}