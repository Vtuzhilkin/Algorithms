#include <iostream>
#include <vector>

int factorization() {

	int number;
	std::cin >> number;
	int divider = 2;
	while (divider*divider <= number) {
		if (number % divider == 0) {
			std::cout << divider << " ";
			number = number / divider;
		}
		else {
			divider++;
		}
	}
	std::cout << number;
	return 0;
}