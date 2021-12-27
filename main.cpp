// g++ -g -Wall -Wextra -O2 -c main.cpp -o main.o && g++ main.o array.o -o main && ./main
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "vector.h"
#include "print_num.h"
#include "variant.h"
#include "print.h"
#include "list.h"
#include "tree.h"


static const uint32_t ARR_SIZE = 5;


int main() {
  printf("Hello World!\n");
  
  /*
        42
        /
       16
      /  \
     8   32
    /    / \
   2    22  40
       / \    \
      21  23   41  
  */

  tree_t<uint32_t> t1;
  t1.add(42);
  t1.add(16);
  t1.add(32);
  t1.add(40);
  t1.add(41);
  t1.add(8);
  t1.add(22);
  t1.add(21);
  t1.add(23);
  t1.add(2);
  t1.print_preorder();
  t1.print_preorder_iterative();
  t1.print_postorder();
  t1.print_postorder_iterative();
  t1.print_inorder();
  t1.print_inorder_iterative();
  t1.print_level_order();
  t1.print_levels();
  
  vector_t<uint32_t> vec1;
  vec1.add_back(36);
  vec1.add_back(13);
  vec1.add_back(53);
  vec1[0] = 23;
  vec1.print();

  variant_t var1("rere");
  variant_t var2(true);
  vector_t<variant_t> vec2(2); 
  vec2.add_back(var1);
  vec2.add_back(var2);
  vec2.add_back(var1);
  vec2.print();

  vector_t<vector_t<uint32_t>> vec_vec(2);
  vec_vec.add_back(vec1);
  vec_vec.add_back(vec1);
  vec_vec.print();
  
  vector_t<vector_t<vector_t<uint32_t>>> vec_vec_vec(2);
  vec_vec_vec.add_back(vec_vec);
  vec_vec_vec.add_back(vec_vec);
  vec_vec_vec.print();

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
  variant_t vnum(56u);
  variant_t vbool(true);
  l2.add_back(vnum);
  l2.add_back(vbool);
  l2.add_front(vnum);
  l2.print();
  l2.print_reverse();
  
  return 0;
}
