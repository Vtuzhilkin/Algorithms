#include <iostream>
#include <unordered_map>

int competition() {
	int number;
	std::cin >> number;
	int sum = 0;
	std::unordered_map<int, std::pair<int, int>> sums;
	int result;
	sums[0] = std::make_pair(-1, -1);
	for (int i = 0; i < number; i++) {
		std::cin >> result;
		if (result == 0) result = -1;
		sum += result;
		if (sums.find(sum) == sums.end()) {
			sums[sum] = std::make_pair(i, i);
		}
		else {
			sums[sum].second = i;
		}
	}
	int longest_sequance = 0;
	for (const auto& sum_index : sums) {
		int longest = sum_index.second.second - sum_index.second.first;
		if (longest_sequance < longest) longest_sequance = longest;
	}
	std::cout << longest_sequance;
}