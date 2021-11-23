#include <stdio.h>

#include "print_num.h"

bool print_num(uint32_t num, const uint32_t base) {
 
  if (base < 2 || base > 36) {
    printf("error: invalid base (expected base 2-36)\n");
    return false;
  }

  char str[65]; 
  
  if (num == 0) {
    str[0] = '0';
    str[1] = 0;
  } else { 
    // determine the length of the number
    uint32_t i = 0;
    for (uint64_t m = num; m != 0; m /= base) {
      ++i;
    }
  
    str[i] = 0;

    const char dgts[] = "0123456789ABCDEFGHJGKLMNOPRSTUVWXYZ";
    // we get the digits of the number and translate them into symbolic representation
    for (uint64_t m = num; m != 0; m /= base) {
      char c = dgts[m % base];
      --i;
      str[i] = c;
    }
  }

  printf("%u (base 10) = %s (base %u)\n", num, str, base);
  return true;
}
