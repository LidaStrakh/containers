#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list_elem_t {
  uint32_t     elem;
  list_elem_t* next;
};

void list_free(list_t* list) {
  for (list_elem_t* p = list->head; p != nullptr;) {
    list_elem_t* q = p->next;
    free(p);
    p = q;
  }
}

static void do_list_free_rec(list_elem_t* p) {
  if (p == nullptr) {
    return;
  }
  do_list_free_rec(p->next);
  free(p);
}

void list_free_rec(list_t* list) {
  do_list_free_rec(list->head);
}


void list_print(const list_t* list) {
  for (const list_elem_t* p = list->head; p != nullptr; p = p->next) {
    printf("%u", p->elem);
    if (p->next != nullptr) { 
      printf(" -> ");
    } else {
      printf("\n");
    }
  }
}

static void list_print_reverse_rec(const list_elem_t* p) {
  if (p == nullptr) {
    return;
  } 
  list_print_reverse_rec(p->next);
  if (p->next != nullptr) {
    printf(" <- ");
  }
  printf("%u", p->elem);
}

void list_print_reverse(const list_t* list) {
  list_print_reverse_rec(list->head);
  printf("\n");
}

static list_elem_t* make_list_elem(uint32_t elem, list_elem_t* next) {
  list_elem_t* e = (list_elem_t*)malloc(sizeof(list_elem_t));
  e->elem = elem;
  e->next = next;
  return e;
}

void list_add_back(list_t* list, uint32_t elem) {
  list_elem_t* l = make_list_elem(elem, nullptr);
  *list->ptail = l;
  list->ptail = &l->next;
}

void list_add_front(list_t* list, uint32_t elem) {
  list_elem_t* l = make_list_elem(elem, list->head);
  list->head = l;
  if (l->next == nullptr) {
    list->ptail = &l->next;
  }
}

void list_init(list_t* list) {
  list->head = nullptr;
  list->ptail = &list->head;
}