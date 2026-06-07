// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
        return;
    }

    std::string word;
    char ch;
    
    while (file.get(ch)) {
        if (std::isalpha(static_cast<unsigned char>(ch))) {
            word += std::tolower(static_cast<unsigned char>(ch));
        } else {
            if (!word.empty()) {
                tree.insert(word);
                word.clear();
            }
        }
    }
    
    if (!word.empty()) {
        tree.insert(word);
    }
    
    file.close();
}

void printFreq(BST<std::string>& tree) {
    std::vector<std::pair<std::string, int>> words;
    
    tree.inorder([&words](std::string word, int count) {
        words.push_back({word, count});
    });
    
    std::sort(words.begin(), words.end(), 
        [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
    
    std::ofstream out("result/freq.txt");
    for (const auto& pair : words) {
        std::cout << pair.first << " " << pair.second << std::endl;
        out << pair.first << " " << pair.second << std::endl;
    }
    out.close();
}
