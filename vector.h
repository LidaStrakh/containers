#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <stdint.h>
#include <stdio.h>
#include "print.h"

template<typename T>
class vector_t {
private:
  T* elements;
  size_t capacity;
  size_t size;
public:
  vector_t(): elements(nullptr), capacity(0), size(0) {}
  vector_t(size_t cap)
    : elements((T*)malloc(cap*sizeof(T)))
    , capacity(cap)
    , size(0)
  {}

  ~vector_t() {
    free(elements);
  };

  void add_back(const T& elem);
  void print() const;
};

template<typename T>
void vector_t<T>::add_back(const T& elem) {
  if (capacity <= size) {
    size_t new_capacity = capacity == 0 ? 1 : capacity * 2; 
    T* new_elements = (T*)malloc(new_capacity*sizeof(T)); 
    for (size_t i = 0; i != size; ++i) {
      new_elements[i] = elements[i];
    }
    free(elements);
    elements = new_elements;
    capacity = new_capacity;
  }
  elements[size] = elem;
  ++size;
}

template<typename T>
void print(const vector_t<T>& vec) {
  vec.print();
}

template<typename T>
void vector_t<T>::print() const {
  printf("{");
  for (uint32_t i = 0; i < size; ++i) {
    ::print(elements[i]);
    if (i < size - 1) {
      printf(", ");
    }
  }
  printf("}\n");
}

#endif // _VECTOR_H_
