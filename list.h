
#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include "variant.h"
#include "print.h"

template<typename T> struct list_elem_t {
  T elem;
  list_elem_t<T>* next;
};

template<typename T>
struct list_t {
  list_elem_t<T>*  head;
  list_elem_t<T>** ptail;
};

template<typename T>
void list_init(list_t<T>* list) {
  list->head = nullptr;
  list->ptail = &list->head;
}

template<typename T>
static list_elem_t<T>* make_list_elem(const T& elem, list_elem_t<T>* next) {
  list_elem_t<T>* e = (list_elem_t<T>*)malloc(sizeof(list_elem_t<T>));
  e->elem = elem;
  e->next = next;
  return e;
}

template<typename T>
void list_add_back(list_t<T>* list, const T& elem) {
  list_elem_t<T>* l = make_list_elem<T>(elem, nullptr);
  *list->ptail = l;
  list->ptail = &l->next;
}

template<typename T>
void list_add_front(list_t<T>* list, const T& elem) {
  list_elem_t<T>* l = make_list_elem(elem, list->head);
  list->head = l;
  if (l->next == nullptr) {
    list->ptail = &l->next;
  }
}

template<typename T>
void list_print(const list_t<T>* list) {
  for (const list_elem_t<T>* p = list->head; p != nullptr; p = p->next) {
    print(p->elem);
    if (p->next != nullptr) {
      printf(" -> ");
    } else {
      printf("\n");
    }
  }
}

template<typename T>
static void list_print_reverse_rec(const list_elem_t<T>* p) {
  if (p == nullptr) {
    return;
  }
  list_print_reverse_rec(p->next);
  if (p->next != nullptr) {
    printf(" <- ");
  }
  print(p->elem);
}

template<typename T>
void list_print_reverse(const list_t<T>* list) {
  list_print_reverse_rec(list->head);
  printf("\n");
}

template<typename T>
void list_free(list_t<T>* list) {
  for (list_elem_t<T>* p = list->head; p != nullptr;) {
    list_elem_t<T>* q = p->next;
    free(p);
    p = q;
  }
}

#endif // _LIST_H_
