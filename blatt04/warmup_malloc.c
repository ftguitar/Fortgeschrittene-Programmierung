#include "../unity/unity.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*____________________________________________
 * TestSetup
 */

void setUp(void) {}

void tearDown(void) {}

/* ____________________________________________
 * Aufgabenteil (a), alte fib_fast:

 * int fib_fast(int n) {
 *   if (n >= 5000) {
 *      return fib_slow(n);
 *   }
 *   int cache[5000];
 *   cache[0] = 0;
 *   cache[1] = 1;
 *   for (int i = 2; i <= n; ++i) {
 *     cache[i] = cache[i - 1] + cache[i - 2];
 *   }
 *   return cache[n];
 *   }
 */

int fib_fast(int n) {
  int *cache = malloc(n * sizeof(int));
  cache[0] = 0;
  cache[1] = 1;
  for (int i = 2; i <= n; ++i) {
    cache[i] = cache[i - 1] + cache[i - 2];
  }
  int returner = cache[n];
  free(cache);
  return returner;
}

void test_fib_fast_0(void) { TEST_ASSERT_EQUAL(0, fib_fast(0)); }

void test_fib_fast_1(void) { TEST_ASSERT_EQUAL(1, fib_fast(1)); }

void test_fib_fast_10(void) { TEST_ASSERT_EQUAL(55, fib_fast(10)); }

/*____________________________________________
 * Aufgabenteil (b)
 */

char *repeat(size_t n, char *s) {
  size_t a = n * strlen(s) + 1;
  int ptr = 0;
  int lenstr = strlen(s);
  int strptr = 0;
  char *output = malloc(a * sizeof(char));
  while (ptr < (a - 1)) {
    output[ptr] = s[strptr];
    ptr++;
    strptr++;
    if (strptr >= lenstr) {
      strptr = 0;
    }
  }
  char *final = output;
  free(output);
  return final;
}

void test_repeat(void) {
  TEST_ASSERT(0 == strcmp("foofoofoo", repeat(3, "foo")));
}

/*____________________________________________
 * Aufgabenteil (c)
 *__________________________________________*/

char *join(char **strings, size_t num_strings, char *separator) {
  size_t lenstr = 1 + ((num_strings - 1) * strlen(separator));
  for (int i; i < num_strings; i++) {
    lenstr += strlen(strings[i]);
  }
  char *output = malloc(lenstr * sizeof(char));
  int ptr = 0;
  int strptr = 0;
  int inner_strptr = 0;
  while (ptr < (lenstr - 1)) {
    output[ptr] = strings[strptr][inner_strptr];
    ptr++;
    inner_strptr++;
    if (inner_strptr >= strlen(strings[strptr])) {
      if (strptr == (num_strings - 1)) {
        break;
      }
      int sep_ctr = 0;
      int sep_len = strlen(separator);
      while (sep_ctr < sep_len) {
        output[ptr] = separator[sep_ctr];
        ptr++;
        sep_ctr++;
      }
      strptr++;
      inner_strptr = 0;
    }
  }
  char *result = output;
  free(output);
  return result;
}

void test_join(void) {
  char *strings[] = {"Help!", "I'm split into", "mulitple", "strings!"};
  char *result = "Help! * I'm split into * mulitple * strings!";
  TEST_ASSERT(0 == strcmp(result, join(strings, 4, " * ")));
}

/*____________________________________________
 * Aufgabenteil (d)
 * _________________________________________*/

char *find_quoted(char *s) {
  int ptr_begin = 0;
  int ptr_end = 1;
  bool if_find_beg1 = true;
  bool if_find_beg2 = true;
  for (int i = 0; i < strlen(s); i++) {
    if (if_find_beg1 == true && s[i] == '\"') {
      ptr_begin = i + 1;
      if_find_beg1 = false;
      i++;
    }
    if (s[i] == '\"') {
      ptr_end = i;
      if_find_beg2 = false;
      break;
    }
  }
  char *result = NULL;
  if (if_find_beg2 == false) {
    char *s_new = malloc(((ptr_end - ptr_begin) + 1) * sizeof(char));
    for (int i = 0; i < (ptr_end - ptr_begin); i++) {
      s_new[i] = s[ptr_begin + i];
    }

    result = s_new;
    free(s_new);
  }
  return result;
}

void test_find_quoted(void) {
  TEST_ASSERT(0 == strcmp("bar", find_quoted("foo\"bar\" baz \"boo")));
}

void test_find_quoted2(void) { TEST_ASSERT(NULL == find_quoted("foo \"bar")); }

/*____________________________________________
 * main-Function
 *__________________________________________*/

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_fib_fast_1);
  RUN_TEST(test_fib_fast_0);
  RUN_TEST(test_fib_fast_10);
  RUN_TEST(test_repeat);
  printf("foofoofoo,\n%s\n", repeat(3, "foo"));
  RUN_TEST(test_join);
  RUN_TEST(test_find_quoted);
  printf("bar\n%s\n", find_quoted("foo\"bar\" baz \"boo"));
  RUN_TEST(test_find_quoted2);
  return UNITY_END();
}
