#include <stdio.h>
#include "variant.h"

void init_variant_string(variant_t* pvar, const char* str) {
  pvar->type = VARIANT_STR;
  pvar->info.str = str;
}

void init_variant_number(variant_t* pvar, uint32_t num) {
  pvar->type = VARIANT_NUM;
  pvar->info.num = num;
}

void init_variant_bool(variant_t* pvar, bool bln) {
  pvar->type = VARIANT_BLN;
  pvar->info.bln = bln;
}

void variant_print(const variant_t* var) {
  switch (var->type) {
    case VARIANT_STR:
      printf("\"%s\"", var->info.str);
      break;
    case VARIANT_NUM:
      printf("%u", var->info.num);
      break;
    case VARIANT_BLN:
      printf("%s", var->info.bln ? "true" : "false");
      break;
  }
} 