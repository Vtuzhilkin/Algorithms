#include <iostream>
#include <vector>
#include <stack>

int hardSpaceWithFlowers() {
	int number_rows, number_columns;
	std::cin >> number_rows >> number_columns;
	std::vector<std::vector<bool>> space(number_rows + 1, std::vector<bool>(number_columns + 1, 0));
	std::vector<std::vector<int>> number_flowers(number_rows + 1, std::vector<int>(number_columns + 1, 0));
	for (int i = 1; i <= number_rows; i++) {
		for (int j = 1; j <= number_columns; j++) {
			char flower;
			std::cin >> flower;
			space[number_rows - i + 1][j] = flower == '1';
		}
	}
	for (int i = 1; i <= number_rows; i++) {
		for (int j = 1; j <= number_columns; j++) {
			number_flowers[i][j] = std::max(number_flowers[i - 1][j], number_flowers[i][j - 1]) + space[i][j];
		}
	}
	std::stack<char> way;
	int position_y = number_rows, position_x = number_columns;
	while (position_x != 1 || position_y != 1) {
		if (position_y == 1 || number_flowers.at(position_y).at(position_x - 1) > number_flowers.at(position_y - 1).at(position_x)) {
			position_x--;
			way.push('R');
		}
		else {
			position_y--;
			way.push('U');
		}
	}
	std::cout << number_flowers[number_rows][number_columns] << std::endl;
	while (!way.empty()) {
		std::cout << way.top();
		way.pop();
	}
	return 0;
}