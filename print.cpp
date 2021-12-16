#include <stdio.h>
#include "print.h"
#include "variant.h"

void print(uint32_t num) {
  printf("%u", num);
}

void print(const variant_t& var) {
  var.print();
}

void print(const void* ptr) {
  printf("%p", ptr);
}
