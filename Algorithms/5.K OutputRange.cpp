#ifndef REMOTE_JUDGE
struct Node {
    int value;
    const Node* left = nullptr;
    const Node* right = nullptr;
    Node(Node* left, Node* right, int value) : value(value), left(left), right(right) {}
};
#endif

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif
#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;


using namespace std;

void print_LMR(const Node* root, const int& l, const int& r) {
    if (root->left != nullptr && root->value >= l) {
        print_LMR(root->left, l, r);
    }
    if (root->value <= r && root->value >= l) {
        std::cout << root->value << std::endl;
    }
    if (root->right != nullptr && root->value <= r) {
        print_LMR(root->right, l, r);
    }
}

void print_range(Node* root, int l, int r) {
    print_LMR(root, l, r);
}

#ifndef REMOTE_JUDGE
void test() {
    {
        Node node1({ nullptr, nullptr, 2 });
        Node node2({ nullptr, &node1, 1 });
        Node node3({ nullptr, nullptr, 8 });
        Node node4({ nullptr, &node3, 8 });
        Node node5({ &node4, nullptr, 9 });
        Node node6({ &node5, nullptr, 10 });
        Node node7({ &node2, &node6, 5 });
        //print_range(&node7, 2, 4);
    }
    {
        Node node1({ nullptr,   nullptr,  3});
        Node node2({ nullptr,   &node1,  3});
        Node node3({ nullptr,   &node2,  2});
        Node node4({ nullptr,   nullptr, 5});
        Node node5({ nullptr,   &node4,  5});
        Node node6({ nullptr,   &node5,  5});
        Node node7({ &node3,   &node6,  4});
        print_range(&node7, 2, 4);
    }
}

int outputRange() {
    test();
}
#endif