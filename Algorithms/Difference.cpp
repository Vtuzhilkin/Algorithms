#include <iostream>
#include <vector>
#include <algorithm>

int mugs() {
	int number_island;
	std::cin >> number_island;
	std::vector<int> square_islandes(number_island, 0);
	for (int i = 0; i < number_island; i++) {
		int square;
		std::cin >> square;
		square_islandes[i] = square;
	}
	std::sort(square_islandes.begin(), square_islandes.end());
	int difference;
	std::cin >> difference;
	int i = 0;
	int size = square_islandes.size();
	while (difference >= size) {
		i++;
		difference %= size;
		size = size - 1;
	}
	std::cout << square_islandes[difference+1] - square_islandes[i];
}