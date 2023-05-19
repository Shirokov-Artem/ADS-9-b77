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
    Node* left_child, * right_child;
    explicit Node(T k) : key(k), count(1), left_child(nullptr), right_child(nullptr) {}
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
            if (node->left_child == nullptr) {
                node->left_child = new Node<T>(key);
                return;
            }
            insert(node->left_child, key);
        } else {
            if (node->right_child == nullptr) {
                node->right_child = new Node<T>(key);
                return;
            }
            insert(node->right_child, key);
        }
     }
     int search(Node<T>* node, const T& key) {
         if (node == nullptr) {
             return 0;
         }
         if (node->key == key) {
             return node->count;
         } else if (node->key > key) {
             return search(node->left_child, key);
         } else {
             return search(node->right_child, key);
         }
     }
     int get_depth(Node<T>* node) {
         if (node == nullptr) {
             return 0;
         }
         return std::max(get_depth(node->left_child), get_depth(node->right_child)) + 1;
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
