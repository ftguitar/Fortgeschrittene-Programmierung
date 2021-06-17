#include "./ansi_codes.h"
#include <stdio.h>

int main(void) {
  printf(CLEAR_SCREEN);
  printf(CURSOR_HIDE);
  move_cursor_to(1, 1);
  int i = 1;
  while (i <= 3) {
    int a = 0;
    while (a <= 19) {
      printf("#");
      fflush(stdout);
      a++;
    }
    i++;
    move_cursor_to(1, i);
  }
  printf(FG_RED);
  move_cursor_to(6, 2);
  printf("hello");
  fflush(stdout);
  move_cursor_to(1, 4);
  printf(CURSOR_SHOW);
  printf(COLOR_RESET);
  return 0;
}
