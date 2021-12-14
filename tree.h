#ifndef _TREE_H_
#define _TREE_H_

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
public:
  tree_t(): root(nullptr) {}
  ~tree_t();
  
  void add(const T& elem); 
  void print_preorder() const;
  void print_postorder() const;
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
 
// TODO: implement:
//   void tree_print_level_order(const tree_t* root);
//   void tree_print_levels(const tree_t* root);
//   void tree_print_preorder_iterative(const tree_t* root);
//   void tree_print_postorder_iterative(const tree_t* root);
//   void tree_print_inorder_iterative(const tree_t* root);
//   void tree_print_inorder(const tree_t* root);

#endif // _TREE_H_
