#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#ifndef REMOTE_JUDGE
#include <cassert>
#include <string>

struct Node {
    std::string value;
    Node* next;
    Node(const std::string& value, Node* next) : value(value), next(next) {

    }
};
#endif


int solution(Node* head, const std::string& elem) {
    int index = 0;
    
    while (head != nullptr && elem != head->value) {
        head = head->next;
        index++;
    }

    if (head == nullptr) {
        return -1;
    }
    else {
        return index;
    }
}

#ifndef REMOTE_JUDGE
void test() {
    Node node3("node3", nullptr);
    Node node2("node2", &node3);
    Node node1("node1", &node2);
    Node node0("node0", &node1);
    int idx = solution(&node0, "node0");
    assert(idx == 0);
}

int caringMother() {
    test();
}
#endif