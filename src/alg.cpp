// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <string>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file " << filename << std::endl;
        exit(1);
    }
    std::string word;
    BST<std::string> tree;
    while ((word = getNextWord(file)) != "") {
        tree.insert(word);
    }
    return tree;
}

std::string getNextWord(std::ifstream& file) {
    std::string word;
    char ch;
    while (file.get(ch) && !isalpha(ch)) {
    }
    if (!file) {
        return "";
    }
    word += tolower(ch);
    while (file.get(ch) && isalpha(ch)) {
        word += tolower(ch);
    }
    return word;
}
