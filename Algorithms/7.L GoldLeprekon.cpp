#include <iostream>
#include <vector>
#include <algorithm>

int calculate_profit(const std::vector<int>& bars, const int& size_backpack) {
	std::vector<std::vector<int>> dp(bars.size(), std::vector<int>(size_backpack + 1, 0));
	for (int number_bar = 0; number_bar < bars.size(); number_bar++) {
		for (int number_backpack = 0; number_backpack <= size_backpack; number_backpack++) {
			int previous_profit = 0, current_profit = 0;
			if (number_bar > 0) {
				previous_profit = dp[number_bar - 1][number_backpack];
			}
			if (number_backpack >= bars.at(number_bar)) {
				current_profit = bars.at(number_bar);
				if (number_bar > 0) {
					current_profit += dp.at(number_bar - 1).at(number_backpack - bars.at(number_bar));
				}
			}
			dp[number_bar][number_backpack] = std::max(previous_profit, current_profit);
		}
	}
	return dp.back().back();
}

int glodLeprelon() {
	int number_bars, capacity_backpack;
	std::cin >> number_bars >> capacity_backpack;
	std::vector<int> bars;
	for (int i = 0; i < number_bars; i++) {
		int bar;
		std::cin >> bar;
		bars.push_back(bar);
	}
	std::cout << calculate_profit(bars, capacity_backpack);
	return 0;
}