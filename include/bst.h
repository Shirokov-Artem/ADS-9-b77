// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <string>
#include <algorithm>

template <typename T>
class BST {
 private:
  struct Node {
    T value;
    int count;
    Node* left;
    Node* right;
    explicit Node(const T& new_value) : value(new_value), count(1), left(nullptr), right(nullptr) {}
  };
  Node* root;
  Node* insert(Node* n, const T& value) {
    if (!n) {
      return new Node(value);
    }
    if (value < n->value) {
      n->left = insert(n->left, value);
    } else if (value > n->value) {
      n->right = insert(n->right, value);
    } else {
      n->count++;
    }
    return n;
  }
  int search(Node* n, const T& value) const {
    if (!n) {
      return 0;
    }
    if (n->value == value) {
      return n->count;
    }
    if (value < n->value) {
      return search(n->left, value);
    }
    return search(n->right, value);
  }
  int depth(Node* n) const {
    if (!n) {
      return 0;
    }
    return std::max(depth(n->left), depth(n->right)) + 1;
  }

 public:
  BST() : root(nullptr) {}
  void insert(const T& value) {
    root = insert(root, value);
  }
  int search(const T& value) const {
    return search(root, value);
  }
  int depth() const {
    return depth(root);
  }
};
#endif  // INCLUDE_BST_H_
