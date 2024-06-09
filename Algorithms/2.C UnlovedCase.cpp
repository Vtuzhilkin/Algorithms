#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#ifndef REMOTE_JUDGE
#include <cassert>
#include <string>
#include <iostream>

struct Node {
    std::string value;
    Node* next;
    Node(const std::string& value, Node* next) : value(value), next(next) {

    }
};
#endif


Node* solution(Node* head, int idx) {
    if (idx == 0) {
        return head->next;
    }
    Node* head_iter = head;
    while (idx-1) {
        head_iter = head_iter->next;
        idx--;
    }
    head_iter->next = head_iter->next->next;
    return head;
}

void print(Node* head){
    while (head != nullptr) {
        std::cout << head->value << '\n';
        head = head->next;
    }
}

#ifndef REMOTE_JUDGE
void test() {
    Node node3("node3", nullptr);
    Node node2("node2", &node3);
    Node node1("node1", &node2);
    Node node0("node0", &node1);
    Node* new_head = solution(&node0, 1);
    print(&node0);
    assert(new_head == &node0);
    assert(new_head->next == &node2);
    assert(new_head->next->next == &node3);
    assert(new_head->next->next->next == nullptr);
    // result is : node0 -> node2 -> node3
}

int unlovedCase() {
    test();
}
#endif