#ifndef _PRINT_H_
#define _PRINT_H_

#include <stdint.h>
#include "variant.h"

void print(uint32_t num);
void print(const variant_t& var);

#endif // _PRINT_H_