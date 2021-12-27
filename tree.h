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
  void print_inorder_iterative() const;
  void print_level_order() const;
  void print_levels() const;
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
  printf("Tree %-20s ", "preorder recursive:");
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
  printf("Tree %-20s ", "postorder recursive:");
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
  printf("Tree %-20s ", "inorder recursive:");
  tree_print_inorder(root);
  printf("\n");
}

template<typename T>
void tree_t<T>::print_preorder_iterative() const {
  vector_t<const tree_elem_t<T>*> stack;
  printf("Tree %-20s ", "preorder iterative:");

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
void tree_t<T>::print_postorder_iterative() const {
  printf("Tree %-20s ", "postorder iterative:");

  vector_t<const tree_elem_t<T>*> stack;
  stack.add_back(root);
  const tree_elem_t<T>* last = root;

  for (; stack.size() != 0;) {
    const tree_elem_t<T>* node = stack.back();
    if (node == nullptr) {
      assert(last == nullptr);
      stack.remove_back();
    } else if (last == node->right) {
      // this also covers the case when both children are nullptr
      print(node->elem);
      printf(" ");
      last = node;
      stack.remove_back();
    } else if (last == node->left) {
      assert(last != nullptr || node->right != nullptr);
      stack.add_back(node->right);
      last = node->right;
    } else {
      stack.add_back(node->left);
      last = node->left;
    }
  }
  printf("\n");
}

template<typename T>
void tree_t<T>::print_inorder_iterative() const {
  printf("Tree %-20s ", "inorder iterative:");
  vector_t<const tree_elem_t<T>*> stack;
  bool down = true;
  stack.add_back(root);
  for (; stack.size() != 0;) {
    const tree_elem_t<T>* node = stack.back();
    if (node == nullptr) {
      down = false;
      stack.remove_back();
    } else if (down) {
      stack.add_back(node->left);
    } else {
      print(node->elem);
      printf(" ");
      stack.remove_back();
      stack.add_back(node->right);
      down = true;
    }
  }
  printf("\n");
}

template<typename T>
void tree_t<T>::print_level_order() const {
  printf("Tree %-20s ", "level order:");
  // Allocate memory equal to the size of the tree as
  // all tree nodes will be in the queue at same time.
  vector_t<const tree_elem_t<T>*> queue(size());
  size_t head = 0;
  if (root != nullptr) {
    queue.add_back(root);
  }
  for (; head < queue.size(); ++head) {
    const tree_elem_t<T>* node = queue[head];
    if (node->left != nullptr) {
      queue.add_back(node->left);
    }
    if (node->right != nullptr) {
      queue.add_back(node->right);
    }
    print(node->elem);
    printf(" ");
  }
  printf("\n");
}

template<typename T>
void tree_t<T>::print_levels() const {
  printf("Tree %-20s ", "levels:");

  typedef vector_t<const tree_elem_t<T>*> queue_t;
  queue_t queue1;
  queue_t queue2;
  queue_t* pqueue1 = &queue1;
  queue_t* pqueue2 = &queue2;

  pqueue1->add_back(root);
  for (; pqueue1->size() > 0;) {
    assert(pqueue2->size() == 0);
    for (size_t i = 0; i < pqueue1->size(); ++i) {
      const tree_elem_t<T>* node = (*pqueue1)[i];
      if (node == nullptr) {
        continue;
      }
      print(node->elem);
      printf(" ");
      pqueue2->add_back(node->left);
      pqueue2->add_back(node->right);
    }
    printf("| ");
    for (size_t i = pqueue1->size(); i > 0; --i) {
      pqueue1->remove_back();
    }
    queue_t* p = pqueue1;
    pqueue1 = pqueue2;
    pqueue2 = p;
  }
  printf("\n");
}

#endif // _TREE_H_
