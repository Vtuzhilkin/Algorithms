#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cinttypes>

std::set<std::vector<int>> findFours(int sumFour, const std::vector<int>& numbers) {
	std::set<std::vector<int>> fours;
	std::unordered_map<int64_t, std::vector<std::pair<int, int>>> pairs;
	for (int i = 0; i < numbers.size(); i++) {
		for (int j = i + 1; j < numbers.size(); j++) {
			int64_t target = sumFour;
			target = target - numbers.at(i) - numbers.at(j);
			if (pairs.find(target) != pairs.end()) {
				for (const auto& pair : pairs.at(target)) {
					std::vector<int> four = { pair.first, pair.second, numbers.at(i), numbers.at(j) };
					fours.insert(four);
				}
			}
		}
		for (int j = 0; j < i; j++) {
			pairs[numbers.at(i) + numbers.at(j)].push_back(std::make_pair(numbers.at(j), numbers.at(i)));
		}
	}
	return fours;
}


int sumFour() {
	int N, sumFour;
	std::cin >> N >> sumFour;
	std::vector<int> numbers;
	for (int i = 0; i < N; i++) {
		int number;
		std::cin >> number;
		numbers.push_back(number);
	}
	if (numbers.size() != 0) {
		std::sort(numbers.begin(), numbers.end());
		std::set<std::vector<int>> fours = findFours(sumFour, numbers);
		std::cout << fours.size() << std::endl;
		for (const auto& four : fours) {
			std::cout << four.at(0) << " " << four.at(1) << " " << four.at(2) << " " << four.at(3) << std::endl;
		}
	}
	else {
		std::cout << 0;
	}
	return 0;
}