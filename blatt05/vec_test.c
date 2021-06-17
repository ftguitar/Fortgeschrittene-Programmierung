#include "../unity/unity.h"
#include "./vec.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setUp(void) {}

void tearDown(void) {}

void test_vec_at(void) {
  Vec *xs = vec_new();
  vec_push(xs, 42);
  TEST_ASSERT_EQUAL(vec_at(xs, 1), 1 + vec_at(xs, 0));
  vec_free(xs);
}

void test_vec_length(void) {
  Vec *xs = vec_new();
  TEST_ASSERT_EQUAL(0, vec_length(xs));
  vec_free(xs);
}

void test_vec_capacity(void) {
  Vec *xs = vec_new();
  TEST_ASSERT_EQUAL(1, vec_capacity(xs));
  vec_free(xs);
}

void test_vec_push(void) {
  Vec *xs = vec_new();
  TEST_ASSERT_EQUAL(1, vec_push(xs, 42));
  vec_free(xs);
}

void test_vec_pop_1(void) {
  Vec *xs = vec_new();
  vec_pop(xs);
  TEST_ASSERT_EQUAL(0, vec_length(xs));
  vec_free(xs);
}

void test_vec_pop_2(void) {
  Vec *xs = vec_new();
  vec_push(xs, 42);
  vec_push(xs, 666);
  vec_pop(xs);
  TEST_ASSERT_EQUAL(1, vec_length(xs));
  vec_free(xs);
}

void test_vec_min_between(void) {
  Vec *xs = vec_new();
  for (int i = 4; i >= 0; i--) {
    vec_push(xs, i);
  }
  TEST_ASSERT_EQUAL(vec_at(xs, 0), vec_min_between(xs, 0, 4));
  vec_free(xs);
}

void test_vec_sort(void) {
  Vec *xs = vec_new();
  for (int i = 4; i >= 0; i--) {
    vec_push(xs, i);
  }
  vec_sort(xs);
  TEST_ASSERT_EQUAL(vec_at(xs, 0), vec_min_between(xs, 0, 4));
  vec_free(xs);
}

int main(int argc, char **argv) {
  UNITY_BEGIN();
  RUN_TEST(test_vec_at);
  RUN_TEST(test_vec_length);
  RUN_TEST(test_vec_capacity);
  RUN_TEST(test_vec_push);
  RUN_TEST(test_vec_pop_1);
  RUN_TEST(test_vec_pop_2);
  RUN_TEST(test_vec_min_between);
  RUN_TEST(test_vec_sort);
  return UNITY_END();
}
