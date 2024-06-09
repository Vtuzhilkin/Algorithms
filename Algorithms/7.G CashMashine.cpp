#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int calculate(const std::vector<int>& banknotes, const int& capacity_backpack) {
	std::vector<int> backpacks(capacity_backpack + 1, 0);
	backpacks[0] = 1;
	for (const int& banknote : banknotes) {
		for (int capacity = banknote; capacity <= capacity_backpack; capacity++) {
			backpacks[capacity] += backpacks[capacity - banknote];
		}
	}
	return backpacks.back();
}

int cashMashine() {
	int number_banknotes, capacity_backpack;
	std::cin >> capacity_backpack >> number_banknotes;
	std::vector<int> banknotes;
	for (int i = 0; i < number_banknotes; i++) {
		int banknote;
		std::cin >> banknote;
		banknotes.push_back(banknote);
	}
	std::sort(banknotes.begin(), banknotes.end());
	std::cout << calculate(banknotes, capacity_backpack);
	return 0;
}