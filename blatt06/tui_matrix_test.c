#include "../unity/unity.h"

#include "./ansi_codes.h"
#include "./tui_matrix.h"

void setUp(void) {
}
void tearDown(void) {
}

void test_matrix_alloc(void) {
  Cell def = (Cell){
      .content = '.', .text_color = FG_WHITE, .background_color = BG_BLACK};
  Matrix* matrix = matrix_new(3, 3, &def);
  TEST_ASSERT_EQUAL_INT(matrix_width(matrix), 3);
  TEST_ASSERT_EQUAL_INT(matrix_height(matrix), 3);
  matrix_free(matrix);
}

void test_matrix_cell_at(void) {
  Cell def = (Cell){
      .content = '.', .text_color = FG_WHITE, .background_color = BG_BLACK};
  Matrix* matrix = matrix_new(3, 3, &def);
  Cell* cell_at = matrix_cell_at(matrix, 1, 1);
  printf("%c\n", def.content);

  printf("%c\n", (cell_at->content));
  TEST_ASSERT_EQUAL(cell_at->content, '.');
  matrix_free(matrix);
}

void test_matrix_clear_with(void) {
  Cell def = (Cell){
      .content = '.', .text_color = FG_WHITE, .background_color = BG_BLACK};
  Matrix* matrix = matrix_new(3, 3, &def);
  Cell repl = (Cell){
      .content = 'x', .text_color = FG_WHITE, .background_color = BG_BLACK};
  matrix_clear_with(matrix, &repl);
  Cell* cell_at = matrix_cell_at(matrix, 1, 1);
  TEST_ASSERT_EQUAL(cell_at->content, 'x');
  matrix_free(matrix);
}

void test_matrix_clear(void) {
  Cell def = (Cell){
      .content = '.', .text_color = FG_WHITE, .background_color = BG_BLACK};
  Matrix* matrix = matrix_new(3, 3, &def);
  matrix_clear(matrix);
  Cell* cell_at = matrix_cell_at(matrix, 1, 1);
  TEST_ASSERT_EQUAL(cell_at->content, ' ');
  matrix_free(matrix);
}

void test_matrix_resize(void) {
  Cell def = (Cell){
      .content = '.', .text_color = FG_WHITE, .background_color = BG_BLACK};
  Cell repl = (Cell){
      .content = 'x', .text_color = FG_WHITE, .background_color = BG_BLACK};
  Matrix* matrix = matrix_new(3, 3, &def);
  matrix_resize(matrix, 5, 5, &repl);
  Cell* cell_at = matrix_cell_at(matrix, 4, 4);
  TEST_ASSERT_EQUAL(cell_at->content, 'x');
  matrix_free(matrix);
}

int main(void) {
  Cell def = (Cell){
      .content = '.', .text_color = FG_WHITE, .background_color = BG_BLACK};
  Cell repl = (Cell){
      .content = 'x', .text_color = FG_WHITE, .background_color = BG_BLACK};
  Matrix* matrix = matrix_new(3, 3, &def);
  Matrix* ma = matrix_new(3, 3, &repl);
  matrix_print_update(matrix, ma);
  matrix_free(ma);
  matrix_free(matrix);
  UNITY_BEGIN();
  RUN_TEST(test_matrix_alloc);
  RUN_TEST(test_matrix_cell_at);
  RUN_TEST(test_matrix_clear_with);
  RUN_TEST(test_matrix_clear);
  RUN_TEST(test_matrix_resize);
  return UNITY_END();
}
