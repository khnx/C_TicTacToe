#include "include/main.h"

int main(void) {
  Game_State game;
  FPS_Counter fps;
  Board board;
  Msg end_msg;
  Msg end_submsg;

  end_msg.text = "FINISHED";

  init(&game, &fps);
  program_loop(&game, &fps, &board, &end_msg, &end_submsg);
  clean_up(&game, &fps, &end_msg, &end_submsg);

  return EXIT_SUCCESS;
}