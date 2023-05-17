// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <string>
#include  "bst.h"

std::string cleanWord(const std::string& str) {
  std::string res = "";
  for (char c : str) {
    if (isalpha(c)) {
      res += tolower(c);
    }
  }
  return res;
}

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
    exit(1);
  }
  std::string word;
  while (file >> word) {
    word = cleanWord(word);
    if (word != "") {
      tree.insert(word);
    }
  }
  file.close();
  return tree;
} 
