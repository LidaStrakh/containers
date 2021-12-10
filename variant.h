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

class variant_t {
private:
  variant_type_t type;
  variant_info_t info; 
public:
  variant_t(const char* str);
  variant_t(uint32_t num);
  variant_t(bool bln);
  void print() const;
}; 

#endif // _VARIANT_H_
