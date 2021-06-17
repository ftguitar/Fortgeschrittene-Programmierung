#include <assert.h>
#include <stdlib.h>
#include <unistd.h>

#include "../tui/tui.h"

#include "./game_lib.h"

void draw_info_bar(GameState* gs) {
  char buf[255];
  sprintf(buf, "LIFES: %d    POINTS: %d    DISTANCE: %d    POWERUP: %d",
          gs->ship.health, gs->points, gs->time_step, gs->ship.powerup_time);
  tui_set_str_at(0, gs->term_size.y - 1, buf, FG_WHITE, BG_BLACK);
}

void draw_frame(GameState* gs) {
  Cell c = (Cell){
      .content = ' ', .text_color = FG_WHITE, .background_color = BG_WHITE};
  Int2 frame_begin = {gs->field_begin.x - 1, gs->field_begin.y - 1};
  Int2 frame_end = {gs->field_end.x + 1, gs->field_end.y + 1};
  for (size_t x = frame_begin.x; x < frame_end.x; ++x) {
    *tui_cell_at(x, frame_begin.y) = c;
    *tui_cell_at(x, frame_end.y - 1) = c;
  }
  for (size_t y = frame_begin.y; y < frame_end.y; ++y) {
    *tui_cell_at(frame_begin.x, y) = c;
    *tui_cell_at(frame_end.x - 1, y) = c;
  }
}

bool is_field_coordinate(GameState* gs, int x, int y) {
  Int2 size = gs->field_size;
  bool x_is_valid = 0 <= x && x < size.x;
  bool y_is_valid = 0 <= y && y < size.x;
  return x_is_valid && y_is_valid;
}

Cell* field_cell_at(GameState* gs, int x, int y) {
  /* Same as `assert(is_field_coordinate(gs, x, y))` but prints a stack trace if
   * used with the address sanitizer.
   *
   * The stack trace allows you to find out which function call caused the
   * invalid coordinates, which greatly simplifies debugging.
   * (You will probably run into this.)
   *
   * To get the stack trace, we use an ugly hack: if the assertion fails, we
   * simply cause a segmentation fault by writing to the NULL-Pointer, which the
   * address sanitizer then detects and spits out a stack trace for us :3
   */
  if (!is_field_coordinate(gs, x, y)) {
    tui_shutdown();
    printf(FG_RED "ASSERTION FAILED: Coordinate (%d, %d) is not a valid game "
                  "field coordinate.\n\n" COLOR_RESET,
           x, y);
    fflush(stdout);
    int* null = NULL;
    *null = 42;
  }

  return tui_cell_at(x + gs->field_begin.x, y + gs->field_begin.y);
}

void draw_ship(GameState* gs) {
  for (int i = gs->ship.pos.y - 1; i <= gs->ship.pos.y + 1; i++) {
    Cell* pos_1 = field_cell_at(gs, gs->ship.pos.x, i);
    Cell* pos_2 = field_cell_at(gs, gs->ship.pos.x + 1, i);
    Cell* pos_3 = field_cell_at(gs, gs->ship.pos.x + 2, i);
    pos_1->content = '-';
    pos_2->content = '=';
    pos_1->text_color = FG_HI_YELLOW;
    pos_2->text_color = FG_HI_YELLOW;
    pos_3->background_color = BG_HI_CYAN;
  }
  Cell* pos_4 = field_cell_at(gs, gs->ship.pos.x + 3, gs->ship.pos.y);
  Cell* pos_5 = field_cell_at(gs, gs->ship.pos.x + 4, gs->ship.pos.y);
  Cell* pos_6 = field_cell_at(gs, gs->ship.pos.x + 5, gs->ship.pos.y);
  pos_4->background_color = BG_HI_CYAN;
  pos_5->background_color = BG_HI_CYAN;
  pos_6->content = '>';
  pos_6->text_color = FG_HI_YELLOW;
  if (gs->ship.powerup_time > 0) {
    Cell* p_cannon1 = field_cell_at(gs, gs->ship.pos.x + 3, gs->ship.pos.y - 1);
    Cell* p_cannon2 = field_cell_at(gs, gs->ship.pos.x + 3, gs->ship.pos.y + 1);
    p_cannon1->content = '>';
    p_cannon2->content = '>';
    p_cannon1->text_color = FG_HI_YELLOW;
    p_cannon2->text_color = FG_HI_YELLOW;
  }
}

