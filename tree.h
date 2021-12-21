#ifndef _TREE_H_
#define _TREE_H_

#include "vector.h"

template<typename T>
class tree_elem_t {
public:
  T elem;
  tree_elem_t* left;
  tree_elem_t* right;
  tree_elem_t(const T& t): elem(t), left(nullptr), right(nullptr) {}
};

template<typename T>
class tree_t {
private:
  tree_elem_t<T>* root;
  size_t size_;
public:
  tree_t(): root(nullptr), size_(0) {}
  ~tree_t();
  size_t size() const;
  void add(const T& elem); 
  void print_preorder() const;
  void print_postorder() const;
  void print_inorder() const;
  void print_preorder_iterative() const;
  void print_postorder_iterative() const;
};

template<typename T>
void free_rec(tree_elem_t<T>* node) {
  if (node == nullptr) {
    return;
  }
  free_rec(node->left);
  free_rec(node->right);
  delete node;
}

template<typename T>
tree_t<T>::~tree_t() {
  free_rec(root);
}

template<typename T>
void tree_t<T>::add(const T& elem) {
  tree_elem_t<T>* node = new tree_elem_t<T>(elem);
  ++size_;
  if (root == nullptr) {
    root = node;
  } else {
    for (tree_elem_t<T>* p = root;;){
      if (elem < p->elem) {
          if (p->left == nullptr){
          p->left = node;
          break;
        }
        p = p->left;
      } else {
        if (p->right == nullptr){
          p->right = node;
          break;
        }
        p = p->right;
      }
    } 
  }
}

template<typename T>
size_t tree_t<T>::size() const {
  return size_;
}

template<typename T>
void tree_print_preorder(const tree_elem_t<T>* node) {
  if (node == nullptr) {
    return;
  }
  print(node->elem);
  printf(" ");
  tree_print_preorder(node->left);
  tree_print_preorder(node->right);
} 

template<typename T>
void tree_t<T>::print_preorder() const {
  printf("Tree preorder: ");
  tree_print_preorder(root);
  printf("\n");
}

template<typename T>
void tree_print_postorder(const tree_elem_t<T>* node) {
  if (node == nullptr) {
    return;
  }
  tree_print_postorder(node->left);
  tree_print_postorder(node->right);
  print(node->elem);
  printf(" ");
}

template<typename T>
void tree_t<T>::print_postorder() const {
  printf("Tree postorder: ");
  tree_print_postorder(root);
  printf("\n");
}

template<typename T>
void tree_print_inorder(tree_elem_t<T>* node) {
  if (node == nullptr) {
    return;
  }
  tree_print_inorder(node->left);
  print(node->elem);
  printf(" ");
  tree_print_inorder(node->right);
}

template<typename T>
void tree_t<T>::print_inorder() const {
  printf("Tree inorder: ");
  tree_print_inorder(root);
  printf("\n");
}

template<typename T>
void tree_t<T>::print_preorder_iterative() const {
  vector_t<const tree_elem_t<T>*> stack(size());
  printf("Tree preorder iterative: ");

  stack.add_back(root);

  for (; stack.size() != 0;) {
    const tree_elem_t<T>* node = stack.back();
    stack.remove_back();
    if (node == nullptr) {
      continue;
    }
    print(node->elem);
    printf(" ");
    stack.add_back(node->right);
    stack.add_back(node->left);
  }
  printf("\n");
}

template<typename T>
struct stack_item_t {
  const tree_elem_t<T>* node;
  bool down;
};

template<typename T>
void tree_t<T>::print_postorder_iterative() const {
  printf("Tree postorder iterative: ");

  // Allocate stack size equal to twice the size of the tree
  // because we put nullptr children on stack as well.
  vector_t<stack_item_t<T>> stack(size() * 2);
  stack_item_t<T> si0 = {root, true};
  stack.add_back(si0);

  for (; stack.size() != 0;) {
    const tree_elem_t<T>* node = stack.back().node;
    bool down = stack.back().down;
    if (node == nullptr) {
      stack.remove_back();
    } else if (down) {
      stack[stack.size() - 1].down = false;
      stack_item_t<T> sir = {node->right, true};
      stack.add_back(sir);
      stack_item_t<T> sil = {node->left, true};
      stack.add_back(sil);
    } else {
      print(node->elem);
      printf(" ");
      stack.remove_back();
    }
  }

  printf("\n");
}

//         42
//        /
//       16
//      /  \
//     8   32
//    /    / \
//   2    22  40

// TODO: implement:
//   void tree_print_level_order(const tree_t* root);
//   void tree_print_levels(const tree_t* root);
//   void tree_print_postorder_iterative(const tree_t* root);
//   void tree_print_inorder_iterative(const tree_t* root);

#endif // _TREE_H_
