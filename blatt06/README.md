# blatt06 (2 / 16.0)


Dein Code kompiliert leider nicht (-14)
## Build Log  🔴 (failure)

```

### make compile  🔴 (failure)
```bash
+ cd $(cat current_sheet)
+ make compile
[0mgcc -g -Wall -c ansi_codes.c -o ansi_codes.o
gcc -g -Wall -c ansi_example.c -o ansi_example.o
gcc -g -Wall ansi_example.o ansi_codes.o -o ansi_example
gcc -g -Wall -c tui_matrix_example.c -o tui_matrix_example.o
gcc -g -Wall -c tui_matrix.c -o tui_matrix.o
gcc -g -Wall tui_matrix_example.o tui_matrix.o ansi_codes.o -o tui_matrix_example
gcc -g -Wall -c tui_example.c -o tui_example.o
gcc -g -Wall -c tui_io.c -o tui_io.o
gcc -g -Wall -c tui.c -o tui.o
gcc -g -Wall tui_example.o tui_matrix.o tui_io.o ansi_codes.o tui.o -o tui_example
gcc -g -Wall -c rainbows.c -o rainbows.o
In file included from ./tui.h:6,
                 from rainbows.c:5:
rainbows.c: In function 'rainbow_color':
././ansi_codes.h:8:16: warning: statement with no effect [-Wunused-value]
    8 | #define FG_RED "\e[0;31m"
      |                ^~~~~~~~~~
rainbows.c:11:17: note: in expansion of macro 'FG_RED'
   11 |     case 0:     FG_RED; break;
      |                 ^~~~~~
././ansi_codes.h:10:19: warning: statement with no effect [-Wunused-value]
   10 | #define FG_YELLOW "\e[0;33m"
      |                   ^~~~~~~~~~
rainbows.c:12:17: note: in expansion of macro 'FG_YELLOW'
   12 |     case 1:     FG_YELLOW; break;
      |                 ^~~~~~~~~
././ansi_codes.h:9:18: warning: statement with no effect [-Wunused-value]
    9 | #define FG_GREEN "\e[0;32m"
      |                  ^~~~~~~~~~
rainbows.c:13:17: note: in expansion of macro 'FG_GREEN'
   13 |     case 2:     FG_GREEN; break;
      |                 ^~~~~~~~
././ansi_codes.h:11:17: warning: statement with no effect [-Wunused-value]
   11 | #define FG_BLUE "\e[0;34m"
      |                 ^~~~~~~~~~
rainbows.c:14:17: note: in expansion of macro 'FG_BLUE'
   14 |     case 3:     FG_BLUE; break;
      |                 ^~~~~~~
rainbows.c: In function 'main':
rainbows.c:46:70: error: expected ')' before ';' token
   46 |           tui_set_str_at(x + 1, y + 1, input[x], rainbow_color(x % 4); BG_BLACK);
      |                                                                      ^
      |                                                                      )
rainbows.c:46:45: warning: passing argument 3 of 'tui_set_str_at' makes pointer from integer without a cast [-Wint-conversion]
   46 |           tui_set_str_at(x + 1, y + 1, input[x], rainbow_color(x % 4); BG_BLACK);
      |                                        ~~~~~^~~
      |                                             |
      |                                             char
In file included from rainbows.c:5:
./tui.h:39:53: note: expected 'const char *' but argument is of type 'char'
   39 | void tui_set_str_at(size_t x, size_t y, const char* s, const char* text_color,
      |                                         ~~~~~~~~~~~~^
rainbows.c:46:11: error: too few arguments to function 'tui_set_str_at'
   46 |           tui_set_str_at(x + 1, y + 1, input[x], rainbow_color(x % 4); BG_BLACK);
      |           ^~~~~~~~~~~~~~
In file included from rainbows.c:5:
./tui.h:39:6: note: declared here
   39 | void tui_set_str_at(size_t x, size_t y, const char* s, const char* text_color,
      |      ^~~~~~~~~~~~~~
rainbows.c:42:14: warning: unused variable 'y' [-Wunused-variable]
   42 |       size_t y = size.y / 2 - 1;
      |              ^
rainbows.c:56:40: error: expected ')' before ';' token
   56 |             tui_set_str_at(x + 1, y + 1; cell->content; cell->text_color; cell->background_color);
      |                                        ^
      |                                        )
rainbows.c:56:13: error: too few arguments to function 'tui_set_str_at'
   56 |             tui_set_str_at(x + 1, y + 1; cell->content; cell->text_color; cell->background_color);
      |             ^~~~~~~~~~~~~~
In file included from rainbows.c:5:
./tui.h:39:6: note: declared here
   39 | void tui_set_str_at(size_t x, size_t y, const char* s, const char* text_color,
      |      ^~~~~~~~~~~~~~
rainbows.c:58:29: error: expected ')' before ';' token
   58 |             tui_set_str_at(1; y + 1; cell->content; cell->text_color; cell_background_color);
      |                             ^
      |                             )
rainbows.c:58:13: error: too few arguments to function 'tui_set_str_at'
   58 |             tui_set_str_at(1; y + 1; cell->content; cell->text_color; cell_background_color);
      |             ^~~~~~~~~~~~~~
In file included from rainbows.c:5:
./tui.h:39:6: note: declared here
   39 | void tui_set_str_at(size_t x, size_t y, const char* s, const char* text_color,
      |      ^~~~~~~~~~~~~~
rainbows.c:53:17: warning: unused variable 'cell' [-Wunused-variable]
   53 |           Cell *cell = tui_cell_at(x, y);
      |                 ^~~~
rainbows.c:50:14: warning: unused variable 'input' [-Wunused-variable]
   50 |       char * input = argv[1];
      |              ^~~~~
rainbows.c:72:1: error: expected declaration or statement at end of input
   72 | }
      | ^
make: *** [Makefile:62: rainbows.o] Error 1

```

