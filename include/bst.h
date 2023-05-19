// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <string>
#include <algorithm>

template<typename T>
class Node {
 public:
    T key;
    int count;
    Node* left_c, * right_c;
    explicit Node(T k) : key(k), count(1), left_c(nullptr), right_c(nullptr) {}
};
template<typename T>
class BST {
 private:
     Node<T>* root;
     void insert(Node<T>* node, const T& key) {
        if (node->key == key) {
            node->count++;
            return;
        } else if (node->key > key) {
            if (node->left_c == nullptr) {
                node->left_c = new Node<T>(key);
                return;
            }
            insert(node->left_c, key);
        } else {
            if (node->right_c == nullptr) {
                node->right_c = new Node<T>(key);
                return;
            }
            insert(node->right_c, key);
        }
     }
     int search(Node<T>* node, const T& key) {
         if (node == nullptr) {
             return 0;
         }
         if (node->key == key) {
             return node->count;
         } else if (node->key > key) {
             return search(node->left_c, key);
         } else {
             return search(node->right_c, key);
         }
     }
     int get_depth(Node<T>* node) {
         if (node == nullptr) {
             return 0;
         }
         return std::max(get_depth(node->left_c), get_depth(node->right_c)) + 1;
     }

 public:
     BST() : root(nullptr) {}
     void insert(const T& key) {
         if (root == nullptr) {
             root = new Node<T>(key);
             return;
         }
         insert(root, key);
     }
     int search(const T& key) {
         return search(root, key);
     }
     int depth() {
         return get_depth(root) - 1;
     }
};
#endif  // INCLUDE_BST_H_
