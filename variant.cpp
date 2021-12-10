#include <stdio.h>
#include "variant.h"

variant_t::variant_t(const char* str) 
    : type(VARIANT_STR) {
  info.str = str;
}

variant_t::variant_t(uint32_t num)
    : type(VARIANT_NUM) {
  info.num = num;
}

variant_t::variant_t(bool bln)
    :type(VARIANT_BLN) {
  info.bln = bln;
}

void variant_t::print() const {
  switch (type) {
    case VARIANT_STR:
      printf("\"%s\"", info.str);
      break;
    case VARIANT_NUM:
      printf("%u", info.num);
      break;
    case VARIANT_BLN:
      printf("%s", info.bln ? "true" : "false");
      break;
  }
} 