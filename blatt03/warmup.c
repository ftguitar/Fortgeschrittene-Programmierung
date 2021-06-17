#include "stdio.h"

int my_strlen(char *s) {
  int str_counter = 0;
  int pos_counter = 0;
  while (s[pos_counter] != 0) {
    str_counter++;
    pos_counter++;
  }
  return str_counter;
}

int my_strcmp(char *s1, char *s2) {
  if (my_strlen(s1) != my_strlen(s2)) {
    return 1;
  }
  for (int i = 0; i < my_strlen(s1); i++) {
    if (s1[i] != s2[i]) {
      return 1;
    }
  }
  return 0;
}

/* _____________________________________
 * Tests + Testsetup + main-func
 */
#include "../unity/unity.h"
void setUp(void) {}

void tearDown(void) {}

void test_my_strlen_1(void) { TEST_ASSERT_EQUAL(3, my_strlen("foo")); }

void test_my_strlen_2(void) { TEST_ASSERT_EQUAL(6, my_strlen("foobar")); }

void test_my_strcmp_1(void) {
  TEST_ASSERT_EQUAL(1, my_strcmp("foobar", "foo"));
}

void test_my_strcmp_2(void) {
  TEST_ASSERT_EQUAL(1, my_strcmp("foobar", "futsal"));
}

void test_my_strcmp_3(void) {
  TEST_ASSERT_EQUAL(0, my_strcmp("foobar", "foobar"));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_my_strlen_1);
  RUN_TEST(test_my_strlen_2);
  RUN_TEST(test_my_strcmp_1);
  RUN_TEST(test_my_strcmp_2);
  RUN_TEST(test_my_strcmp_3);
  return UNITY_END();
}
