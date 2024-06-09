#include <iostream>
#include <vector>
#include <algorithm>

int calculate(const std::vector<int>& banknotes, const int& capacity_backpack) {
	std::vector<int> backpacks(capacity_backpack + 1, -1);
	for (int capacity = 1; capacity <= capacity_backpack; capacity++) {
		for (const int& banknote : banknotes) {
			if (capacity == banknote) {
				backpacks[capacity] = 1;
				break;
			}
			else if (capacity > banknote && backpacks[capacity - banknote] != -1) {
				if (backpacks[capacity] == -1) {
					backpacks[capacity] = backpacks[capacity - banknote] + 1;
				}
				else {
					backpacks[capacity] = std::min(backpacks[capacity], backpacks[capacity - banknote] + 1);
				}
			}
		}
	}
	return backpacks.back();
}

int buyingHouse() {
	int number_banknotes, capacity_backpack;
	std::cin >> capacity_backpack >> number_banknotes;
	std::vector<int> banknotes;
	for (int i = 0; i < number_banknotes; i++) {
		int banknote;
		std::cin >> banknote;
		banknotes.push_back(banknote);
	}
	std::sort(banknotes.rbegin(), banknotes.rend());
	std::cout << calculate(banknotes, capacity_backpack);
	return 0;
}