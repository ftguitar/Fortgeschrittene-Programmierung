#include "./fib_lib.h"

int fib_slow(int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  if (n >= 2) {
    return fib_slow(n - 1) + fib_slow(n - 2);
  }
  return 0;
}

int fib_fast(int n) {
  int cache[5000];
  cache[0] = 0;
  cache[1] = 1;
  for (int point = 2; point <= n; point++) {
    cache[point] = cache[point - 1] + cache[point - 2];
  }
  return cache[n];
}
