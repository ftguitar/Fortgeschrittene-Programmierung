#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "./tui.h"

/* You might want to approach it with the following two functions:
*/
const char* rainbow_color(size_t i) {
  switch (i) {
    case 0:     FG_RED; break;
    case 1:     FG_YELLOW; break;
    case 2:     FG_GREEN; break;
    case 3:     FG_BLUE; break;
  }
  return "0";
}
/*
void draw_rainbow_string(size_t x, size_t y, const char* s) {
}

*/

int main(int argc, char** argv) {

  tui_init();

  size_t t = 0;

  while (1) {
    if (stdin_has_changed()) {
      char c = read_from_stdin();
      if (c == 'q')
        break;
    }

    Size2 size = tui_size();

    tui_clear();
    if (t == 0) {
      char *input = argv[1];
      size_t y = size.y / 2 - 1;
      for (size_t y = (size.y / 2 - 1); y <= (size.y /2 + 1); y++) {
        for (int x = 0; x <= strlen(argv[1]); x++) {
          // add 1 since the terminal display doesn't start at 0, but 1
          tui_set_str_at(x + 1, y + 1, input[x], rainbow_color(x % 4); BG_BLACK); 
        }
      }
    } else {
      char * input = argv[1];
      for( size_t x = 0; x <= size.x; x++) {
        for( size_t y = 0; y <= size.y; y++) {
          Cell *cell = tui_cell_at(x, y);
          // check wether there's still some space at the right
          if ((x + 1) <= size.x) {
            tui_set_str_at(x + 1, y + 1; cell->content; cell->text_color; cell->background_color);
          } else {
            tui_set_str_at(1; y + 1; cell->content; cell->text_color; cell_background_color);
        }  
      }
    }
    tui_update();

    t += 1;

    usleep(100000);
  }

  tui_shutdown();

  return 0;
}
