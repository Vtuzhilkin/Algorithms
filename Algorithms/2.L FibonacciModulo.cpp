#include <iostream>
#include <cmath>

int fibonacciModulo() {
	int N;
	int k;
	std::cin >> N >> k;
	int number = 1;
	int next_number = 0;
	int fibonacci = 0;
	for (int i = 0; i <= N; i++) {
		fibonacci = (number + next_number) % int(pow(10, k));
		number = next_number;
		next_number = fibonacci;
	}
	if (N != 0) {
		std::cout << fibonacci;
	}
	else {
		std::cout << 1;
	}

	return 0;
}