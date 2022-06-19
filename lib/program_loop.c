#include "../include/program_loop.h"

static void display_end_message(SDL_Renderer *renderer, Msg *msg);

void program_loop(Game_State *game, FPS_Counter *fps, Board *board, Msg *msg) {
  SDL_Renderer *renderer = game->renderer;
  // Positions/ dimensions of tiles.
  set_tiles(board);
  // Someone won the game.
  Uint16 won = 0;

  while (!game->quit) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    Uint64 fps_start = SDL_GetPerformanceCounter();

    game->quit = event_loop(board, &won);

    if (won)
      display_end_message(renderer, msg);
    // Display the board.
    else {
      render_tiles(renderer, board);
    }

    // Display fps counter.
    fps_counter(renderer, fps);

    // Display the renderer.
    SDL_RenderPresent(renderer);

    Uint64 fps_end = SDL_GetPerformanceCounter();
    fps->value =
        1.0f / ((fps_end - fps_start) / (double)SDL_GetPerformanceFrequency());
  }
}

static void display_end_message(SDL_Renderer *renderer, Msg *msg) {
  const char *font_path = "fonts/freesans/FreeSans.ttf";

  TTF_Init();
  TTF_Font *font = TTF_OpenFont(font_path, 44);
  if (!font) {
    fprintf(stderr, "Error: Font not found.\n");
    exit(EXIT_FAILURE);
  }

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  Color color = {0, 0, 0, 255};

  display_text(renderer, WIN_WIDTH_DEFAULT / 2 - msg->rect.w / 2,
               WIN_HEIGHT_DEFAULT / 2 - msg->rect.h / 2, msg->text, font,
               &msg->texture, &msg->rect, &color);
  SDL_RenderCopy(renderer, msg->texture, NULL, &msg->rect);
}