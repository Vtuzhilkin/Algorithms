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

using namespace std;

void findMax(const Node* root, int& max) {
    if (root->value > max) {
        max = root->value;
    }
    if (root->left != nullptr) {
        findMax(root->left, max);
    }
    if (root->right != nullptr) {
        findMax(root->right, max);
    }
}

int Solution(const Node* root) {
    int max = root->value;
    findMax(root, max);
    return max;
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({ 1, nullptr, nullptr });
    Node node2({ -5, nullptr, nullptr });
    Node node3({ 3, &node1, &node2 });
    Node node4({ 2, &node3, nullptr });
    assert(Solution(&node4) == 3);
}

int lightBulbs() {
    test();
}
#endif