#include "../unity/unity.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/* ______________________________________
 * Test SetUp
 * ____________________________________*/

void setUp(void) {}

void tearDown(void) {}

/* ______________________________________
 * Aufgabenteil (a)
 * ____________________________________*/

int add_3(int i) {
  i += 3;
  return i;
}

void test_add_3(void) { TEST_ASSERT_EQUAL(8, add_3(5)); }

void assign_add_3(int *j) { *j = *j + 3; }

void test_assign_add_3(void) {
  int j = 5;
  assign_add_3(&j);
  TEST_ASSERT_EQUAL(8, j);
}

/* _______________________________________
 * Aufgabenteil (b)
 * _____________________________________*/

struct Point {
  int x;
  int y;
};

/* ________________________________________
 * Aufgabenteil (c)
 * ______________________________________*/

struct Point add_point(struct Point p1, struct Point p2) {
  struct Point p3 = {(p1.x + p2.x), (p1.y + p2.y)};
  return p3;
}

void test_add_point(void) {
  struct Point p1 = {1, 2};
  struct Point p2 = {10, 20};
  struct Point p3 = add_point(p1, p2);
  TEST_ASSERT_EQUAL(11, p3.x);
  TEST_ASSERT_EQUAL(22, p3.y);
}

void add_assign_point(struct Point *p1, struct Point p2) {
  (*p1).x += p2.x;
  (*p1).y += p2.y;
}

void test_add_assign_point(void) {
  struct Point p1 = {1, 2};
  struct Point p2 = {10, 20};
  add_assign_point(&p1, p2);
  TEST_ASSERT_EQUAL(11, p1.x);
  TEST_ASSERT_EQUAL(22, p1.y);
}

/* __________________________________________
 * Aufgabenteil (d)
 * ________________________________________*/

char *find_char(char c, char *s) {
  char *ptr = s;
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == c) {
      ptr += i;
      return ptr;
    }
  }
  ptr = NULL;
  return ptr;
}

void test_find_char1(void) {
  char *s = "foo";
  char *c2 = find_char('x', s);
  TEST_ASSERT_EQUAL(c2, NULL);
}

void test_find_char2(void) {
  char *s = "foo";
  char *c1 = find_char('o', s);
  TEST_ASSERT_EQUAL(c1, s + 1);
}

/* ____________________________________
 * Main-Function
 * __________________________________*/

int main(int argc, char **argv) {
  UNITY_BEGIN();
  RUN_TEST(test_add_3);
  RUN_TEST(test_assign_add_3);
  RUN_TEST(test_add_point);
  RUN_TEST(test_add_assign_point);
  RUN_TEST(test_find_char1);
  RUN_TEST(test_find_char2);
  return UNITY_END();
}
