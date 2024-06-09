#include <iostream>

bool degreeFour(const int& number) {
	int degree_number = 1;
	int degree = 4;
	while (degree_number <= number) {
		if (degree_number == number) {
			return true;
		}
		degree_number = degree_number * degree;
	}
	return false;
}

int degree() {
	int number;
	std::cin >> number;
	if (degreeFour(number)) {
		std::cout << "True";
	}
	else {
		std::cout << "False";
	}
	return 0;
}