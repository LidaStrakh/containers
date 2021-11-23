#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "array.h"

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

  return 0;
}
