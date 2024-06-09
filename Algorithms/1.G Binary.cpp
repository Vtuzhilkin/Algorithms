#include <iostream>

int binary() {
	int number;
	std::cin >> number;
	std::string binary_number = "";
	if (number != 0) {
		while (number != 0) {
			binary_number += '0' + number % 2;
			number = number / 2;
		}
		for (int i = binary_number.size() - 1; i >= 0; i--) {
			std::cout << binary_number.at(i);
		}
	}
	else {
		std::cout << 0;
	}
	return 0;
}