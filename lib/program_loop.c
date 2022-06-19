#include "../include/program_loop.h"

static void display_end_message(SDL_Renderer *renderer, Msg *msg, Msg *submsg,
                                Uint16 won);

void program_loop(Game_State *game, FPS_Counter *fps, Board *board, Msg *msg,
                  Msg *submsg) {
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

    // Display the board.
    render_tiles(renderer, board);
    if (won)
      display_end_message(renderer, msg, submsg, won);

    // Display fps counter.
    fps_counter(renderer, fps);

    // Display the renderer.
    SDL_RenderPresent(renderer);

    Uint64 fps_end = SDL_GetPerformanceCounter();
    fps->value =
        1.0f / ((fps_end - fps_start) / (double)SDL_GetPerformanceFrequency());
  }
}

static void display_end_message(SDL_Renderer *renderer, Msg *msg, Msg *submsg,
                                Uint16 won) {
  const char *font_path = "fonts/freesans/FreeSans.ttf";

  TTF_Init();
  TTF_Font *font = TTF_OpenFont(font_path, 44);
  TTF_Font *font2 = TTF_OpenFont(font_path, 26);
  if (!font || !font2) {
    fprintf(stderr, "Error: Font not found.\n");
    exit(EXIT_FAILURE);
  }

  SDL_Rect rect;
  rect.w = msg->rect.w + 120;
  rect.h = msg->rect.h + 75;
  rect.x = WIN_WIDTH_DEFAULT / 2 - rect.w / 2;
  rect.y = WIN_HEIGHT_DEFAULT / 2 - rect.h / 2;

  SDL_SetRenderDrawColor(renderer, 100, 150, 200, 255);
  SDL_RenderFillRect(renderer, &rect);

  Color color = {255, 255, 255, 255};

  display_text(renderer, WIN_WIDTH_DEFAULT / 2 - msg->rect.w / 2,
               WIN_HEIGHT_DEFAULT / 2 - msg->rect.h / 2, msg->text, font,
               &msg->texture, &msg->rect, &color);
  SDL_RenderCopy(renderer, msg->texture, NULL, &msg->rect);

  char *tell_winner = "No Winner";
  if (won == 1) {
    tell_winner = "Green Wins";
  } else if (won == 2) {
    tell_winner = "Blue Wins";
  }

  display_text(renderer, WIN_WIDTH_DEFAULT / 2 - submsg->rect.w / 2,
               WIN_HEIGHT_DEFAULT / 2 + submsg->rect.h / 2, tell_winner, font2,
               &submsg->texture, &submsg->rect, &color);
  SDL_RenderCopy(renderer, submsg->texture, NULL, &submsg->rect);
}