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

void read_tree(const Node* root, std::vector<std::pair<bool, int>>& tree) {
    tree.push_back(std::make_pair(true, root->value));

    if (root->left != nullptr) {
        read_tree(root->left, tree);
    }
    else {
        tree.push_back(std::make_pair(false, 0));
    }
    if (root->right != nullptr) {
        read_tree(root->right, tree);
    }
    else {
        tree.push_back(std::make_pair(false, 0));
    }
}

bool check(const Node* root, const std::vector<std::pair<bool, int>>& tree, int& i) {
    if (i >= tree.size()) {
        return false;
    }
    else if (root->value != tree.at(i).second && tree.at(i).first) {
        return false;
    }
    else if (!tree.at(i).first) {
        return false;
    }
    else {
        if (root->left != nullptr) {
            if (!check(root->left, tree, ++i)) {
                return false;
            }
        }
        else {
            ++i;
        }
        if (root->right != nullptr) {
            if (!check(root->right, tree, ++i)) {
                return false;
            }
        }
        else {
            ++i;
        }
    }
    return true;
}


bool Solution(const Node* root1, const Node* root2) {
    std::vector<std::pair<bool, int>> first_tree;
    read_tree(root1, first_tree);
    int i = 0;
    return check(root2, first_tree, i) && i == first_tree.size()-1;
}

#ifndef REMOTE_JUDGE
void test() {
    {
        Node node1({ 1, nullptr, nullptr });
        Node node2({ 2, nullptr, nullptr });
        Node node3({ 3, &node1, &node2 });

        Node node4({ 1, nullptr, nullptr });
        Node node5({ 2, nullptr, nullptr });
        Node node6({ 3, &node4, &node5 });
        assert(Solution(&node3, &node6));
    }
    {
        Node node1({ 1, nullptr, nullptr });
        Node node0({ 0, &node1, nullptr });


        Node node2({ 1, nullptr, nullptr });
        Node node3({ 0, nullptr, &node2 });
        assert(!Solution(&node0, &node3));

    }
}

int twinTress() {
    test();
}
#endif