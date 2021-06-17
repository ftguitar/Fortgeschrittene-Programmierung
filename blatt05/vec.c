#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./vec.h"

struct Vec {
  int *data;       /* dynamic memory area containing the integers */
  size_t length;   /* how many integers are currently stored in data */
  size_t capacity; /* how many integers can be stored in data */
};

Vec *vec_new() {
  Vec *r = malloc(sizeof(Vec)); // initialize vector
  if (r != NULL) {              // check if we still have memory
    r->length = 0;              // initialize length to 0
    r->capacity = 1;            // initialize capacity to 1
    r->data = malloc(1 * sizeof(int));
    if (r->data == NULL) {
      free(r);
      free(r->data);
      r = NULL;
      return r;
    }
  } else { // if we're running out of memory
    free(r);
    r = NULL;
  }
  return r;
}

void vec_free(Vec *xs) {
  if (xs != NULL) {
    free(xs->data);
    free(xs);
  }
}

int *vec_at(Vec *xs, size_t i) {
  int *r = xs->data + i;
  return r;
}

size_t vec_length(Vec *xs) {
  size_t r = xs->length;
  return r;
}

size_t vec_capacity(Vec *xs) {
  size_t r = xs->capacity;
  return r;
}

bool vec_push(Vec *xs, int x) {
  bool r = 0;
  if (xs->length < xs->capacity) { // still free capacity in allocated vec
    *(xs->data + xs->length) = x;
    xs->length++;
    r = 1;
  } else { // new capacity has to be allocated before pushing x to the Vec
    xs->capacity = xs->capacity * 2;
    xs->data = realloc(xs->data, (xs->capacity) * sizeof(int));
    if (xs->data == NULL) { // check if we run out memory
      return r;
    }
    *(xs->data + xs->length) = x;
    xs->length++;
    r = 1;
  }
  return r;
};

void vec_pop(Vec *xs) {
  if (xs->length == 0) { // check wether xs contain any elements
    return;
  }
  xs->length--;
  if (xs->length <= (xs->capacity / 2)) { // check if we can save memory
    if (xs->capacity == 1) {
      return;
    }
    xs->capacity = xs->capacity / 2;
    xs->data = realloc(xs->data, (xs->capacity) * sizeof(int));
  }
}

void swap_int(int *xs, int *y) {
  int *help = xs;
  xs = y;
  y = help;
}

int *vec_min_between(Vec *xs, size_t from, size_t to) {
  int *ptr_to_min = (xs->data + from);
  for (int i = 0; i < (to - from);
       i++) { // check if x smaller than *(ptr_to_min)
    if (*(ptr_to_min) < *(xs->data + i)) {
      ptr_to_min = xs->data + i;
    } else {
      continue;
    }
  }
  return ptr_to_min;
}

void vec_sort(Vec *xs) {
  for (int i = 0; i < xs->length; i++) {
    swap_int((xs->data + i), vec_min_between(xs, i, xs->length));
  }
}

void vec_print(Vec *xs) {
  printf("Vector at address %p has %lu elements and capacity %lu.\n", xs,
         xs->length, xs->capacity);
  if (xs->length == 0) {
    return;
  }
  for (int i = 0; i < xs->length; i++) {
    printf("vec[%d] = %d (address %p)\n", i, *(xs->data + i), xs->data + i);
  }
}
/*
int main(int argc, char **argv) {
  Vec *xs = vec_new();
  vec_print(xs);
  for (size_t i = 0; i < 9; ++i) {
    vec_push(xs, i * 10);
    vec_print(xs);
  }
  for (size_t i = 0; i < 9; ++i) {
    vec_pop(xs);
    vec_print(xs);
  }
  vec_free(xs);
  return 0;
}
*/
