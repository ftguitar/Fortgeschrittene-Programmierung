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
  printf("fib(%d) = %d\n", fib, fib_slow(fib));
  return 0;
}
