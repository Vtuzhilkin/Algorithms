#include <vector>
#include <cassert>

using Iterator = std::vector<int>::iterator;
using CIterator = std::vector<int>::const_iterator;

std::vector<int> merge(
	CIterator left_begin, CIterator left_end,
	CIterator right_begin, CIterator right_end) {
	std::vector<int> result;
	while (left_begin != left_end || right_begin != right_end) {
		if (right_begin == right_end || left_begin != left_end && *left_begin <= *right_begin) {
			result.push_back(*left_begin);
			left_begin++;
		}
		else if(left_begin == left_end || right_begin != right_end){
			result.push_back(*right_begin);
			right_begin++;
		}
	}
	return result;
}

void merge_sort(Iterator begin, Iterator end) {
	int length = end - begin;
	if (length > 2) {
		merge_sort(begin, begin + length/2);
		merge_sort(begin + length/2, end);
		std::vector<int> result = merge(begin, begin + length/2, begin + length/2, end);
		Iterator result_begin = result.begin();
		while (begin != end && result_begin != result.end()) {
			*begin = *result_begin;
			begin++;
			result_begin++;
		}
	} 
	else {
		if (length == 2 && *begin > *(begin + 1)) {
			int auxiliary = *begin;
			*begin = *(begin + 1);
			*(begin + 1) = auxiliary;
		}
	}
}

void test_merge_sort() {
	std::vector<int> a = { 1, 4, 9 };
	std::vector<int> b = { 2, 10, 11 };
	std::vector<int> c = merge(a.cbegin(), a.cend(), b.cbegin(), b.cend());
	std::vector<int> expected = { 1, 2, 4, 9, 10, 11 };
	assert(c == expected);
	std::vector<int> d = { 1, 4, 2, 10, 1, 2 };
	std::vector<int> sorted = { 1, 1, 2, 2, 4, 10 };
	merge_sort(d.begin(), d.end());
	assert(d == sorted);
}