void draw_projectiles(GameState* gs) {
  for (int i = 0; i < vec_length(gs->projectiles); i++) {
    Int2* p = *vec_at(gs->projectiles, i);
    Cell* pos = field_cell_at(gs, p->x, p->y);
    pos->content = '>';
    pos->text_color = FG_HI_RED;
  }
}

void draw_asteroids(GameState* gs) {
  for (int i = 0; i < vec_length(gs->asteroids); i++) {
    Int2* p = *vec_at(gs->asteroids, i);
    Cell* pos = field_cell_at(gs, p->x, p->y);
    pos->background_color = BG_HI_WHITE;
  }
}

void draw_powerups(GameState* gs) {
  for (int i = 0; i < vec_length(gs->powerups); i++) {
    Int2* p = *vec_at(gs->powerups, i);
    Cell* pos = field_cell_at(gs, p->x, p->y);
    pos->content = '@';
    pos->text_color = FG_HI_GREEN;
  }
}

void draw_explosions(GameState* gs) {
  for (int i = 0; i < vec_length(gs->explosions); i++) {
    Explosion* expl = *vec_at(gs->explosions, i);
    int age = expl->age;
    int x = expl->pos.x;
    int y = expl->pos.y;
    if (is_field_coordinate(gs, x, y + age)) {
      Cell* pos_north = field_cell_at(gs, x, y + age);
      pos_north->background_color = BG_HI_RED;
      pos_north->text_color = FG_HI_YELLOW;
      pos_north->content = '#';
    }
    if (is_field_coordinate(gs, x, y - age)) {
      Cell* pos_south = field_cell_at(gs, x, y - age);
      pos_south->background_color = BG_HI_RED;
      pos_south->text_color = FG_HI_YELLOW;
      pos_south->content = '#';
    }
    if (is_field_coordinate(gs, x - (2 * age), y)) {
      Cell* pos_west = field_cell_at(gs, x - (2 * age), y);
      pos_west->background_color = BG_HI_RED;
      pos_west->text_color = FG_HI_YELLOW;
      pos_west->content = '#';
    }
    if (is_field_coordinate(gs, x + (2 * age), y)) {
      Cell* pos_east = field_cell_at(gs, x + (2 * age), y);
      pos_east->background_color = BG_HI_RED;
      pos_east->text_color = FG_HI_YELLOW;
      pos_east->content = '#';
    }
  }
}

bool handle_input(GameState* gs, char c) {
  if (c == 'q')
    return true;
  if (c == 'w') {
    if (gs->ship.pos.y - 1 > gs->field_begin.y) {
      gs->ship.pos.y--;
    }
  } else if (c == 'a') {
    if (gs->ship.pos.x > gs->field_begin.x) {
      gs->ship.pos.x--;
    }
  } else if (c == 's') {
    if (gs->ship.pos.y + 4 < gs->field_end.y) {
      gs->ship.pos.y++;
    }
  } else if (c == 'd') {
    if (gs->ship.pos.x + 8 < gs->field_end.x) {
      gs->ship.pos.x++;
    }
  } else if (c == ' ') {
    Int2* p = malloc(sizeof(Int2));
    p->x = gs->ship.pos.x + 5;
    p->y = gs->ship.pos.y;
    vec_push(gs->projectiles, p);
    if (gs->ship.powerup_time > 0) {
      Int2* p1 = malloc(sizeof(Int2));
      Int2* p2 = malloc(sizeof(Int2));
      p1->x = gs->ship.pos.x + 3;
      p2->x = gs->ship.pos.x + 3;
      p1->y = gs->ship.pos.y - 1;
      p2->y = gs->ship.pos.y + 1;
      vec_push(gs->projectiles, p1);
      vec_push(gs->projectiles, p2);
    }
  }
  return false;
}

/*compares to Int2 and return 1 if they're colliding*/
bool colliding_model(Int2 p1, Int2 p2) {
  if (p1.x == p2.x && p1.y == p2.y) {
    return 1;
  }
  return 0;
}

bool collides_with_ship(Int2 ship_pos, Int2 pos) {
  Int2 pos_1 = {.x = ship_pos.x + 2, .y = ship_pos.y + 1};
  Int2 pos_2 = {.x = ship_pos.x + 4, .y = ship_pos.y};
  Int2 pos_3 = {.x = ship_pos.x + 2, .y = ship_pos.y - 1};
  if (colliding_model(pos_1, pos) == 1) {
    return 1;
  } else if (colliding_model(pos_2, pos) == 1) {
    return 1;
  } else if (colliding_model(pos_3, pos) == 1) {
    return 1;
  } else {
    return 0;
  }
}

