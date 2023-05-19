// Copyright 2021 NNTU-CS
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <locale>
#include "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    BST<std::string> tree;
    std::string word;
    while (!file.eof()) {
        char c = file.get();
        if (std::isalpha(c)) {
            word += std::tolower(c);
        } else if (!word.empty()) {
            tree.insert(word);
            word = "";
        }
    }
    if (!word.empty()) {
        tree.insert(word);
    }
    return tree;
}
