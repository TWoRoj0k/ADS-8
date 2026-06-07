// Copyright 2021 NNTU-CS
#include <sys/stat.h>
#include <string>
#include <iostream>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

int main() {
    mkdir("result", 0777);
    BST<std::string> tree;
    makeTree(tree, "src/war_peace.txt");
    std::cout << "Tree depth: " << tree.depth() << std::endl;
    std::cout << "\nWord frequencies:\n";
    printFreq(tree);
    return 0;
}
