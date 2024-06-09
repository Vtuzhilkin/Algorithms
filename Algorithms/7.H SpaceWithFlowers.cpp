#include <iostream>
#include <vector>

int spaceWithFlowers() {
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
	std::cout << number_flowers[number_rows][number_columns];
	return 0;
}