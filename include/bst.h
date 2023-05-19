// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <string>
#include <iostream>
#include <fstream>

template<class T>
class BST {
 private:
    struct Node {
        T key;
        int count;
        Node* left;
        Node* right;
        Node(T k) : key(k), count(1), left(nullptr), right(nullptr) {}
    };
    Node* root = nullptr;
    Node* insert(Node* cur, T key) {
        if (!cur) {
            return new Node(key);
        }
        if (cur->key == key) {
            cur->count++;
        } else if (cur->key > key) {
            cur->left = insert(cur->left, key);
        } else {
            cur->right = insert(cur->right, key);
        }
        return cur;
    }
    int search(Node* cur, T key) {
        if (!cur) {
            return 0;
        }
        if (cur->key == key) {
            return cur->count;
        } else if (cur->key > key) {
            return search(cur->left, key);
        } else {
            return search(cur->right, key);
        }
    }
    int depth(Node* cur) {
        if (!cur) {
            return -1;
        }
        int leftDepth = depth(cur->left);
        int rightDepth = depth(cur->right);
        return std::max(leftDepth, rightDepth) + 1;
    }

 public:
    BST() = default;
    void add(const T& key) {
        root = insert(root, key);
    }
    int search(const T& key) {
        return search(root, key);
    }
    int calcDepth() {
        return depth(root);
    }
};
#endif  // INCLUDE_BST_H_
