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
    std::cout << "File error!" << std::endl;
    exit(1);
  }

  BST<std::string> tree;
  std::string word;

  while (file >> word) {
    // преобразуем слово к нижнему регистру
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);

    // проверяем, что слово состоит только из латинских букв
    if (std::all_of(word.begin(), word.end(), [](char c) { return std::isalpha(c); })) {
      tree.insert(word);
    }
  }

  file.close();
  return tree;
}
