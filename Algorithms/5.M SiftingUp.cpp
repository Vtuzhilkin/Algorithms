#include <vector>
#include <cassert>
#ifdef REMOTE_JUDGE
#include "solution.h"
#endif


int siftUp(std::vector<int>& heap, int idx) {
    while (heap.at(idx) > heap.at(idx / 2) && idx != 1) {
        int help = heap.at(idx / 2);
        heap[idx / 2] = heap[idx];
        heap[idx] = help;
        idx = idx / 2;
    }
    if (heap.size() > 2 * idx + 1 && heap.at(idx) < heap.at(2 * idx + 1)) {
        int help = heap.at(idx);
        heap[idx] = heap[2 * idx + 1];
        heap[2 * idx + 1] = help;
        idx = 2 * idx + 1;
    }
    return idx;
}

#ifndef REMOTE_JUDGE
void test() {
    std::vector<int> sample = { -1, 12, 6, 8, 3, 15, 7 };
    assert(siftUp(sample, 5) == 1);
}


int sittingUp() {
    test();
}
#endif