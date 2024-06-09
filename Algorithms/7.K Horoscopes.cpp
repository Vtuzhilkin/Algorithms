#include <iostream>
#include <vector>
#include <stack>

std::vector<int> read(int size) {
	std::vector<int> sequance({0});
	for (int i = 0; i < size; i++) {
		int element;
		std::cin >> element;
		sequance.push_back(element);
	}
	return sequance;
}

void write(std::stack<int>& nop) {
	while (!nop.empty()) {
		std::cout << nop.top() << " ";
		nop.pop();
	}
	std::cout << std::endl;
}

void nop(const std::vector<int>& first_sequance, const std::vector<int>& second_sequance) {
	std::vector<std::vector<int>> dp(first_sequance.size(), std::vector<int>(second_sequance.size(), 0));
	for (int i = 1; i < first_sequance.size(); i++) {
		for (int j = 1; j < second_sequance.size(); j++) {
			if (first_sequance.at(i) == second_sequance.at(j)) {
				dp[i][j] = dp.at(i - 1).at(j - 1) + 1;
			}
			else {
				dp[i][j] = std::max(dp.at(i).at(j - 1), dp.at(i - 1).at(j));
			}
		}
	}
	int current_i = first_sequance.size() - 1, current_j = second_sequance.size() - 1;
	int size_nop = dp.back().back();
	std::stack<int> first_nop, second_nop;
	while (size_nop) {
		if (first_sequance.at(current_i) == second_sequance.at(current_j)) {
			size_nop--;
			first_nop.push(current_i);
			second_nop.push(current_j);
			current_i--;
			current_j--;
		}
		else if (dp.at(current_i - 1).at(current_j) >= dp.at(current_i).at(current_j - 1)) {
			current_i--;
		}
		else {
			current_j--;
		}
	}
	std::cout << dp.back().back() << std::endl;
	write(first_nop);
	write(second_nop);
}

int horoscopes() {
	int size_first, size_second;
	std::cin >> size_first;
	std::vector<int> first_sequance = read(size_first);
	std::cin >> size_second;
	std::vector<int> second_sequance = read(size_second);
	std::vector<std::vector<int>> dp;
	nop(first_sequance, second_sequance);
	return 0;
}