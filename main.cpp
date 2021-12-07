// g++ -g -Wall -Wextra -O2 -c main.cpp -o main.o && g++ main.o array.o -o main && ./main
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "array.h"
#include "print_num.h"
#include "variant.h"
#include "print.h"
#include "list.h"

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

  list_t<uint32_t> l1;
  list_init(&l1);
  list_add_back(&l1, 18u);
  list_add_back(&l1, 23u);
  list_add_back(&l1, 47u);
  list_add_front(&l1, 34u);
  list_print(&l1);
  list_print_reverse(&l1);
  list_free(&l1);

  list_t<variant_t> l2;
  list_init(&l2);
  variant_t vnum;
  init_variant_number(&vnum, 56);
  variant_t vbool;
  init_variant_bool(&vbool, true);
  list_add_back(&l2, vnum);
  list_add_back(&l2, vbool);
  list_add_front(&l2, vnum);
  list_print(&l2);
  list_print_reverse(&l2);
  list_free(&l2);
  
  return 0;
}
