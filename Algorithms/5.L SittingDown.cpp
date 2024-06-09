#include <vector>
#include <cassert>
#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

void swapDown(std::vector<int>& heap, int& idx, int idx_swap) {
    int help = heap.at(idx);
    heap[idx] = heap[idx_swap];
    heap[idx_swap] = help;
    idx = idx_swap;
}

int siftDown(std::vector<int>& heap, int idx) {
    while (2 * idx + 1 < heap.size() && !(heap.at(idx) >= heap.at(2 * idx) && heap.at(idx) >= heap.at(2 * idx + 1))) {
        if (heap.at(idx) <= heap.at(2 * idx) && heap.at(idx) <= heap.at(2 * idx + 1)) {
            int help_idx = 2*idx;
            if (heap.at(2 * idx) < heap.at(2 * idx + 1)) {
                help_idx++;
            }
            swapDown(heap, idx, help_idx);
        }else if (heap.at(idx) <= heap.at(2 * idx)) {
            swapDown(heap, idx, 2*idx);
        }
        else if (heap.at(idx) <= heap.at(2 * idx + 1)) {
            swapDown(heap, idx, 2 * idx + 1);
        }
    }
    if (2 * idx < heap.size() && heap.at(2 * idx) >= heap.at(idx)) {
        int help = heap.at(idx);
        heap[idx] = heap[2 * idx];
        heap[2 * idx] = help;
        idx = 2 * idx;
    }
    return idx;
}

#ifndef REMOTE_JUDGE
void test() {
    std::vector<int> sample = { -1, 12, 1, 8, 3, 4, 7 };
    assert(siftDown(sample, 2) == 5);
}


int sittingDown() {
    test();
}
#endif