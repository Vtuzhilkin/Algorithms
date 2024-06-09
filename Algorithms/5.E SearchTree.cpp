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

bool searchTree(const Node* root, int prev_root_value, bool direction) {
    if (root->right != nullptr) {
        if (root->right->value > root->value) {
            if (direction) {
                if (root->right->value > prev_root_value) {
                    if (!searchTree(root->right, root->value, true)) {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
            else {
                if (root->right->value < prev_root_value) {
                    if (!searchTree(root->right, root->value, true)) {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
        }
        else {
            return false;
        }
    }

    if (root->left != nullptr) {
        if (root->left->value < root->value) {
            if (direction) {
                if (root->left->value > prev_root_value) {
                    if (!searchTree(root->left, root->value, false)) {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
            else {
                if (root->left->value < prev_root_value) {
                    if (!searchTree(root->left, root->value, false)) {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
        }
        else {
            return false;
        }
    }

    return true;
}

bool Solution(const Node* root) {
    bool left = true, right = true;
    if (root->left != nullptr) {
        if (root->left->value >= root->value) {
            return false;
        }
        else {
            left = searchTree(root->left, root->value, false);
        }
    }
    if (root->right != nullptr) {
        if (root->right->value <= root->value) {
            return false;
        }
        else {
            right = searchTree(root->right, root->value, true);
        }
    }
    return left && right;
}


#ifndef REMOTE_JUDGE
void test() {
    {
        Node node1({ 1, nullptr, nullptr });
        Node node2({ 4, nullptr, nullptr });
        Node node3({ 3, &node1, &node2 });
        Node node4({ 8, nullptr, nullptr });
        Node node5({ 5, &node3, &node4 });
        assert(Solution(&node5));
    }
    {
        Node node1({ 1, nullptr, nullptr });
        Node node2({ 5, nullptr, nullptr });
        Node node3({ 3, &node1, &node2 });
        Node node4({ 8, nullptr, nullptr });
        Node node5({ 5, &node3, &node4 });
        assert(!Solution(&node5));
    }
    {
        Node node7({ 19, nullptr, nullptr });
        Node node6({ 9, nullptr, &node7 });
        Node node5({6, nullptr, nullptr});
        Node node4({ 4, nullptr, nullptr });
        Node node3({ 1, nullptr, nullptr });
        Node node2({8, &node5, &node6});
        Node node1({ 3, &node3, &node4});
        Node node0({ 5, &node1, &node2 });
        assert(Solution(&node0));
    }
}


int searchTree() {
    test();
}
#endif