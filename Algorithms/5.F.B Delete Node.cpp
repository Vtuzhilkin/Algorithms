// https://contest.yandex.ru/contest/24810/run-report/113830283/
// ������� ������
// ������� �������� ������� �� ��������� ������ ������ ���������� � ��������� ������ :
// 1. ����� ��������� �������
// 2. ����� ����� ������ ������� � ����� ��������� ��������� �������.
// 3. ������ ��������� ������� �� ����� ������ �������.
// 
// �������������� ������������
// ����� ��������� ������� � ��� ��������.
//      ���� ��������� ������� �� �������, �� ������������ ������� ��������� ��������� ������.
//      ���� ��������� ������� �������, ���������� ��� ��������� ��������:
//      1. � ��������� ������� ��� �������� :
//           ��������� ��������� ������� � ������������ �������� ������� ��� nullptr.
//      
//      2. � ��������� ������� ���� ������ ������ �������:
//           ��������� ������� ���������� �� ������ ������� ������� � ������������ �������� �������(root) ��� ������ �������.
//      
//      3. � ��������� ������� ���� ����� ������� ��� ��� �������.������ ������ ������ ����� ������ ������� � ��� ��������.
//               ���� ������ ������� ������� �� ����������, �� ��������� ������� ���������� �� ������ ������ �������.
//               ����� ����� ������ ������� ���������� �� ������ ������ �������, � ��������� ������� ���������� �� ������ ������� ������� � ������������ �������� �������(root).
// 
// ��������� ���������.
// ����� ���������� �������� � ������ ������ �������� O(log(N)), ��� N - ���������� ��������� � ����.
// � ����� ������ ��������� �������� �������� O(log(M)), ��� M ������� ���������� ��������.
// ���� ��������� ������� �� ���������, �� ����� ����� ������ ������� � ����� ��������� �������� O(log(N)) - O(log(M)), ��� N - ����������
// ��������� � ����, M - ������� ���������� ��������.
// � ����� ��������� ��������� ��������� ������ �������� - O(log(N)).
// 
// ���������������� ���������.
// ��� ���������� ������� ��������� ���������� ������ ��� ��������� �������, �������� ���������� ��������, ������ ������� �������� �
// ������ ������ �������� - � ������������ O(4) ~O(1).
// � ����� ���������������� ��������� �������� O(1).


#ifndef REMOTE_JUDGE
struct Node {
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(Node* left, Node* right, int value) : value(value), left(left), right(right) {}
};
#endif
#ifdef REMOTE_JUDGE
#include "solution.h"
#endif
#include <cassert>
#include <utility>
#include <iostream>

Node** search_remove(Node** parent, const int& key) {
    while (*parent) {
        if (key > (*parent)->value) {
            parent = &(*parent)->right;
        }
        else if (key < (*parent)->value) {
            parent = &(*parent)->left;
        }
        else {
            return parent;
        }
    }
    return nullptr;
}

std::pair<Node*, Node*> search_right(Node* parent, const int& key) {
    while (parent != nullptr) {
        if (!parent->right) {
            return std::make_pair(parent, nullptr);
        }
        if (!parent->right->right) {
            return std::make_pair(parent, parent->right);
        }
        parent = parent->right;
    }
    return std::make_pair(nullptr, nullptr);
}


Node* remove(Node* root, int key) {
    Node** pointer_remove_node = search_remove(&root, key);
    
    if (!pointer_remove_node) {
        return root;
    }

    Node* remove_node = *pointer_remove_node;
    
    if (!remove_node->left && !remove_node->right) {
        *pointer_remove_node = nullptr;
    }
    else if (!remove_node->left) {
        *pointer_remove_node = remove_node->right;
    }
    else {
        std::pair<Node*, Node*> right = search_right(remove_node->left, key);
        Node* parent_right = right.first;
        Node* right_node = right.second;
        if (!right_node) {  
            *pointer_remove_node = parent_right;
            parent_right->right = remove_node->right;
        }
        else {
            parent_right->right = right_node->left;
            right_node->right = remove_node->right;
            right_node->left = remove_node->left;
            *pointer_remove_node = right_node;
        }

    }
    remove_node = nullptr;
    return root;
}

#ifndef REMOTE_JUDGE
void test() {

    {
        Node node3({ nullptr, nullptr, 7 });
        Node node2({ nullptr, &node3, 5 });
        Node node1({ nullptr, nullptr, 5 });
        Node* newHead = remove(&node1, 5);
    }
    
    {
        Node node11({ nullptr, nullptr, 45 });
        Node node10({ nullptr, nullptr, 99 });
        Node node9({ nullptr, nullptr, 72 });
        Node node8({ &node9, &node10, 91 });
        Node node7({ nullptr, nullptr, 50 });
        Node node6({ nullptr, nullptr, 32 });
        Node node5({ &node6, nullptr, 29 });
        Node node4({ nullptr, &node11, 11 });
        Node node3({ &node7, &node8, 65 });
        Node node2({ &node4, &node5, 20 });
        Node node1({ &node2, &node3, 41 });

        Node* newHead;

        newHead = remove(&node1, 41);

    }
    {   
        Node* node = nullptr;
        remove(node, 4);
    }

}

int deleteNode() {
    test();
}
#endif
