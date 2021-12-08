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
  l1.add_back(18u);
  l1.add_back(23u);
  l1.add_back(47u);
  l1.add_front(34u);
  l1.print();
  l1.print_reverse();

  list_t<variant_t> l2;
  variant_t vnum;
  init_variant_number(&vnum, 56);
  variant_t vbool;
  init_variant_bool(&vbool, true);
  l2.add_back(vnum);
  l2.add_back(vbool);
  l2.add_front(vnum);
  l2.print();
  l2.print_reverse();
  
  return 0;
}
