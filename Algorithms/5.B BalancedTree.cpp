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

bool check(int& deepth, int& total_deepth) {
    if (total_deepth == -1) {
        total_deepth = deepth;
        return true;
    }
    else {
        if (abs(total_deepth - deepth) <= 1) return true;
        else return false;
    }
}

bool balanced(const Node* root, int deepth,  int& total_deepth) {
    deepth++;
    if (root->left != nullptr) {
        if (!balanced(root->left, deepth, total_deepth)) {
            return false;
        }
    }
    else {
        if (!check(deepth, total_deepth)) {
            return false;
        }
    }
    if (root->right != nullptr) {
        if (!balanced(root->right, deepth, total_deepth)) {
            return false;
        }
    }
    else {
        if (!check(deepth, total_deepth)) {
            return false;
        }
    }
    return true;
}

bool Solution(const Node* root) {
    int total_deepth = -1;
    int deepth = -1;
    return balanced(root, deepth, total_deepth);
}


#ifndef REMOTE_JUDGE
void test1() {
    Node node1({ 1, nullptr, nullptr });
    Node node2({ -5, nullptr, nullptr });
    Node node3({ 3, &node1, &node2 });
    Node node4({ 10, nullptr, nullptr });
    Node node5({ 2, &node3, &node4 });
    assert(Solution(&node5));
}

void test2() {
    Node node5({ 5, nullptr, nullptr });
    Node node6({ 5, nullptr, nullptr });
    Node node7({ 5, nullptr, nullptr });
    Node node8({ 5, nullptr, nullptr });
    Node node4({ 4, &node7, &node8 });
    Node node3({ 3, &node5, &node6 });
    Node node2({ 2, nullptr, &node4 });
    Node node1({ 1, &node3, nullptr });
    Node node0({ 0, &node1, &node2 });
    assert(Solution(&node0) == false);
}

void test3() {
    Node node2({ 2, nullptr, nullptr });
    Node node1({ 1, nullptr, &node2 });
    Node node0({ 0, nullptr, &node1 });
    assert(Solution(&node0) == false);
}

int balancedTree() {
    test1();
    test2();
    test3();
}
#endif