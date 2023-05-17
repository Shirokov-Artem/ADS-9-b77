// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <algorithm>
#include <string>

template<typename T>
class BSTNode {
 public:
  T value;
  BSTNode<T>* left;
  BSTNode<T>* right;

  explicit BSTNode(T value) : value(value), left(nullptr), right(nullptr) {}
};

template<typename T>
class BST {
 public:
  BSTNode<T>* root;

  BST() : root(nullptr) {}

  ~BST() {
    destroy(root);
  }

  void insert(T value) {
    root = insert(root, value);
  }

  int depth() const {
    return depth(root);
  }

  bool search(T value) const {
    return search(root, value);
  }

 private:
  void destroy(BSTNode<T>* node) {
    if (node != nullptr) {
      destroy(node->left);
      destroy(node->right);
      delete node;
    }
  }

  BSTNode<T>* insert(BSTNode<T>* node, T value) {
    if (node == nullptr) {
      return new BSTNode<T>(value);
    }

    if (value < node->value) {
      node->left = insert(node->left, value);
    } else if (value > node->value) {
      node->right = insert(node->right, value);
    }

    return node;
  }

  int depth(BSTNode<T>* node) const {
    if (node == nullptr) {
      return 0;
    }

    int leftDepth = depth(node->left);
    int rightDepth = depth(node->right);

    return (leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1;
  }

  bool search(BSTNode<T>* node, T value) const {
    if (node == nullptr) {
      return false;
    }

    if (node->value == value) {
      return true;
    }

    if (value < node->value) {
      return search(node->left, value);
    } else {
      return search(node->right, value);
    }
  }
};
#endif  // INCLUDE_BST_H_
