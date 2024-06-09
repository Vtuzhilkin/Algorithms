#include <iostream>
#include <vector>

int differentTreeSearch() {
	int number;
	std::cin >> number;
	number++;
	std::vector<int> numbers = { 1, 1 };
	while (numbers.size() <= number) {
		int count_trees = 0;
		for (int i = 0; i < numbers.size(); i++) {
			count_trees += numbers.at(i) * numbers.at(numbers.size() - 1 - i);
		}
		numbers.push_back(count_trees);
	}
	std::cout << numbers.at(number - 1);
	return 0;
}