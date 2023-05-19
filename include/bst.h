// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <vector>
#include <ostream>
#include <string>
#include <iostream>

template<typename T>
class BST {
public:
    BST() { }
    ~BST() {
        clear(root_);
    }
    void insert(const T& key) {
        if (root_ == nullptr) {
            root_ = createNode(key);
        } else {
            insertHelper(root_, key);
        }
    }
    int find(const T& key) const {
        return findHelper(root_, key);
    }
    size_t size() const {
        return sizeHelper(root_);
    }
    size_t depth() const {
        return depthHelper(root_);
    }
    void bfs(void (*func)(T&)) const {
        std::vector<BSTNode*> nodes;
        if (root_ != nullptr) {
            nodes.push_back(root_);
        }
        for (size_t i = 0; i < nodes.size(); i++) {
            BSTNode* node = nodes[i];
            func(node->key);
            if (node->left != nullptr) {
                nodes.push_back(node->left);
            }
            if (node->right != nullptr) {
                nodes.push_back(node->right);
            }
        }
    }

private:
    struct BSTNode {
        T key;
        int freq;
        BSTNode* left;
        BSTNode* right;

        BSTNode(const T& key)
            : key(key),
              freq(1),
              left(nullptr),
              right(nullptr) {}
    };

    BSTNode* root_ = nullptr;

    BSTNode* createNode(const T& key) {
        BSTNode* node = new BSTNode(key);
        return node;
    }

    void insertHelper(BSTNode* node, const T& key) {
        if (node->key == key) {
            node->freq++;
        } else if (node->key > key) {
            if (node->left == nullptr) {
                node->left = createNode(key);
            } else {
                insertHelper(node->left, key);
            }
        } else {
            if (node->right == nullptr) {
                node->right = createNode(key);
            } else {
                insertHelper(node->right, key);
            }
        }
    }

    int findHelper(BSTNode* node, const T& key) const {
        if (node == nullptr) {
            return 0;
        } else if (node->key == key) {
            return node->freq;
        } else if (node->key > key) {
            return findHelper(node->left, key);
        } else {
            return findHelper(node->right, key);
        }
    }

    void clear(BSTNode* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    size_t sizeHelper(BSTNode* node) const {
        if (node == nullptr) {
            return 0;
        } else {
            return 1 + sizeHelper(node->left) + sizeHelper(node->right);
        }
    }

    size_t depthHelper(BSTNode* node) const {
        if (node == nullptr) {
            return 0;
        } else {
            return 1 + std::max(depthHelper(node->left), depthHelper(node->right));
        }
    }
};
#endif  // INCLUDE_BST_H_
