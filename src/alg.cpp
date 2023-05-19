// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <cctype>
#include <stdexcept>
#include "bst.h"
#include "alg.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error! Can not open file!");
    }
    BST<std::string> tree;
    std::string word;
    while (file >> word) {
        std::string new_word;
        for (char c : word) {
            if (std::isalpha(c)) {
                new_word += std::tolower(c);
            }
        }
        if (!new_word.empty()) {
            tree.add(new_word);
        }
    }
    return tree;
}
