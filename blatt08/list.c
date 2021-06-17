#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./list.h"

struct Node {
  int val;
  Node* prev;
  Node* next;
};

Node* node_next(Node* n) {
  return n->next;
}
Node* node_prev(Node* n) {
  return n->prev;
}
int* node_val(Node* n) {
  return &n->val;
}

struct List {
  Node* first;
  Node* last;
  size_t len;
};

List* list_new(void) {
  List* l = malloc(sizeof(List));
  if (l != NULL) {
    l->len = 0;
    l->first = NULL;
    l->last = NULL;
  } else {
    free(l);
  }
  return l;
}

int list_pop(List* l) {
  if (l->len == 0) {
    return 0;
  } else {
    int result = l->last->val;
    Node* help = l->last->prev;
    free(l->last);
    if (l->len > 1) {
      l->last = help;
      l->last->next = NULL;
    }
    l->len--;
    return 1;
  }
}

void list_free(List* l) {
  int i = 1;
  while (i == 1) {
    i = list_pop(l);
  }
  free(l);
}

Node* list_first(List* l) {
  if (l->len > 0) {
    return l->first;
  } else {
    return NULL;
  }
}
Node* list_last(List* l) {
  if (l->len > 0) {
    return l->last;
  } else {
    return NULL;
  }
}
size_t list_len(List* l) {
  return l->len;
}

void list_push_back(List* l, int val) {
  Node* new = malloc(sizeof(Node));
  if (l->len == 0) {
    l->first = new;
    new->prev = NULL;
  } else {
    new->prev = l->last;
    l->last->next = new;
  }
  new->val = val;
  new->next = NULL;
  l->last = new;
  l->len++;
}

void list_push_front(List* l, int val) {
  Node* new = malloc(sizeof(Node));
  if (l->len == 0) {
    l->last = new;
    new->next = NULL;
  } else {
    new->next = l->first;
    l->first->prev = new;
  }
  new->val = val;
  new->prev = NULL;
  l->first = new;
  l->len++;
}

int list_pop_back(List* l) {
  if (l->len == 0) {
    return NULL;
  } else {
    int result = l->last->val;
    Node* help = l->last->prev;
    free(l->last);
    if (l->len > 1) {
      l->last = help;
      l->last->next = NULL;
    }
    l->len--;
    return result;
  }
}

int list_pop_front(List* l) {
  if (l->len == 0) {
    return NULL;
  } else {
    int result = l->first->val;
    Node* help = l->first->next;
    free(l->first);
    if (l->len > 1) {
      l->first = help;
      l->first->prev = NULL;
    }
    l->len--;
    return result;
  }
}
