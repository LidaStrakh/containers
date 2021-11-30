#ifndef _VARIANT_H_
#define _VARIANT_H_

#include <stdint.h>


enum variant_type_t {
  VARIANT_STR,
  VARIANT_NUM,
  VARIANT_BLN
};

union variant_info_t {
  const char* str;
  uint32_t num;
  bool bln;
};

struct variant_t {
  variant_type_t type;
  variant_info_t info; 
}; 

void variant_print(const variant_t* var);
void init_variant_string(variant_t* pvar, const char* str);
void init_variant_number(variant_t* pvar, uint32_t num);
void init_variant_bool(variant_t* pvar, bool bln);

#endif // _VARIANT_H_
