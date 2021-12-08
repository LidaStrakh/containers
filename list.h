
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
static list_elem_t<T>* make_list_elem(const T& elem, list_elem_t<T>* next) {
  list_elem_t<T>* e = (list_elem_t<T>*)malloc(sizeof(list_elem_t<T>));
  e->elem = elem;
  e->next = next;
  return e;
}

template<typename T>
class list_t {
private:
  list_elem_t<T>*  head;
  list_elem_t<T>** ptail;

  void print_reverse_rec(const list_elem_t<T>* p) const;

public:
  list_t(): head(nullptr), ptail(&this->head) {}
  ~list_t();
  void add_back(const T& elem);
  void add_front(const T& elem);
  void print() const;
  void print_reverse() const;
};

template<typename T>
list_t<T>::~list_t() {
  for (list_elem_t<T>* p = this->head; p != nullptr;) {
    list_elem_t<T>* q = p->next;
    free(p);
    p = q;
  }
}

template<typename T>
void list_t<T>::add_back(const T& elem) {
  list_elem_t<T>* l = make_list_elem<T>(elem, nullptr);
  *this->ptail = l;
  this->ptail = &l->next;
}

template<typename T>
void list_t<T>::add_front(const T& elem) {
  list_elem_t<T>* l = make_list_elem(elem, this->head);
  this->head = l;
  if (l->next == nullptr) {
    this->ptail = &l->next;
  }
}

template<typename T>
void list_t<T>::print() const {
  for (const list_elem_t<T>* p = this->head; p != nullptr; p = p->next) {
    ::print(p->elem);
    if (p->next != nullptr) {
      printf(" -> ");
    } else {
      printf("\n");
    }
  }
}

template<typename T>
void list_t<T>::print_reverse_rec(const list_elem_t<T>* p) const {
  if (p == nullptr) {
    return;
  }
  print_reverse_rec(p->next);
  if (p->next != nullptr) {
    printf(" <- ");
  }
  ::print(p->elem);
}

template<typename T>
void list_t<T>::print_reverse() const {
  print_reverse_rec(this->head);
  printf("\n");
}

#endif // _LIST_H_