void move_projectiles(GameState* gs) {
  size_t i = vec_length(gs->projectiles);
  while (i > 0) {
    i--;
    Int2* p = *vec_at(gs->projectiles, i);
    p->x++;
    if (p->x + 2 > gs->field_end.x) {
      vec_remove(gs->projectiles, i);
    }
  }
}

void move_asteroids(GameState* gs) {
  if (gs->time_step % 5 == 0) {
    size_t i = vec_length(gs->asteroids);
    while (i > 0) {
      i--;
      Int2* p = *vec_at(gs->asteroids, i);
      p->x--;
      if (p->x < gs->field_begin.x) {
        vec_remove(gs->asteroids, i);
      }
    }
  }
}

void move_powerups(GameState* gs) {
  size_t i = vec_length(gs->powerups);
  while (i > 0) {
    i--;
    Int2* p = *vec_at(gs->powerups, i);
    p->x--;
    if (p->x < gs->field_begin.x) {
      vec_remove(gs->powerups, i);
    }
  }
}

void move_explosions(GameState* gs) {
  size_t i = vec_length(gs->explosions);
  while (i > 0) {
    i--;
    Explosion* expl = *vec_at(gs->explosions, i);
    expl->age++;
    if (expl->age >= 5) {
      vec_remove(gs->explosions, i);
    }
  }
}

void spawn_asteroids(GameState* gs) {
  if (gs->time_step % 5 == 0) {
    for (int i = gs->field_begin.y; i < gs->field_end.y - 2; i++) {
      int random = rand() % 50;
      if (random == 0) {
        Int2* pos = malloc(sizeof(Int2));
        pos->x = gs->field_end.x - 2;
        pos->y = i;
        vec_push(gs->asteroids, pos);
      }
    }
  }
}

void spawn_powerups(GameState* gs) {
  int random = rand() % 200;
  if (random == 0) {
    int pos = rand() % (gs->field_end.y - 2 - gs->field_begin.y);
    Int2* powerup = malloc(sizeof(Int2));
    powerup->x = gs->field_end.x - 2;
    powerup->y = pos;
    vec_push(gs->powerups, powerup);
  }
}

void handle_projectile_asteroid_collisions(GameState* gs) {
  // zwei while schleifen ineinander über asteroiden, projektile,
  // mit colliding model überprüfen
  size_t i = vec_length(gs->asteroids);
  while (i > 0) {
    i--;
    Int2* p1 = *vec_at(gs->asteroids, i);
    Int2 p1_adv = {p1->x, p1->y};
    size_t t = vec_length(gs->projectiles);
    while (t > 0) {
      t--;
      Int2* p2 = *vec_at(gs->projectiles, t);
      Int2 p2_adv = {p2->x, p2->y};
      if (colliding_model(p1_adv, p2_adv) == 1) {
        // if (colliding_model({p1->x, p1->y}, {p2->x, p2->y}) == 1) {
        vec_remove(gs->projectiles, t);
        vec_remove(gs->asteroids, i);
        gs->points += 5;
        Explosion* expl = malloc(sizeof(Explosion));
        expl->pos = p2_adv;
        expl->age = 0;
        vec_push(gs->explosions, expl);
      }
    }
  }
}

void handle_powerup_ship_collisions(GameState* gs) {
  size_t i = vec_length(gs->powerups);
  while (i > 0) {
    i--;
    Int2* p = *vec_at(gs->powerups, i);
    Int2 p_adv = {p->x, p->y};
    if (collides_with_ship(gs->ship.pos, p_adv) == 1) {
      vec_remove(gs->powerups, i);
      gs->ship.powerup_time = 1000;
      gs->points += 50;
    }
  }
}

void handle_asteroid_ship_collisions(GameState* gs) {
  size_t i = vec_length(gs->asteroids);
  while (i > 0) {
    i--;
    Int2* p = *vec_at(gs->asteroids, i);
    Int2 p_adv = {p->x, p->y};
    if (collides_with_ship(gs->ship.pos, p_adv) == 1) {
      vec_remove(gs->asteroids, i);
      gs->ship.health--;
      Explosion* expl = malloc(sizeof(Explosion));
      expl->pos = p_adv;
      expl->age = 0;
      vec_push(gs->explosions, expl);
    }
  }
}
