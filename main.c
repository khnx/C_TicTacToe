#include "include/main.h"

int main(void) {
  Game_State game;
  FPS_Counter fps;
  Board board;
  Msg end_msg;

  end_msg.text = "FINISHED";

  init(&game, &fps);
  program_loop(&game, &fps, &board, &end_msg);
  clean_up(&game, &fps);

  return EXIT_SUCCESS;
}