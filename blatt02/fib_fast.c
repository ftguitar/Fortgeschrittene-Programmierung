#include "./fib_lib.h"
#include "stdio.h"

int read_int() {
  int n;
  scanf("%d", &n);
  return n;
}

int main(void) {
  printf("Input: ");
  int fib = read_int();
  if (fib > 4999) {
    printf("fib(%d) = %d\n", fib, fib_slow(fib));
  }
  printf("fib(%d) = %d\n", fib, fib_fast(fib));
  return 0;
}
