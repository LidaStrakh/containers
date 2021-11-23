#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "array.h"
#include "list.h"
#include "print_num.h"

static const uint32_t ARR_SIZE = 5;

int main() {
  printf("Hello World!\n");
  
  uint32_t arr[ARR_SIZE] = {1, 34, 78, 6, 23};
  
  uint32_t len1 = 5;
  uint32_t *arr1 = (uint32_t*)malloc(sizeof(uint32_t) * len1);
  memcpy(arr1, arr, sizeof(uint32_t) * len1);

  print_array(arr, ARR_SIZE);
  print_array(arr1, len1);
  
  free(arr1);
  
  uint32_t num = 56;
  const uint32_t base = 10;
  print_num(num, base);

  list_t l; 
  list_init(&l);
  
  for (uint32_t n = 32; n != 53; ++n) {
    list_add_back(&l, n);
  }
  
  list_add_back(&l, 53);
  list_add_back(&l, 6);
  list_add_front(&l, 2);

  list_print(&l);
  list_print_reverse(&l);

  list_free_rec(&l);

  return 0;
}
