// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <string>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);
    std::string word;
    while (file >> word) {
        std::string processed_word;
        // переводим все буквы в нижний регистр
        for (char c : word) {
            processed_word += std::tolower(c);
        }
        // если слово состоит только из латинских букв, добавляем его в дерево
        if (std::isalpha(processed_word[0])) {
            tree.insert(processed_word);
        }
    }
    file.close();
    return tree;
}
