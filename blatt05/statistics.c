#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "./vec.h"

#define SUCCESS 0
#define ERROR_NO_FURTHER_INPUT -1
#define ERROR_STRING_IS_NOT_A_NUMBER -2

int read_int(int *user_input) {
  char *line = NULL;
  size_t line_len = 0;
  ssize_t status = getline(&line, &line_len, stdin);
  if (status < 0) {
    free(line);
    return ERROR_NO_FURTHER_INPUT;
  }
  errno = 0;
  char *end = NULL;
  int i = strtol(line, &end, 10);
  free(line);
  if (errno != 0 || end == line) {
    return ERROR_STRING_IS_NOT_A_NUMBER;
  } else {
    *user_input = i;
    return SUCCESS;
  }
}

int main(int argc, char **argv) {
  Vec *xs = vec_new();
  int *user_input; //= 10;
  int invalid_ctr = 0;
  int reader;
  while (1) {
    reader = read_int(user_input);
    // if (user_input == *(10)) {
    // continue;
    //}
    if (reader == 0) {
      vec_push(xs, *(user_input));
    }
    if (reader == -2) {
      invalid_ctr++;
    } else { // reader == -2
      break;
    }
  }
  printf("Number of data points: %zu\n", vec_length(xs));
  vec_sort(xs);
  printf("Minimum: %d\n", *(vec_at(xs, 0)));
  printf("Lower quartile: %d\n", *(vec_at(xs, ((vec_length(xs) / 4) - 1))));
  printf("Median: %d\n", *(vec_at(xs, ((vec_length(xs) / 2) - 1))));
  printf("Upper quartile: %d\n",
         *(vec_at(xs, (((3 * vec_length(xs)) / 4) - 1))));
  printf("Maximum: %d\n", *(vec_at(xs, (vec_length(xs) - 1))));
  double i = 0;
  for (int a = 0; i < vec_length(xs); a++) {
    i += *(vec_at(xs, i));
  }
  i = i / vec_length(xs);
  printf("Average: %lf\n", i);
  if (invalid_ctr != 0) {
    printf("WARNING: Found %d invalid data points.\n", invalid_ctr);
  }
  return 0;
}
