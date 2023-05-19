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
  Node* root;
  Node* addNode(Node* p, const T& value) {
    if (p == nullptr) {
      p = new Node{value, 1, nullptr, nullptr};
    }
    else if (value < p->value) {
      p->left = addNode(p->left, value);
    }
    else if (value > p->value) {
      p->right = addNode(p->right, value);
    }
    else {
      p->count++;
    }
    return p;
  }
  int searchNode(Node* p, const T& value) {
    if (p == nullptr) {
      return 0;
    }
    else if (value == p->value) {
      return p->count;
    }
    else if (value < p->value) {
      return searchNode(p->left, value);
    }
    else {
      return searchNode(p->right, value);
    }
  }
  int getDepth(Node* p) {
    if (p == nullptr) {
      return 0;
    }
    else {
      int leftDepth = getDepth(p->left);
      int rightDepth = getDepth(p->right);
      return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
  }

 public:
  BST() : root(nullptr) {}
  void Add(const T& value) {
    root = addNode(root, value);
  }
  int search(const T& value) {
    return searchNode(root, value);
  }
  int depth() {
    return getDepth(root) - 1;
  }
};
#endif  // INCLUDE_BST_H_
