#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include "print.h"

template<typename T>
class vector_t {
private:
  T* elements_;
  size_t capacity_;
  size_t size_;
public:
  vector_t(): elements_(nullptr), capacity_(0), size_(0) {}
  vector_t(size_t cap)
    : elements_((T*)malloc(cap*sizeof(T)))
    , capacity_(cap)
    , size_(0)
  {}

  ~vector_t() {
    free(elements_);
  };

  size_t size() const {return size_;}

  const T& operator[](size_t index) const;
  const T& front() const;
  const T& back() const;
  T& operator[](size_t index);
  void add_back(const T& elem);
  void clear();
  void remove_back();
  bool empty() const;
  void print() const;
  T min_element() const;
  T max_element() const;
  void bubble_sort();
};

template<typename T>
const T& vector_t<T>::operator[](size_t index) const {
  assert(index < size_);
  return elements_[index];
}

template<typename T>
T& vector_t<T>::operator[](size_t index) {
  assert(index < size_);
  return elements_[index];
}

template<typename T>
const T& vector_t<T>::back() const {
  assert(size_ != 0);
  return elements_[size_ - 1];
}

template<typename T>
const T& vector_t<T>::front() const {
  assert(size_ != 0);
  return elements_[0];
}

template<typename T>
void vector_t<T>::add_back(const T& elem) {
  if (capacity_ <= size_) {
    size_t new_capacity = capacity_ == 0 ? 1 : capacity_ * 2;
    T* new_elements = (T*)malloc(new_capacity*sizeof(T)); 
    for (size_t i = 0; i != size_; ++i) {
      new_elements[i] = elements_[i];
    }
    free(elements_);
    elements_ = new_elements;
    capacity_ = new_capacity;
  }
  elements_[size_] = elem;
  ++size_;
}

template<typename T>
void vector_t<T>::clear() {
  size_ = 0;
}

template<typename T>
void vector_t<T>::remove_back() {
  assert(size_ != 0);
  --size_;
}

template<typename T>
bool vector_t<T>::empty() const {
  return size_ == 0;
}

template<typename T>
void print(const vector_t<T>& vec) {
  vec.print();
}

template<typename T>
void vector_t<T>::print() const {
  printf("{");
  for (uint32_t i = 0; i < size_; ++i) {
    ::print(elements_[i]);
    if (i < size_ - 1) {
      printf(", ");
    }
  }
  printf("}\n");
}

template<typename T>
T vector_t<T>::min_element() const {
  assert(!empty());
  T min = elements_[0];
  for (size_t i = 1; i < size(); ++i) {
    const T& e = elements_[i];
    if (e < min) {
      min = e;
    }
  }
  return min;
}

template<typename T>
T vector_t<T>::max_element() const {
  assert(!empty());
  T max = elements_[0];
  for (size_t i = 1; i < size(); ++i) {
    const T& e = elements_[i];
    if (max < e) {
      max = e;
    }
  }
  return max;
}

template<typename T>
void swap(T& x, T& y) {
  T tmp = x;
  x = y;
  y = tmp;
}

// Bubble sort has complexity O(n^2) where n is the size of the array.
// The index of the outer loop changes from size down to 2. For every
// iteration of the outer loop the inner loop iterates from 1 up to
// the index of the outer loop. Therefore the total number of iterations
// can be counted as:
//  1 + 2 + 3 + ... + (n - 2) + (n - 1) =
//    = (1 + (n - 1)) + (2 + (n - 2)) + ... =
//    = n*(n-1)/2
template<typename T>
void vector_t<T>::bubble_sort() {
  for (size_t j = size(); j > 1; --j) {
    for (size_t i = 1; i < j; ++i) {
      if (elements_[i] < elements_[i - 1]) {
        swap(elements_[i], elements_[i - 1]);
      }
    }
  }
}

#endif // _VECTOR_H_
