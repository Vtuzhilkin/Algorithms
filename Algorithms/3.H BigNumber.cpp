#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool compare(const std::string& first, const std::string& second) {
	int min_size = std::min(first.size(), second.size());
	for (int i = 0; i < min_size; i++) {
		if (first.at(i) > second.at(i)) return true;
		else if (first.at(i) < second.at(i)) return false;
	}
	return std::stoi(first + second) > stoi(second + first);
}

int bigNumber() {
	int N;
	std::cin >> N;
	std::vector<std::string> numbers;
	std::string number;
	for (int i = 0; i < N; i++) {
		std::cin >> number;
		numbers.push_back(number);
	}
	std::sort(numbers.begin(), numbers.end(), compare);
	for (const std::string& number :numbers) {
		std::cout << number;
	}
	return 0;
}