#include <iostream>
#include <vector>

void bubble_sort(std::vector<int>& massiv) {
	bool output = false;
	for (int i = 0; i < massiv.size() - 1; i++) {
		bool sort = true;
		for (int j = 0; j < massiv.size() - 1 - i; j++) {
			if (massiv[j] > massiv[j + 1]) {
				int number = massiv[j];
				massiv[j] = massiv[j + 1];
				massiv[j + 1] = number;
				sort = false;
			}
		}
		if (sort) {
			if (!output) {
				for (const int& number : massiv) {
					std::cout << number << " ";
				}
			}
			return;
		}
		for (const int& number : massiv) {
			std::cout << number << " ";
			output = true;
		}
		std::cout << std::endl;
	}
}

int bubble() {
	int size;
	std::cin >> size;
	std::vector<int> massiv;
	for (int i = 0; i < size; i++) {
		int number;
		std::cin >> number;
		massiv.push_back(number);
	}
	bubble_sort(massiv);
	return 0;
}