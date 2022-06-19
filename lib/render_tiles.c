#include "../include/render_tiles.h"

void set_tiles(Board *board) {
  int width = 200;
  int height = 200;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board->tiles[i][j].w = width - 5;
      board->tiles[i][j].h = height - 5;
      board->tiles[i][j].x = (WIN_WIDTH_DEFAULT / 2) + (j - 1.5) * width;
      board->tiles[i][j].y = (WIN_HEIGHT_DEFAULT / 2) + (i - 1.5) * height;

      board->values[i][j] = 0;
    }
  }
}

void render_tiles(SDL_Renderer *renderer, Board *board) {
  SDL_RenderClear(renderer);

  // Tiles.
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board->values[i][j] == 1)
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
      else if (board->values[i][j] == 2)
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
      else
        SDL_SetRenderDrawColor(renderer, 255, 46, 0, 255);
      SDL_RenderFillRect(renderer, &board->tiles[i][j]);
    }
  }
}