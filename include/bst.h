// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <cstdlib>
#include <iostream>

template <typename T>
class BST {
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* _root;

 public:
    BST() : _root(nullptr) {}
    virtual ~BST() {
        destroy(_root);
    }
    void insert(const T& value) {
        _root = insert(value, _root);
    }
    int depth() const {
        return depth(_root);
    }
    int search(const T& value) const {
        return search(value, _root);
    }

 private:
    // рекурсивная функция для уничтожения дерева
    void destroy(Node* p) {
        if (p != nullptr) {
            destroy(p->left);
            destroy(p->right);
            delete p;
        }
    }
    // рекурсивная функция для вставки элемента в дерево
    Node* insert(const T& value, Node* p) {
        if (p == nullptr) {
            return new Node(value);
        }
        if (value < p->data) {
            p->left = insert(value, p->left);
        } else if (value > p->data) {
            p->right = insert(value, p->right);
        }
        return p;
    }
    // рекурсивная функция для подсчёта глубины дерева
    int depth(Node* p) const {
        if (p == nullptr) {
            return 0;
        }
        return 1 + std::max(depth(p->left), depth(p->right));
    }
    // рекурсивная функция для поиска заданного элемента в дереве
    int search(const T& value, Node* p) const {
        if (p == nullptr) { // если элемент не найден
            return -1;
        }
        if (value == p->data) { // если элемент найден
            return depth(p);
        }
        if (value < p->data) { // если значение меньше текущего элемента, идём влево
            return search(value, p->left);
        }
        // иначе идём вправо
        return search(value, p->right);
    }
};
#endif  // INCLUDE_BST_H_
