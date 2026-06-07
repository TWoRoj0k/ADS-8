// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <string>
#include <algorithm>
#include <functional>

template <typename T>
class BST {
 private:
    struct Node {
        T data;
        int count;
        Node* left;
        Node* right;
        explicit Node(T val) : data(val), count(1), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insert(Node*& node, T value) {
        if (node == nullptr) {
            node = new Node(value);
        } else if (value < node->data) {
            insert(node->left, value);
        } else if (value > node->data) {
            insert(node->right, value);
        } else {
            node->count++;
        }
    }

    int getDepth(Node* node) const {
        if (node == nullptr) return 0;
        return 1 + std::max(getDepth(node->left), getDepth(node->right));
    }

    int searchNode(Node* node, T value) const {
        if (node == nullptr) return 0;
        if (value < node->data) return searchNode(node->left, value);
        if (value > node->data) return searchNode(node->right, value);
        return node->count;
    }

    void clear(Node* node) {
        if (node == nullptr) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    void inorderTraversal(Node* node, const std::function<void(T, int)>& func) const {
        if (node == nullptr) return;
        inorderTraversal(node->left, func);
        func(node->data, node->count);
        inorderTraversal(node->right, func);
    }

 public:
    BST() : root(nullptr) {}

    ~BST() {
        clear(root);
    }

    void insert(T value) {
        insert(root, value);
    }

    int depth() const {
    if (root == nullptr) return 0;
    return getDepth(root) - 1;
}

    int search(T value) const {
        return searchNode(root, value);
    }

    void inorder(const std::function<void(T, int)>& func) const {
        inorderTraversal(root, func);
    }
};

#endif  // INCLUDE_BST_H_
