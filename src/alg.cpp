// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::ifstream file(filename);
  if (file.fail()) {
    std::cerr << "Failed to open file!\n";
    exit(EXIT_FAILURE);
  }
  std::string line;
  std::string word;
  while (std::getline(file, line)) {
    for (auto c : line) {
      if (isalpha(c)) {
        word += tolower(c);
      } else if (!word.empty()) {
        tree.addElement(word);
        word.clear();
      }
    }
  }
  if (!word.empty()) {
    tree.addElement(word);
  }
  file.close();
  return tree;
}
