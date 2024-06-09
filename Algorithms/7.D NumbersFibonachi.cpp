#include <iostream>
#include <vector>
#include <cmath>

void fibonachi(int number) {
	std::vector<int> numbers({ 1, 1 });
	int modul = pow(10, 9) + 7;
	while (--number) {
		numbers.push_back((numbers.back() + *(++numbers.rbegin())) % modul);
	}
	std::cout << numbers.back();
}

int numbersFibonachi() {
	int number;
	std::cin >> number;
	fibonachi(number);
	return 0;
}

