#ifndef REMOTE_JUDGE
struct Node {
    int value;
    const Node* left = nullptr;
    const Node* right = nullptr;
    Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
};
#endif

#ifdef REMOTE_JUDGE
#include "solution_tree.h"
#endif
#include <cmath>
#include <iostream>
#include <cassert>
#include <vector>


using namespace std;

void read_left(const Node* root, std::vector<int>& left_tree) {
    left_tree.push_back(root->value);
    if (root->left != nullptr) {
        read_left(root->left, left_tree);
    }
    if (root->right != nullptr) {
        read_left(root->right, left_tree);
    }
}

bool check_tree(const Node* root, const std::vector<int>& left_tree, int& i) {
    if (i >= left_tree.size()) {
        return false;
    }else if (root->value != left_tree.at(i)) {
        return false;
    }
    else {
        if (root->right != nullptr) {
            if (!check_tree(root->right, left_tree, ++i)) {
                return false;
            }
        }
        if (root->left != nullptr) {
            if (!check_tree(root->left, left_tree, ++i)) {
                return false;
            }
        }
    }
    return true;
}

bool Solution(const Node* root) {
    std::vector<int> left_tree;
    if (root->left != nullptr) {
        read_left(root->left, left_tree);
    }
    if (root->right != nullptr) {
        int i = 0;
        return check_tree(root->right, left_tree, i) && i == left_tree.size()-1;
    }
    if (root == nullptr) {
        return true;
    }
    else if (root->left == nullptr && root->right == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

#ifndef REMOTE_JUDGE
void test() {
    {
        Node node1({ 3, nullptr, nullptr });
        Node node2({ 4, nullptr, nullptr });
        Node node3({ 4, nullptr, nullptr });
        Node node4({ 3, nullptr, nullptr });
        Node node5({ 2, &node1, &node2 });
        Node node6({ 2, &node3, &node4 });
        Node node7({ 1, &node5, &node6 });
        assert(Solution(&node7));
        assert(Solution(&node1));
    }
    {
        Node node3({ 3, nullptr, nullptr });
        Node node2({ 3, nullptr, nullptr });
        Node node1({ 2, &node2, &node3 });
        Node node0({ 1, nullptr, &node1});
        assert(!Solution(&node0));
    }
}


int anagrammTree() {
    test();
}
#endif