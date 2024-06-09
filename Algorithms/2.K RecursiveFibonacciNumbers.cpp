#include <iostream>
#include <cmath>

uint64_t fibonacci(int number, uint64_t first, uint64_t second) {
	uint64_t number_new = first + second;
	number--;
	if (number == 0) {
		return number_new;
	}
	else {
		fibonacci(number, second, number_new);
	}
}

int recursiveFibonacciNumbers() {
	uint64_t number;
	int k;
	std::cin >> number >> k;
	std::cout << fibonacci(number + 1, 1.0, 0.0);
	return 0;
}