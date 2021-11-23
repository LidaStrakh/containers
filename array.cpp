#include <stdio.h>
#include "array.h"

void print_array(const uint32_t* arr, uint32_t len) {
  printf("{");
  for (uint32_t i = 0; i < len; ++i) {
    printf("%u", arr[i]);
    if (i < len - 1) {
      printf(", ");
    }
  }
  printf("}\n");
} 
