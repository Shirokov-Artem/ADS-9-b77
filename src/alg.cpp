// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <string>
#include <cstring>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> bst;
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Error! Can not open file!");
  }
  std::string word;
  while (file >> word) {
      std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c){ return std::tolower(c);});
      bst.add(word);
  }
  return bst;
}
