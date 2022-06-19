#include "../include/events.h"

static void mouse_click(SDL_Event *event, Board *board, Uint16 *won);

SDL_bool event_loop(Board *board, Uint16 *won) {
  SDL_bool done = SDL_FALSE;
  SDL_Event event;

  while (SDL_PollEvent(&event)) {

    switch (event.type) {

    case SDL_QUIT:
      done = SDL_TRUE;
      break;

    case SDL_MOUSEBUTTONDOWN:
      mouse_click(&event, board, won);
      break;
    }
  }

  return done;
}

static Uint16 winner(Uint16 values[3][3]) {

  // Rows.
  if (((values[0][0] == values[0][1]) && (values[0][1] == values[0][2]) &&
       values[0][0] != 0) ||
      ((values[1][0] == values[1][1]) && (values[1][1] == values[1][2]) &&
       values[1][0] != 0) ||
      ((values[2][0] == values[2][1]) && (values[2][1] == values[2][2]) &&
       values[2][0] != 0)) {
    return 1;
  }
  // Columns.
  else if (((values[0][0] == values[1][0]) && (values[1][0] == values[2][0]) &&
            values[0][0] != 0) ||
           ((values[1][0] == values[1][1]) && (values[1][1] == values[1][2]) &&
            values[1][0] != 0) ||
           ((values[2][0] == values[2][1]) && (values[2][1] == values[2][2]) &&
            values[2][0] != 0)) {
    return 1;
  }
  // Diagonal.
  else if (((values[0][0] == values[1][1]) && (values[1][1] == values[2][2]) &&
            values[0][0] != 0) ||
           ((values[0][2] == values[1][1]) && (values[1][1] == values[2][0]) &&
            values[0][2] != 0)) {
    return 1;
  }

  return 0;
}

static void mouse_click(SDL_Event *event, Board *board, Uint16 *won) {
  Sint32 x = event->motion.x;
  Sint32 y = event->motion.y;

  static Uint16 turn = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (!board->values[i][j] && *won < 1 && x > board->tiles[i][j].x &&
          x < board->tiles[i][j].x + board->tiles[i][j].w &&
          y > board->tiles[i][j].y &&
          y < board->tiles[i][j].y + board->tiles[i][j].h) {

        if (turn) {
          board->values[i][j] = 1;
          turn = 0;
        } else {
          board->values[i][j] = 2;
          turn = 1;
        }

        *won = winner(board->values);
      }
    }
  }
}