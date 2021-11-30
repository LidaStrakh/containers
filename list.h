#ifndef _LIST_H_
#define _LIST_H_

#include <stdint.h>

struct list_elem_t;

struct list_t {
  list_elem_t*  head;
  list_elem_t** ptail;
};

void list_free(list_t* list);
void list_free_rec(list_t* list);
void list_print(const list_t* list);
void list_print_reverse(const list_t* list);
void list_add_num_back(list_t* list, uint32_t num);
void list_add_num_front(list_t* list, uint32_t num);
void list_add_str_back(list_t* list, const char* str);
void list_add_str_front(list_t* list, const char* str);
void list_add_bln_back(list_t* list, bool bln);
void list_add_bln_front(list_t* list, bool bln);
void list_init(list_t* list);

#endif // _LIST_H_