#include <iostream>
#include <vector>

int monitoring() {
	int number_rows, number_cols;
	std::cin >> number_rows >> number_cols;
	std::vector<std::vector<int>> table(number_cols, std::vector<int>(number_rows));
	for (int i = 0; i < number_rows; i++) {
		for (int j = 0; j < number_cols; j++) {
			int number;
			std::cin >> number;
			table[j][i] = number;
		}
	}
	for (int i = 0; i < number_cols; i++) {
		for (int j = 0; j < number_rows; j++) {
			std::cout << table.at(i).at(j);
			if (j != number_rows - 1) {
				std::cout << " ";
			}
		}
		if (i != number_cols - 1) {
			std::cout << "\n";
		}
	}
	return 0;
}