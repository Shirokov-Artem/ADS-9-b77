// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template<typename T>
class BST {
 private:
  struct Node {
    T value;
    int count;
    Node* left;
    Node* right;
  };
  Node* root = nullptr;

 public:
  BST() = default;
  void add(const T& value) {
    Node** cur = &root;
    while (*cur != nullptr) {
      if ((*cur)->value < value) {
        cur = &(*cur)->left;
      } else if ((*cur)->value > value) {
        cur = &(*cur)->right;
      } else {
        (*cur)->count++;
        return;
      }
    }
    *cur = new Node{value, 1, nullptr, nullptr};
  }
  int search(const T& value) {
    Node* cur = root;
    while (cur != nullptr) {
      if (cur->value == value) {
        return cur->count;
      } else if (cur->value < value) {
        cur = cur->left;
      } else {
        cur = cur->right;
      }
    }
    return 0;
  }
  int depth() {
    std::function<int(Node*)> getDepth = [&](Node* node) -> int {
      if (!node) return 0;
      return std::max(getDepth(node->left), getDepth(node->right)) + 1;
    };
    return getDepth(root) - 1;
  }
};
#endif  // INCLUDE_BST_H_
