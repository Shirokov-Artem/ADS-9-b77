// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <string>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> bst;
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::string("Error! Could not open file.");
  }
  std::string word;
  while (file >> word){
    for (int i = 0; i < word.length(); i++) {
      word[i] = std::tolower(word[i]);
    }
    bst.Add(word);
  }
  file.close();
  return bst;
}
